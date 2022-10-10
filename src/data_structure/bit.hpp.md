---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/bits.test.cpp
    title: test/data_structure/bits.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/bit.md
    document_title: "\u6811\u72B6\u6570\u7EC4"
    links: []
  bundledCode: "#line 1 \"src/data_structure/bit.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief \u6811\u72B6\u6570\u7EC4\r\n@docs docs/bit.md\r\
    \n*/\r\ntemplate <typename T>\r\nstruct Fenwick {\r\n#define lowbit(x) x & -x\r\
    \n    const int n;\r\n    vector<T> a;\r\n    // [1, n]\r\n    Fenwick(int n)\
    \ : n(n), a(n + 1) {}\r\n    void add(int x, T v) {\r\n        while (x <= n)\
    \ {\r\n            a[x] += v;\r\n            x += lowbit(x);\r\n        }\r\n\
    \    }\r\n\r\n    // [1, x]\r\n    T query(int x) {\r\n        T res = 0;\r\n\
    \        while (x) {\r\n            res += a[x];\r\n            x -= lowbit(x);\r\
    \n        }\r\n        return res;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u6811\u72B6\
    \u6570\u7EC4\r\n@docs docs/bit.md\r\n*/\r\ntemplate <typename T>\r\nstruct Fenwick\
    \ {\r\n#define lowbit(x) x & -x\r\n    const int n;\r\n    vector<T> a;\r\n  \
    \  // [1, n]\r\n    Fenwick(int n) : n(n), a(n + 1) {}\r\n    void add(int x,\
    \ T v) {\r\n        while (x <= n) {\r\n            a[x] += v;\r\n           \
    \ x += lowbit(x);\r\n        }\r\n    }\r\n\r\n    // [1, x]\r\n    T query(int\
    \ x) {\r\n        T res = 0;\r\n        while (x) {\r\n            res += a[x];\r\
    \n            x -= lowbit(x);\r\n        }\r\n        return res;\r\n    }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/bit.hpp
  requiredBy: []
  timestamp: '2022-10-09 21:27:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/bits.test.cpp
documentation_of: src/data_structure/bit.hpp
layout: document
redirect_from:
- /library/src/data_structure/bit.hpp
- /library/src/data_structure/bit.hpp.html
title: "\u6811\u72B6\u6570\u7EC4"
---
# 树状数组

## 概要
树状数组（Binary Indexed Tree）是一种用于维护序列前缀和的数据结构。它的时间复杂度为 $O(\log n)$ 。
### `Fenwick`
`Fenwick` 类维护一个长度为 $n$ 的序列，支持以下操作：
- `Fenwick(int n)` : 构造一个长度为 $n$ 的序列，初始值均为 $0$ 。区间范围为 $[1, n]$ 。
- `void add(i, x)` : 将序列中第 $i$ 个数加上 $x$ 。
- `T query(i)` : 求序列中前 $i$ 个数的和。


## 常见问题

## 题集