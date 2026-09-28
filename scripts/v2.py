"""SPII-v2: corrected, language-aware re-implementation of the SPII multi-signal
similarity engine. Same four signals and hand weights as SPII-v1, with:
  * a scanning lexer (comments / strings handled per language, so Python `//`
    floor division and C `#include` are no longer mangled),
  * line-set computed on comment-free normalised lines,
  * winnowed character k-gram fingerprints (Schleimer et al. 2003),
  * edit-distance ratio for every pair (no length cap / metric switch).
"""
import re, hashlib
from rapidfuzz.distance import Levenshtein

KW = {
 'java': set('abstract assert boolean break byte case catch char class const continue default do double else enum extends final finally float for goto if implements import instanceof int interface long native new package private protected public return short static strictfp super switch synchronized this throw throws transient try void volatile while true false null var record yield'.split()),
 'c': set('auto break case char const continue default do double else enum extern float for goto if inline int long register restrict return short signed sizeof static struct switch typedef union unsigned void volatile while bool true false nullptr class public private protected new delete namespace using template typename include define'.split()),
 'python': set('False None True and as assert async await break class continue def del elif else except finally for from global if import in is lambda nonlocal not or pass raise return try while with yield'.split()),
}

TOKEN_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*|\d+(?:\.\d+)?|==|!=|<=|>=|&&|\|\||\+\+|--|\+=|-=|\*=|/=|//|->|::|\S")


def strip_comments_strings(code, lang):
    """Return code with comments removed and string/char literals replaced by a
    placeholder. Operates by a single left-to-right scan (not regex) so that
    comment markers inside strings, and `//` as Python floor division, are
    handled correctly."""
    out = []; i = 0; n = len(code)
    cstyle = lang in ('java', 'c')
    while i < n:
        ch = code[i]
        if cstyle and code.startswith('//', i):
            j = code.find('\n', i); i = n if j < 0 else j; continue
        if cstyle and code.startswith('/*', i):
            j = code.find('*/', i + 2); i = n if j < 0 else j + 2; out.append(' '); continue
        if lang == 'python' and ch == '#':
            j = code.find('\n', i); i = n if j < 0 else j; continue
        if lang == 'python' and (code.startswith('"""', i) or code.startswith("'''", i)):
            q = code[i:i + 3]; j = code.find(q, i + 3); i = n if j < 0 else j + 3; out.append('"S"'); continue
        if ch in ('"', "'"):
            j = i + 1
            while j < n and code[j] != ch and code[j] != '\n':
                j += 2 if code[j] == '\\' else 1
            i = j + 1; out.append('"S"'); continue
        if lang == 'c' and ch == '#' :  # preprocessor line kept as code
            pass
        out.append(ch); i += 1
    return ''.join(out)


class Doc:
    def __init__(self, code, lang='java', k=5, w=4, base=None):
        """base: optional Doc of instructor starter code; its lines, token trigrams and
        fingerprints are subtracted (starter-code subtraction)."""
        clean = strip_comments_strings(code, lang)
        if base is not None:
            clean = '\n'.join(l for l in clean.split('\n') if re.sub(r'\s+', ' ', l).strip().lower() not in base.lines)
        self.lines = {re.sub(r'\s+', ' ', l).strip().lower() for l in clean.split('\n')}
        self.lines.discard('')
        self.norm = re.sub(r'\s+', ' ', clean).strip().lower()
        kw = KW[lang]
        toks = []
        for t in TOKEN_RE.findall(clean):
            if t[0].isalpha() or t[0] == '_':
                toks.append(t if t in kw else 'V')
            elif t[0].isdigit():
                toks.append('N')
            else:
                toks.append(t)
        self.toks = toks
        self.tok3 = {'|'.join(toks[i:i + 3]) for i in range(len(toks) - 2)} or ({'|'.join(toks)} if toks else set())
        self.fp = winnow(self.norm.replace(' ', ''), k, w)
        if base is not None:
            self.tok3 -= base.tok3; self.fp -= base.fp


def winnow(s, k, w):
    if len(s) < k:
        return {s} if s else set()
    hs = [int(hashlib.md5(s[i:i + k].encode()).hexdigest()[:12], 16) for i in range(len(s) - k + 1)]
    if len(hs) <= w:
        return {min(hs)}
    fps = set(); prev = None
    for i in range(len(hs) - w + 1):
        win = hs[i:i + w]; m = min(win); pos = i + max(j for j, v in enumerate(win) if v == m)
        if pos != prev:
            fps.add(m); prev = pos
    return fps


def jac(a, b):
    if not a and not b:
        return 0.0
    u = len(a | b)
    return len(a & b) / u if u else 0.0


def signals(A, B):
    return {
        'token': jac(A.tok3, B.tok3),
        'fingerprint': jac(A.fp, B.fp),
        'lineset': jac(A.lines, B.lines),
        'text': Levenshtein.normalized_similarity(A.norm, B.norm),
    }

W_HAND = {'token': 0.35, 'fingerprint': 0.30, 'lineset': 0.20, 'text': 0.15}


def hand(sig):
    return sum(W_HAND[k] * sig[k] for k in W_HAND)
