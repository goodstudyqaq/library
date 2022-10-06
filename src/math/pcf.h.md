---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/pcf.md
    document_title: "PCF(\u7D20\u6570\u7B5B)"
    links: []
  bundledCode: "#line 1 \"src/math/pcf.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n/*\r\n@brief PCF(\u7D20\u6570\u7B5B)\r\n@docs docs/pcf.md\r\n*/\r\
    \n\r\nnamespace pcf {\r\n// \u6C42 [1, n] \u7D20\u6570\u4E2A\u6570\r\n#define\
    \ setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))\r\n#define chkbit(ar,\
    \ i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))\r\n#define isprime(x) (((x)\
    \ && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))\r\n\r\nconst int maxn = 100;\
    \      // pre-calc max n for phi(m, n)\r\nconst int maxm = 100010;   // pre-calc\
    \ max m for phi(m, n)\r\nconst int maxp = 666666;   // max primes counter\r\n\
    const int max = 10000010;  // max prime\r\n\r\nlong long dp[maxn][maxm];\r\nunsigned\
    \ int ar[(max >> 6) + 5] = {0};\r\nint len = 0, primes[maxp], counter[max];\r\n\
    \r\nvoid sieve() {\r\n    setbit(ar, 0), setbit(ar, 1);\r\n    for (int i = 3;\
    \ (i * i) < max; i++, i++) {\r\n        if (!chkbit(ar, i)) {\r\n            int\
    \ k = i << 1;\r\n            for (int j = (i * i); j < max; j += k) setbit(ar,\
    \ j);\r\n        }\r\n    }\r\n\r\n    for (int i = 1; i < max; i++) {\r\n   \
    \     counter[i] = counter[i - 1];\r\n        if (isprime(i)) primes[len++] =\
    \ i, counter[i]++;\r\n    }\r\n}\r\n\r\nvoid init() {\r\n    sieve();\r\n    for\
    \ (int n = 0; n < maxn; n++) {\r\n        for (int m = 0; m < maxm; m++) {\r\n\
    \            if (!n)\r\n                dp[n][m] = m;\r\n            else\r\n\
    \                dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];\r\n \
    \       }\r\n    }\r\n}\r\n\r\nlong long phi(long long m, int n) {\r\n    if (n\
    \ == 0) return m;\r\n    if (primes[n - 1] >= m) return 1;\r\n    if (m < maxm\
    \ && n < maxn) return dp[n][m];\r\n    return phi(m, n - 1) - phi(m / primes[n\
    \ - 1], n - 1);\r\n}\r\n\r\nlong long lehmer(long long m) {\r\n    if (m < max)\
    \ return counter[m];\r\n\r\n    long long w, res = 0;\r\n    int i, a, s, c, x,\
    \ y;\r\n    s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);\r\n    a = counter[y], res\
    \ = phi(m, a) + a - 1;\r\n    for (i = a; primes[i] <= s; i++) res = res - lehmer(m\
    \ / primes[i]) + lehmer(primes[i]) - 1;\r\n    return res;\r\n}\r\nlong long solve(long\
    \ long n) {\r\n    // \u8FD4\u56DE [1, n] \u8D28\u6570\u4E2A\u6570\r\n    int\
    \ i, j, k, l;\r\n    long long x, y, res = 0;\r\n\r\n    for (i = 0; i < pcf::len;\
    \ i++) {\r\n        x = pcf::primes[i], y = n / x;\r\n        if ((x * x) > n)\
    \ break;\r\n        res += (pcf::lehmer(y) - pcf::lehmer(x));\r\n    }\r\n\r\n\
    \    for (i = 0; i < pcf::len; i++) {\r\n        x = pcf::primes[i];\r\n     \
    \   if ((x * x * x) > n) break;\r\n        res++;\r\n    }\r\n\r\n    return res;\r\
    \n}\r\n}  // namespace pcf\r\n\r\n// pcf::init();\r\n// pcf::solve(n);\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief PCF(\u7D20\
    \u6570\u7B5B)\r\n@docs docs/pcf.md\r\n*/\r\n\r\nnamespace pcf {\r\n// \u6C42 [1,\
    \ n] \u7D20\u6570\u4E2A\u6570\r\n#define setbit(ar, i) (((ar[(i) >> 6]) |= (1\
    \ << (((i) >> 1) & 31))))\r\n#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i)\
    \ >> 1) & 31))))\r\n#define isprime(x) (((x) && ((x)&1) && (!chkbit(ar, (x))))\
    \ || ((x) == 2))\r\n\r\nconst int maxn = 100;      // pre-calc max n for phi(m,\
    \ n)\r\nconst int maxm = 100010;   // pre-calc max m for phi(m, n)\r\nconst int\
    \ maxp = 666666;   // max primes counter\r\nconst int max = 10000010;  // max\
    \ prime\r\n\r\nlong long dp[maxn][maxm];\r\nunsigned int ar[(max >> 6) + 5] =\
    \ {0};\r\nint len = 0, primes[maxp], counter[max];\r\n\r\nvoid sieve() {\r\n \
    \   setbit(ar, 0), setbit(ar, 1);\r\n    for (int i = 3; (i * i) < max; i++, i++)\
    \ {\r\n        if (!chkbit(ar, i)) {\r\n            int k = i << 1;\r\n      \
    \      for (int j = (i * i); j < max; j += k) setbit(ar, j);\r\n        }\r\n\
    \    }\r\n\r\n    for (int i = 1; i < max; i++) {\r\n        counter[i] = counter[i\
    \ - 1];\r\n        if (isprime(i)) primes[len++] = i, counter[i]++;\r\n    }\r\
    \n}\r\n\r\nvoid init() {\r\n    sieve();\r\n    for (int n = 0; n < maxn; n++)\
    \ {\r\n        for (int m = 0; m < maxm; m++) {\r\n            if (!n)\r\n   \
    \             dp[n][m] = m;\r\n            else\r\n                dp[n][m] =\
    \ dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];\r\n        }\r\n    }\r\n}\r\n\r\
    \nlong long phi(long long m, int n) {\r\n    if (n == 0) return m;\r\n    if (primes[n\
    \ - 1] >= m) return 1;\r\n    if (m < maxm && n < maxn) return dp[n][m];\r\n \
    \   return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);\r\n}\r\n\r\nlong long\
    \ lehmer(long long m) {\r\n    if (m < max) return counter[m];\r\n\r\n    long\
    \ long w, res = 0;\r\n    int i, a, s, c, x, y;\r\n    s = sqrt(0.9 + m), y =\
    \ c = cbrt(0.9 + m);\r\n    a = counter[y], res = phi(m, a) + a - 1;\r\n    for\
    \ (i = a; primes[i] <= s; i++) res = res - lehmer(m / primes[i]) + lehmer(primes[i])\
    \ - 1;\r\n    return res;\r\n}\r\nlong long solve(long long n) {\r\n    // \u8FD4\
    \u56DE [1, n] \u8D28\u6570\u4E2A\u6570\r\n    int i, j, k, l;\r\n    long long\
    \ x, y, res = 0;\r\n\r\n    for (i = 0; i < pcf::len; i++) {\r\n        x = pcf::primes[i],\
    \ y = n / x;\r\n        if ((x * x) > n) break;\r\n        res += (pcf::lehmer(y)\
    \ - pcf::lehmer(x));\r\n    }\r\n\r\n    for (i = 0; i < pcf::len; i++) {\r\n\
    \        x = pcf::primes[i];\r\n        if ((x * x * x) > n) break;\r\n      \
    \  res++;\r\n    }\r\n\r\n    return res;\r\n}\r\n}  // namespace pcf\r\n\r\n\
    // pcf::init();\r\n// pcf::solve(n);\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/pcf.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/pcf.h
layout: document
redirect_from:
- /library/src/math/pcf.h
- /library/src/math/pcf.h.html
title: "PCF(\u7D20\u6570\u7B5B)"
---
