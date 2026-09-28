const Inject=(..._a:any[])=>(..._b:any[])=>{};const Injectable=()=>(..._b:any[])=>{};class NotFoundException extends Error{};
type Pool=any;
const PG_POOL='PG_POOL';

export interface SimilarityStudent {
  userId: string;
  fullName: string;
  studentCode: string | null;
  hasCode: boolean;
  loc: number;
}

export interface SimilarityDimensions {
  /** ความคล้ายของข้อความโค้ด (Levenshtein ratio หลัง normalize). */
  text: number;
  /** ความคล้ายเชิงโครงสร้าง — Jaccard ของ token-shingle (ไม่สนชื่อตัวแปร). */
  token: number;
  /** ลายนิ้วมือ k-gram — Jaccard ของ fingerprint (จับการคัดลอกบางส่วน). */
  fingerprint: number;
  /** Jaccard ของเซตบรรทัด (จับบล็อกที่คัดลอกแม้สลับตำแหน่ง). */
  lineset: number;
}

export interface SimilarityPair {
  aUserId: string;
  aName: string;
  aStudentCode: string | null;
  bUserId: string;
  bName: string;
  bStudentCode: string | null;
  dimensions: SimilarityDimensions;
  /** คะแนนรวม (0–100). */
  overall: number;
}

export interface SimilaritySummary {
  userId: string;
  fullName: string;
  studentCode: string | null;
  mostSimilarUserId: string | null;
  mostSimilarName: string | null;
  mostSimilarOverall: number | null;
}

export interface SimilarityResult {
  assignment: { id: string; title: string };
  students: SimilarityStudent[];
  pairs: SimilarityPair[];
  summary: SimilaritySummary[];
  /** จำนวนนิสิตที่มีโค้ดให้เทียบ. */
  withCode: number;
}

/** อินพุตของการเทียบไฟล์ที่อัปโหลดเอง. */
export interface UploadedFileInput {
  name: string;
  content: string;
}

export interface FileSimItem {
  index: number;
  name: string;
  hasCode: boolean;
  loc: number;
}

export interface FileSimPair {
  aIndex: number;
  aName: string;
  bIndex: number;
  bName: string;
  dimensions: SimilarityDimensions;
  overall: number;
}

export interface FileSimSummary {
  index: number;
  name: string;
  mostSimilarName: string | null;
  mostSimilarOverall: number | null;
}

export interface FileSimilarityResult {
  files: FileSimItem[];
  pairs: FileSimPair[];
  summary: FileSimSummary[];
  /** จำนวนไฟล์ที่มีเนื้อหาให้เทียบ. */
  withCode: number;
}

/** ขีดจำกัดการอัปโหลด — กันใช้ทรัพยากรเกิน. */
export const FILE_SIM_LIMITS = {
  maxFiles: 60,
  maxCharsPerFile: 300_000,
  maxTotalChars: 3_000_000,
};

interface CodeRow {
  user_id: string;
  full_name: string;
  student_code: string | null;
  snap_code: string | null;
  files_code: string | null;
  draft_code: string | null;
}

/**
 * ตรวจความคล้ายของโค้ดในโจทย์เดียว (instructor/admin) — เทียบทุกคู่ของนิสิต
 * แบบหลายมิติ แล้วสรุปเปอร์เซ็นต์และว่าคล้ายใครมากที่สุด. เป็นแบบ rule-based
 * ในระบบ (ไม่พึ่งบริการภายนอก).
 */
@Injectable()
export class SimilarityService {
  constructor(@Inject(PG_POOL) private readonly pool: Pool) {}

