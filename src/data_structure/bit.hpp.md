---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/bit.md
    document_title: "\u6811\u72B6\u6570\u7EC4"
    links: []
  bundledCode: "#line 1 \"src/data_structure/bit.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief \u6811\u72B6\u6570\u7EC4\r\n@docs docs/bit.md\r\
    \n*/\r\ntemplate <typename T>\r\nstruct Fenwick {\r\n#define lowbit(x) x & -x\r\
    \n    const int n;\r\n    vector<T> a;\r\n    Fenwick(int n) : n(n), a(n + 1)\
    \ {}\r\n    void add(int x, T v) {\r\n        while (x <= n) {\r\n           \
    \ a[x] += v;\r\n            x += lowbit(x);\r\n        }\r\n    }\r\n\r\n    T\
    \ query(int x) {\r\n        T res = 0;\r\n        while (x) {\r\n            res\
    \ += a[x];\r\n            x -= lowbit(x);\r\n        }\r\n        return res;\r\
    \n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u6811\u72B6\
    \u6570\u7EC4\r\n@docs docs/bit.md\r\n*/\r\ntemplate <typename T>\r\nstruct Fenwick\
    \ {\r\n#define lowbit(x) x & -x\r\n    const int n;\r\n    vector<T> a;\r\n  \
    \  Fenwick(int n) : n(n), a(n + 1) {}\r\n    void add(int x, T v) {\r\n      \
    \  while (x <= n) {\r\n            a[x] += v;\r\n            x += lowbit(x);\r\
    \n        }\r\n    }\r\n\r\n    T query(int x) {\r\n        T res = 0;\r\n   \
    \     while (x) {\r\n            res += a[x];\r\n            x -= lowbit(x);\r\
    \n        }\r\n        return res;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/bit.hpp
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/bit.hpp
layout: document
redirect_from:
- /library/src/data_structure/bit.hpp
- /library/src/data_structure/bit.hpp.html
title: "\u6811\u72B6\u6570\u7EC4"
---
