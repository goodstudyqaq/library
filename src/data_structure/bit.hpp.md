---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/bit.hpp\"\n#include <vector>\r\nusing\
    \ namespace std;\r\ntemplate <typename T>\r\nstruct Fenwick {\r\n#define lowbit(x)\
    \ x & -x\r\n    const int n;\r\n    vector<T> a;\r\n    Fenwick(int n) : n(n),\
    \ a(n + 1) {}\r\n    void add(int x, T v) {\r\n        while (x <= n) {\r\n  \
    \          a[x] += v;\r\n            x += lowbit(x);\r\n        }\r\n    }\r\n\
    \r\n    T query(int x) {\r\n        T res = 0;\r\n        while (x) {\r\n    \
    \        res += a[x];\r\n            x -= lowbit(x);\r\n        }\r\n        return\
    \ res;\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\nusing namespace std;\r\ntemplate <typename\
    \ T>\r\nstruct Fenwick {\r\n#define lowbit(x) x & -x\r\n    const int n;\r\n \
    \   vector<T> a;\r\n    Fenwick(int n) : n(n), a(n + 1) {}\r\n    void add(int\
    \ x, T v) {\r\n        while (x <= n) {\r\n            a[x] += v;\r\n        \
    \    x += lowbit(x);\r\n        }\r\n    }\r\n\r\n    T query(int x) {\r\n   \
    \     T res = 0;\r\n        while (x) {\r\n            res += a[x];\r\n      \
    \      x -= lowbit(x);\r\n        }\r\n        return res;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/bit.hpp
  requiredBy: []
  timestamp: '2022-10-06 10:48:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/bit.hpp
layout: document
redirect_from:
- /library/src/data_structure/bit.hpp
- /library/src/data_structure/bit.hpp.html
title: src/data_structure/bit.hpp
---