  /**
   * โค้ดจริงของนิสิตสองคนสำหรับดูเทียบ side-by-side — ใช้แหล่งโค้ดชุดเดียวกับที่
   * อัลกอริทึมเทียบ (snapshot → project_files → draft). แนบภาษา (จาก draft ถ้ามี).
   */
  async pairCode(
    assignmentId: string,
    aUserId: string,
    bUserId: string,
  ): Promise<{
    a: { userId: string; fullName: string; studentCode: string | null; language: string; code: string };
    b: { userId: string; fullName: string; studentCode: string | null; language: string; code: string };
  }> {
    const { rows } = await this.pool.query<
      CodeRow & { language: string | null }
    >(
      `SELECT u.id AS user_id, u.full_name, u.student_code,
              (SELECT string_agg(sf.content, E'\n' ORDER BY sf.path)
                 FROM snapshot_files sf
                WHERE sf.snapshot_id = sub.current_snapshot_id) AS snap_code,
              (SELECT string_agg(pf.content, E'\n' ORDER BY pf.filename)
                 FROM project_files pf
                WHERE pf.psp_project_id = sub.psp_project_id) AS files_code,
              (SELECT d.content FROM project_drafts d
                WHERE d.psp_project_id = sub.psp_project_id) AS draft_code,
              (SELECT d.language FROM project_drafts d
                WHERE d.psp_project_id = sub.psp_project_id) AS language
         FROM users u
         LEFT JOIN submissions sub
                ON sub.user_id = u.id
               AND sub.assignment_id = $1
               AND sub.deleted_at IS NULL
        WHERE u.id = ANY($2::uuid[]) AND u.deleted_at IS NULL`,
      [assignmentId, [aUserId, bUserId]],
    );
    const mk = (uid: string) => {
      const r = rows.find((x) => x.user_id === uid);
      const code = r
        ? (this.firstNonEmpty(r.snap_code, r.files_code, r.draft_code) ?? '')
        : '';
      return {
        userId: uid,
        fullName: r?.full_name ?? '',
        studentCode: r?.student_code ?? null,
        language: r?.language ?? 'text',
        code,
      };
    };
    return { a: mk(aUserId), b: mk(bUserId) };
  }

