---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/prime.md
    document_title: "\u7D20\u6570\u7B5B"
    links: []
  bundledCode: "#line 1 \"src/math/prime.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n/*\r\n@brief \u7D20\u6570\u7B5B\r\n@docs docs/prime.md\r\n*/\r\n\r\n\
    namespace Prime {\r\n//\u65F6\u95F4\u590D\u6742\u5EA6O(n)\r\nconst int maxn =\
    \ 1e5 + 5;\r\nbool is[maxn];\r\nint prm[maxn], id;\r\n// \u6BCF\u4E2A\u6570\u7684\
    \u6700\u5C0F\u8D28\u56E0\u5B50\r\nint minp[maxn];\r\nvoid get_prime() {\r\n  \
    \  /*\r\n    \u6570\u88AB\u7B5B\u6389\u7684\u987A\u5E8F\uFF1A3 -> 3^2 -> 2*3^2\
    \ -> 2^2 * 3^2\r\n    \u5373\u4ECE\u6700\u5927\u7684\u8D28\u6570\u53BB\u586B\r\
    \n    */\r\n    int k = 0;\r\n    memset(is, 1, sizeof(is));\r\n    is[0] = is[1]\
    \ = 0;\r\n    for (int i = 2; i < maxn; ++i) {\r\n        if (is[i]) {\r\n   \
    \         prm[k++] = i;\r\n            minp[i] = i;\r\n        }\r\n        for\
    \ (int j = 0; j < k && (i * prm[j] < maxn); ++j) {\r\n            is[i * prm[j]]\
    \ = 0;\r\n            minp[i * prm[j]] = prm[j];\r\n            if (i % prm[j]\
    \ == 0) break;\r\n        }\r\n    }\r\n    id = k;\r\n}\r\n}  // namespace Prime\r\
    \n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u7D20\u6570\
    \u7B5B\r\n@docs docs/prime.md\r\n*/\r\n\r\nnamespace Prime {\r\n//\u65F6\u95F4\
    \u590D\u6742\u5EA6O(n)\r\nconst int maxn = 1e5 + 5;\r\nbool is[maxn];\r\nint prm[maxn],\
    \ id;\r\n// \u6BCF\u4E2A\u6570\u7684\u6700\u5C0F\u8D28\u56E0\u5B50\r\nint minp[maxn];\r\
    \nvoid get_prime() {\r\n    /*\r\n    \u6570\u88AB\u7B5B\u6389\u7684\u987A\u5E8F\
    \uFF1A3 -> 3^2 -> 2*3^2 -> 2^2 * 3^2\r\n    \u5373\u4ECE\u6700\u5927\u7684\u8D28\
    \u6570\u53BB\u586B\r\n    */\r\n    int k = 0;\r\n    memset(is, 1, sizeof(is));\r\
    \n    is[0] = is[1] = 0;\r\n    for (int i = 2; i < maxn; ++i) {\r\n        if\
    \ (is[i]) {\r\n            prm[k++] = i;\r\n            minp[i] = i;\r\n     \
    \   }\r\n        for (int j = 0; j < k && (i * prm[j] < maxn); ++j) {\r\n    \
    \        is[i * prm[j]] = 0;\r\n            minp[i * prm[j]] = prm[j];\r\n   \
    \         if (i % prm[j] == 0) break;\r\n        }\r\n    }\r\n    id = k;\r\n\
    }\r\n}  // namespace Prime\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime.h
layout: document
redirect_from:
- /library/src/math/prime.h
- /library/src/math/prime.h.html
title: "\u7D20\u6570\u7B5B"
---
