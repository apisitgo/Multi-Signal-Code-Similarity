"""Run a solution file against its unit's test cases using SPII's 'collapse_ws,must'
semantics: whitespace inside lines is collapsed and every <must>...</must> segment of
the expected output must appear, in order, in the program output."""
import json, os, re, subprocess, sys, tempfile, shutil

UNITS = {u['uid']: u for u in json.load(open(os.path.join(os.path.dirname(__file__), 'units.json')))}


def norm(s):
    s = s.replace('\r\n', '\n')
    lines = [re.sub(r'[ \t]+', ' ', l).strip() for l in s.split('\n')]
    return '\n'.join(l for l in lines if l)


def must_segments(expected):
    segs = re.findall(r'<must>(.*?)</must>', expected, re.S)
    return [norm(x) for x in segs] if segs else [norm(expected)]


def check(output, expected):
    out = norm(output); pos = 0
    for seg in must_segments(expected):
        # match segment line-by-line in order (tolerates extra prompt text between lines)
        for line in seg.split('\n'):
            i = out.find(line, pos)
            if i < 0:
                return False
            pos = i + len(line)
    return True


def build(path, lang, work):
    if lang == 'python':
        return ['python3', path], None
    exe = os.path.join(work, 'a.out')
    r = subprocess.run(['gcc', '-O0', '-std=c11', '-w', path, '-o', exe, '-lm'], capture_output=True, text=True)
    if r.returncode != 0:
        return None, r.stderr[:500]
    return [exe], None


def run_tests(path, uid, lang=None):
    u = UNITS[uid]; lang = lang or u['lang']
    work = tempfile.mkdtemp()
    try:
        cmd, err = build(path, lang, work)
        if cmd is None:
            return dict(ok=False, passed=0, total=len(u['tests']), error='compile: ' + err)
        passed = 0; fails = []
        for t in u['tests']:
            try:
                r = subprocess.run(cmd, input=t['input'], capture_output=True, text=True, timeout=5)
                if check(r.stdout, t['expected']):
                    passed += 1
                else:
                    fails.append(dict(input=t['input'][:200], got=r.stdout[-300:], stderr=r.stderr[-200:]))
            except subprocess.TimeoutExpired:
                fails.append(dict(input=t['input'][:200], got='TIMEOUT'))
        return dict(ok=passed == len(u['tests']), passed=passed, total=len(u['tests']), fails=fails[:2])
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == '__main__':
    # usage: harness.py <uid> <file>   -> prints JSON result
    print(json.dumps(run_tests(sys.argv[2], sys.argv[1]), ensure_ascii=False))
