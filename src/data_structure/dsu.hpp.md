---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dsu.test.cpp
    title: test/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/dsu.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\nusing i64 = long long;\r\n\r\nstruct DSU {\r\n    std::vector<int>\
    \ f, g;\r\n    DSU(int n) : f(n), g(n) { std::iota(f.begin(), f.end(), 0); }\r\
    \n    std::array<int, 2> leader(int x) {\r\n        if (f[x] == x) {\r\n     \
    \       return {x, 0};\r\n        }\r\n        auto [y, z] = leader(f[x]);\r\n\
    \        f[x] = y;\r\n        g[x] ^= z;\r\n        return {f[x], g[x]};\r\n \
    \   }\r\n    bool merge(int a, int b, int z) {\r\n        auto [x, u] = leader(a);\r\
    \n        auto [y, v] = leader(b);\r\n        if (x == y) {\r\n            return\
    \ (u ^ v ^ z) == 0;\r\n        }\r\n        f[x] = y;\r\n        g[x] = u ^ v\
    \ ^ z;\r\n        return true;\r\n    }\r\n};\r\n\r\nstruct DSU2 {\r\n    std::vector<int>\
    \ f;\r\n    DSU2(int n) : f(n) { std::iota(f.begin(), f.end(), 0); }\r\n    int\
    \ leader(int x) {\r\n        if (f[x] == x) {\r\n            return x;\r\n   \
    \     }\r\n        int y = leader(f[x]);\r\n        f[x] = y;\r\n        return\
    \ f[x];\r\n    }\r\n    bool merge(int a, int b) {\r\n        auto x = leader(a);\r\
    \n        auto y = leader(b);\r\n        if (x == y) {\r\n            return false;\r\
    \n        }\r\n        f[x] = y;\r\n        return true;\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\nusing\
    \ i64 = long long;\r\n\r\nstruct DSU {\r\n    std::vector<int> f, g;\r\n    DSU(int\
    \ n) : f(n), g(n) { std::iota(f.begin(), f.end(), 0); }\r\n    std::array<int,\
    \ 2> leader(int x) {\r\n        if (f[x] == x) {\r\n            return {x, 0};\r\
    \n        }\r\n        auto [y, z] = leader(f[x]);\r\n        f[x] = y;\r\n  \
    \      g[x] ^= z;\r\n        return {f[x], g[x]};\r\n    }\r\n    bool merge(int\
    \ a, int b, int z) {\r\n        auto [x, u] = leader(a);\r\n        auto [y, v]\
    \ = leader(b);\r\n        if (x == y) {\r\n            return (u ^ v ^ z) == 0;\r\
    \n        }\r\n        f[x] = y;\r\n        g[x] = u ^ v ^ z;\r\n        return\
    \ true;\r\n    }\r\n};\r\n\r\nstruct DSU2 {\r\n    std::vector<int> f;\r\n   \
    \ DSU2(int n) : f(n) { std::iota(f.begin(), f.end(), 0); }\r\n    int leader(int\
    \ x) {\r\n        if (f[x] == x) {\r\n            return x;\r\n        }\r\n \
    \       int y = leader(f[x]);\r\n        f[x] = y;\r\n        return f[x];\r\n\
    \    }\r\n    bool merge(int a, int b) {\r\n        auto x = leader(a);\r\n  \
    \      auto y = leader(b);\r\n        if (x == y) {\r\n            return false;\r\
    \n        }\r\n        f[x] = y;\r\n        return true;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/dsu.hpp
  requiredBy: []
  timestamp: '2022-10-06 10:48:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dsu.test.cpp
documentation_of: src/data_structure/dsu.hpp
layout: document
redirect_from:
- /library/src/data_structure/dsu.hpp
- /library/src/data_structure/dsu.hpp.html
title: src/data_structure/dsu.hpp
---