  async analyzeAssignment(assignmentId: string): Promise<SimilarityResult> {
    const a = await this.pool.query<{ id: string; title: string; course_id: string }>(
      `SELECT id, title, course_id FROM assignments
        WHERE id = $1 AND deleted_at IS NULL`,
      [assignmentId],
    );
    const arow = a.rows[0];
    if (!arow) throw new NotFoundException(`Assignment ${assignmentId} not found`);

    const { rows } = await this.pool.query<CodeRow>(
      `SELECT u.id AS user_id, u.full_name, u.student_code,
              (SELECT string_agg(sf.content, E'\n' ORDER BY sf.path)
                 FROM snapshot_files sf
                WHERE sf.snapshot_id = sub.current_snapshot_id) AS snap_code,
              (SELECT string_agg(pf.content, E'\n' ORDER BY pf.filename)
                 FROM project_files pf
                WHERE pf.psp_project_id = sub.psp_project_id) AS files_code,
              (SELECT d.content FROM project_drafts d
                WHERE d.psp_project_id = sub.psp_project_id) AS draft_code
         FROM enrollments e
         JOIN sections s ON s.id = e.section_id
         JOIN users u    ON u.id = e.user_id
         LEFT JOIN submissions sub
                ON sub.user_id = u.id
               AND sub.assignment_id = $1
               AND sub.deleted_at IS NULL
        WHERE s.course_id = $2
          AND e.role = 'student'
          AND e.status = 'active'
          AND e.deleted_at IS NULL
          AND u.deleted_at IS NULL
        ORDER BY u.student_code NULLS LAST, u.full_name`,
      [assignmentId, arow.course_id],
    );

    // เตรียมโค้ด + ลายเซ็นของแต่ละนิสิต
    interface Prepared {
      userId: string;
      fullName: string;
      studentCode: string | null;
      raw: string;
      normText: string;
      tokenShingles: Set<string>;
      kgrams: Set<string>;
      lines: Set<string>;
      loc: number;
    }
    const prepared: Prepared[] = [];
    const students: SimilarityStudent[] = [];

    for (const r of rows) {
      const code =
        this.firstNonEmpty(r.snap_code, r.files_code, r.draft_code) ?? '';
      const has = code.trim().length > 0;
      const loc = has ? code.split('\n').filter((l) => l.trim().length > 0).length : 0;
      students.push({
        userId: r.user_id,
        fullName: r.full_name,
        studentCode: r.student_code,
        hasCode: has,
        loc,
      });
      if (!has) continue;
      const normText = this.normalizeText(code);
      prepared.push({
        userId: r.user_id,
        fullName: r.full_name,
        studentCode: r.student_code,
        raw: code,
        normText,
        tokenShingles: this.tokenShingles(code),
        kgrams: this.kgrams(normText),
        lines: this.lineSet(code),
        loc,
      });
    }

    // เทียบทุกคู่
    const pairs: SimilarityPair[] = [];
    const bestFor = new Map<
      string,
      { userId: string; name: string; overall: number }
    >();

    for (let x = 0; x < prepared.length; x++) {
      for (let y = x + 1; y < prepared.length; y++) {
        const A = prepared[x];
        const B = prepared[y];
        const token = this.jaccard(A.tokenShingles, B.tokenShingles);
        const fingerprint = this.jaccard(A.kgrams, B.kgrams);
        const lineset = this.jaccard(A.lines, B.lines);
        const text = this.textSim(A.normText, B.normText);
        const overall = Math.round(
          (token * 0.35 + fingerprint * 0.3 + lineset * 0.2 + text * 0.15) * 100,
        );
        const dimensions: SimilarityDimensions = {
          text: Math.round(text * 100),
          token: Math.round(token * 100),
          fingerprint: Math.round(fingerprint * 100),
          lineset: Math.round(lineset * 100),
        };
        pairs.push({
          aUserId: A.userId,
          aName: A.fullName,
          aStudentCode: A.studentCode,
          bUserId: B.userId,
          bName: B.fullName,
          bStudentCode: B.studentCode,
          dimensions,
          overall,
        });
        this.considerBest(bestFor, A.userId, B.userId, B.fullName, overall);
        this.considerBest(bestFor, B.userId, A.userId, A.fullName, overall);
      }
    }

    pairs.sort((p, q) => q.overall - p.overall);

    const summary: SimilaritySummary[] = students.map((s) => {
      const best = bestFor.get(s.userId) ?? null;
      return {
        userId: s.userId,
        fullName: s.fullName,
        studentCode: s.studentCode,
        mostSimilarUserId: best?.userId ?? null,
        mostSimilarName: best?.name ?? null,
        mostSimilarOverall: best ? best.overall : null,
      };
    });

    return {
      assignment: { id: arow.id, title: arow.title },
      students,
      pairs,
      summary,
      withCode: prepared.length,
    };
  }

