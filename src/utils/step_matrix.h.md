---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/step_matrix.md
    document_title: Step matrix
    links:
    - https://atcoder.jp/contests/abc249/tasks/abc249_g
  bundledCode: "#line 1 \"src/utils/step_matrix.h\"\n#include <bits/stdc++.h>\r\n\
    using namespace std;\r\n/*\r\n@brief Step matrix\r\n@docs docs/step_matrix.md\r\
    \n*/\r\n\r\n/*\r\nhttps://atcoder.jp/contests/abc249/tasks/abc249_g\r\n\u5C06\
    \ v \u6570\u7EC4\u7684 01 \u77E9\u9635\u53D8\u4E3A step matrix, step matrix: \u4E3A\
    \u5BF9\u4E8E\u6BCF\u4E00\u884C\u7B2C\u4E00\u4E2A\u975E 0 \u5217\u662F\u5355\u8C03\
    \u9012\u589E\u7684\r\n\u8F6C\u6362\u5B8C\u4E4B\u540E\u53EF\u4EE5 On \u6C42\u51FA\
    \u4EFB\u610F\u9009\u6570\uFF0C\u4F7F\u5F97\u5F02\u6216\u548C\u6700\u5927\r\n*/\r\
    \nvector<long long> convert(vector<long long> v, int bit) {\r\n    int rk = 0;\r\
    \n    int n = v.size();\r\n    vector<long long> res(n);\r\n    for (int i = bit\
    \ - 1; i >= 0; i--) {\r\n        int go = rk;\r\n        while (go < n && ((v[go]\
    \ >> i) & 1) == 0) {\r\n            go++;\r\n        }\r\n        if (go == n)\
    \ continue;\r\n        res[rk] = v[go];\r\n        swap(v[rk], v[go]);\r\n   \
    \     for (int j = rk + 1; j < n; j++) {\r\n            if ((v[j] >> i) & 1) {\r\
    \n                v[j] = v[j] ^ v[rk];\r\n            }\r\n        }\r\n     \
    \   rk++;\r\n    }\r\n    res.resize(rk);\r\n    return res;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Step matrix\r\
    \n@docs docs/step_matrix.md\r\n*/\r\n\r\n/*\r\nhttps://atcoder.jp/contests/abc249/tasks/abc249_g\r\
    \n\u5C06 v \u6570\u7EC4\u7684 01 \u77E9\u9635\u53D8\u4E3A step matrix, step matrix:\
    \ \u4E3A\u5BF9\u4E8E\u6BCF\u4E00\u884C\u7B2C\u4E00\u4E2A\u975E 0 \u5217\u662F\u5355\
    \u8C03\u9012\u589E\u7684\r\n\u8F6C\u6362\u5B8C\u4E4B\u540E\u53EF\u4EE5 On \u6C42\
    \u51FA\u4EFB\u610F\u9009\u6570\uFF0C\u4F7F\u5F97\u5F02\u6216\u548C\u6700\u5927\
    \r\n*/\r\nvector<long long> convert(vector<long long> v, int bit) {\r\n    int\
    \ rk = 0;\r\n    int n = v.size();\r\n    vector<long long> res(n);\r\n    for\
    \ (int i = bit - 1; i >= 0; i--) {\r\n        int go = rk;\r\n        while (go\
    \ < n && ((v[go] >> i) & 1) == 0) {\r\n            go++;\r\n        }\r\n    \
    \    if (go == n) continue;\r\n        res[rk] = v[go];\r\n        swap(v[rk],\
    \ v[go]);\r\n        for (int j = rk + 1; j < n; j++) {\r\n            if ((v[j]\
    \ >> i) & 1) {\r\n                v[j] = v[j] ^ v[rk];\r\n            }\r\n  \
    \      }\r\n        rk++;\r\n    }\r\n    res.resize(rk);\r\n    return res;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: src/utils/step_matrix.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utils/step_matrix.h
layout: document
redirect_from:
- /library/src/utils/step_matrix.h
- /library/src/utils/step_matrix.h.html
title: Step matrix
---
