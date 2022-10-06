---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/weighted_dsu.md
    document_title: "\u5E26\u6743\u5E76\u67E5\u96C6"
    links: []
  bundledCode: "#line 1 \"src/data_structure/weighted_dsu.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief \u5E26\u6743\u5E76\u67E5\u96C6\r\n@docs\
    \ docs/weighted_dsu.md\r\n*/\r\n\r\n// \u5E26\u6743\u5E76\u67E5\u96C6\r\ntemplate\
    \ <typename T>\r\nstruct WeightedDSU {\r\n    std::vector<int> f;\r\n    vector<T>\
    \ g;\r\n    WeightedDSU(int n) : f(n), g(n) { std::iota(f.begin(), f.end(), 0);\
    \ }\r\n    std::pair<int, T> leader(int x) {\r\n        if (f[x] == x) {\r\n \
    \           return {x, g[x]};\r\n        }\r\n        auto [y, z] = leader(f[x]);\r\
    \n        f[x] = y;\r\n        g[x] += z;\r\n        return {f[x], g[x]};\r\n\
    \    }\r\n    // a->b=z\r\n    bool merge(int a, int b, T z) {\r\n        // a->x=u\r\
    \n        auto [x, u] = leader(a);\r\n        // b->y=v\r\n        auto [y, v]\
    \ = leader(b);\r\n        if (x == y) {\r\n            // a->x\r\n           \
    \ return u - v == z;\r\n        }\r\n        f[x] = y;\r\n        g[x] = v - u\
    \ + z;\r\n        return true;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u5E26\u6743\
    \u5E76\u67E5\u96C6\r\n@docs docs/weighted_dsu.md\r\n*/\r\n\r\n// \u5E26\u6743\u5E76\
    \u67E5\u96C6\r\ntemplate <typename T>\r\nstruct WeightedDSU {\r\n    std::vector<int>\
    \ f;\r\n    vector<T> g;\r\n    WeightedDSU(int n) : f(n), g(n) { std::iota(f.begin(),\
    \ f.end(), 0); }\r\n    std::pair<int, T> leader(int x) {\r\n        if (f[x]\
    \ == x) {\r\n            return {x, g[x]};\r\n        }\r\n        auto [y, z]\
    \ = leader(f[x]);\r\n        f[x] = y;\r\n        g[x] += z;\r\n        return\
    \ {f[x], g[x]};\r\n    }\r\n    // a->b=z\r\n    bool merge(int a, int b, T z)\
    \ {\r\n        // a->x=u\r\n        auto [x, u] = leader(a);\r\n        // b->y=v\r\
    \n        auto [y, v] = leader(b);\r\n        if (x == y) {\r\n            //\
    \ a->x\r\n            return u - v == z;\r\n        }\r\n        f[x] = y;\r\n\
    \        g[x] = v - u + z;\r\n        return true;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/weighted_dsu.hpp
  requiredBy: []
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/weighted_dsu.hpp
layout: document
redirect_from:
- /library/src/data_structure/weighted_dsu.hpp
- /library/src/data_structure/weighted_dsu.hpp.html
title: "\u5E26\u6743\u5E76\u67E5\u96C6"
---
# 带权并查集

## 概要
带权并查集是一种在并查集的基础上加入了权值的数据结构，它可以用来维护一些关于并查集的性质，例如：两个集合的大小，两个集合的和，两个集合的最大值，两个集合的最小值等等。
### `WeightedDSU`
`WeightedDSU` 是该算法的模板类，`T` 类需要支持 `+` 和 `-` 运算符。
- `WeightedDSU(int n)`：创建一个包含 `n` 个元素的并查集。区间范围为 `[0, n)` 。
- `pair<int, T> leader(int x)`：返回 `x` 所在集合的代表元素和 `x` 到代表元素的距离。
- `bool merge(int x, int y, T z)`：将 `x` 和 `y` 所在的集合合并，如果 `x` 和 `y` 已经在同一个集合中，且关系和 `z` 矛盾，则返回 `false` ，否则返回 `true` 。`z` 表示 `x` 到 `y` 的距离。


## 常见问题

# 题集