  /**
   * เทียบความคล้ายระหว่างไฟล์ที่อัปโหลดเอง (instructor/admin) — เทียบทุกคู่
   * แบบหลายมิติเช่นเดียวกับการตรวจในโจทย์ แต่แหล่งโค้ดมาจากไฟล์ที่อัปโหลด.
   */
  analyzeFiles(inputs: UploadedFileInput[]): FileSimilarityResult {
    interface Prepared {
      index: number;
      name: string;
      normText: string;
      tokenShingles: Set<string>;
      kgrams: Set<string>;
      lines: Set<string>;
    }
    const prepared: Prepared[] = [];
    const files: FileSimItem[] = [];

    inputs.forEach((f, i) => {
      const code = f.content ?? '';
      const has = code.trim().length > 0;
      const loc = has
        ? code.split('\n').filter((l) => l.trim().length > 0).length
        : 0;
      const name = (f.name ?? '').trim() || `ไฟล์ ${i + 1}`;
      files.push({ index: i, name, hasCode: has, loc });
      if (!has) return;
      const normText = this.normalizeText(code);
      prepared.push({
        index: i,
        name,
        normText,
        tokenShingles: this.tokenShingles(code),
        kgrams: this.kgrams(normText),
        lines: this.lineSet(code),
      });
    });

    const pairs: FileSimPair[] = [];
    const bestFor = new Map<
      number,
      { index: number; name: string; overall: number }
    >();

    for (let x = 0; x < prepared.length; x++) {
      for (let y = x + 1; y < prepared.length; y++) {
        const A = prepared[x];
        const B = prepared[y];
        const token = this.jaccard(A.tokenShingles, B.tokenShingles);
        const fingerprint = this.jaccard(A.kgrams, B.kgrams);
        const lineset = this.jaccard(A.lines, B.lines);
        const text = this.textSim(A.normText, B.normText);
        const overall = Math.round(
          (token * 0.35 + fingerprint * 0.3 + lineset * 0.2 + text * 0.15) * 100,
        );
        pairs.push({
          aIndex: A.index,
          aName: A.name,
          bIndex: B.index,
          bName: B.name,
          dimensions: {
            text: Math.round(text * 100),
            token: Math.round(token * 100),
            fingerprint: Math.round(fingerprint * 100),
            lineset: Math.round(lineset * 100),
          },
          overall,
        });
        this.considerBestFile(bestFor, A.index, B.index, B.name, overall);
        this.considerBestFile(bestFor, B.index, A.index, A.name, overall);
      }
    }

    pairs.sort((p, q) => q.overall - p.overall);

    const summary: FileSimSummary[] = files.map((f) => {
      const best = bestFor.get(f.index) ?? null;
      return {
        index: f.index,
        name: f.name,
        mostSimilarName: best?.name ?? null,
        mostSimilarOverall: best ? best.overall : null,
      };
    });

    return { files, pairs, summary, withCode: prepared.length };
  }

  private considerBestFile(
    map: Map<number, { index: number; name: string; overall: number }>,
    self: number,
    otherIndex: number,
    otherName: string,
    overall: number,
  ): void {
    const cur = map.get(self);
    if (!cur || overall > cur.overall) {
      map.set(self, { index: otherIndex, name: otherName, overall });
    }
  }

  private considerBest(
    map: Map<string, { userId: string; name: string; overall: number }>,
    self: string,
    otherId: string,
    otherName: string,
    overall: number,
  ): void {
    const cur = map.get(self);
    if (!cur || overall > cur.overall) {
      map.set(self, { userId: otherId, name: otherName, overall });
    }
  }

  private firstNonEmpty(...vals: Array<string | null>): string | null {
    for (const v of vals) {
      if (v && v.trim().length > 0) return v;
    }
    return null;
  }

  /** ลบคอมเมนต์ + สตริง + ยุบช่องว่าง แล้วเป็นตัวพิมพ์เล็ก. */
  private normalizeText(code: string): string {
    let s = code;
    // block comments /* */
    s = s.replace(/\/\*[\s\S]*?\*\//g, ' ');
    // line comments // and #
    s = s.replace(/(^|\s)\/\/[^\n]*/g, ' ');
    s = s.replace(/(^|\s)#[^\n]*/g, ' ');
    // strings
    s = s.replace(/"(?:[^"\\]|\\.)*"/g, '""');
    s = s.replace(/'(?:[^'\\]|\\.)*'/g, "''");
    // whitespace
    s = s.replace(/\s+/g, ' ').trim().toLowerCase();
    return s;
  }

  /** โทเคนโดยรวมชื่อ/ตัวเลขเป็นสัญลักษณ์กลาง เพื่อจับโครงสร้างไม่สนชื่อ. */
  private tokenize(code: string): string[] {
    const norm = this.normalizeText(code);
    const out: string[] = [];
    const re = /[a-z_][a-z0-9_]*|\d+|[^\sa-z0-9_]/g;
    let m: RegExpExecArray | null;
    while ((m = re.exec(norm)) !== null) {
      const t = m[0];
      if (/^\d+$/.test(t)) out.push('N');
      else if (/^[a-z_][a-z0-9_]*$/.test(t)) {
        out.push(KEYWORDS.has(t) ? t : 'V');
      } else out.push(t);
    }
    return out;
  }

  /** เซตของ 3-token shingle. */
  private tokenShingles(code: string): Set<string> {
    const toks = this.tokenize(code);
    const set = new Set<string>();
    for (let i = 0; i + 3 <= toks.length; i++) {
      set.add(toks[i] + '|' + toks[i + 1] + '|' + toks[i + 2]);
    }
    if (set.size === 0 && toks.length > 0) set.add(toks.join('|'));
    return set;
  }

  /** เซตของ k-gram (k=5) บนสตริง normalize แล้ว. */
  private kgrams(norm: string, k = 5): Set<string> {
    const s = norm.replace(/\s+/g, '');
    const set = new Set<string>();
    for (let i = 0; i + k <= s.length; i++) set.add(s.slice(i, i + k));
    if (set.size === 0 && s.length > 0) set.add(s);
    return set;
  }

  /** เซตของบรรทัด (trim, lowercase, ยุบช่องว่างภายใน) ที่ไม่ว่าง. */
  private lineSet(code: string): Set<string> {
    const set = new Set<string>();
    for (const raw of code.split('\n')) {
      const l = raw.replace(/\s+/g, ' ').trim().toLowerCase();
      if (l.length > 0) set.add(l);
    }
    return set;
  }

  private jaccard(a: Set<string>, b: Set<string>): number {
    if (a.size === 0 && b.size === 0) return 0;
    let inter = 0;
    const [small, big] = a.size < b.size ? [a, b] : [b, a];
    for (const v of small) if (big.has(v)) inter++;
    const union = a.size + b.size - inter;
    return union === 0 ? 0 : inter / union;
  }

  /** Levenshtein ratio; ถ้าโค้ดยาวมากใช้ lineset แทนเพื่อเลี่ยง O(n·m). */
  private textSim(a: string, b: string): number {
    const cap = 2500;
    if (a.length > cap || b.length > cap) {
      return this.jaccard(this.charShingle(a), this.charShingle(b));
    }
    const dist = this.levenshtein(a, b);
    const maxLen = Math.max(a.length, b.length);
    return maxLen === 0 ? 0 : 1 - dist / maxLen;
  }

  private charShingle(s: string, k = 8): Set<string> {
    const set = new Set<string>();
    for (let i = 0; i + k <= s.length; i++) set.add(s.slice(i, i + k));
    if (set.size === 0 && s.length > 0) set.add(s);
    return set;
  }

  private levenshtein(a: string, b: string): number {
    const m = a.length;
    const n = b.length;
    if (m === 0) return n;
    if (n === 0) return m;
    let prev = new Array<number>(n + 1);
    let cur = new Array<number>(n + 1);
    for (let j = 0; j <= n; j++) prev[j] = j;
    for (let i = 1; i <= m; i++) {
      cur[0] = i;
      const ca = a.charCodeAt(i - 1);
      for (let j = 1; j <= n; j++) {
        const cost = ca === b.charCodeAt(j - 1) ? 0 : 1;
        cur[j] = Math.min(prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + cost);
      }
      [prev, cur] = [cur, prev];
    }
    return prev[n];
  }
}

/** คีย์เวิร์ดที่เก็บไว้ตอน tokenize (ตัวอื่นถือเป็นตัวแปร/ชื่อ = 'V'). */
const KEYWORDS = new Set<string>([
  // shared / control flow
  'if', 'else', 'elif', 'for', 'while', 'do', 'switch', 'case', 'break',
  'continue', 'default', 'return', 'try', 'catch', 'except', 'finally',
  'throw', 'raise', 'def', 'class', 'function', 'void', 'int', 'long',
  'double', 'float', 'char', 'bool', 'boolean', 'string', 'str', 'new',
  'const', 'let', 'var', 'static', 'public', 'private', 'protected', 'import',
  'from', 'as', 'in', 'is', 'and', 'or', 'not', 'true', 'false', 'null',
  'none', 'print', 'println', 'printf', 'cout', 'cin', 'scanf', 'input',
  'range', 'len', 'this', 'self', 'lambda', 'with', 'struct', 'auto',
  'include', 'using', 'namespace', 'std', 'main', 'system',
]);
