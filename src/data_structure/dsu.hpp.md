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
    _deprecated_at_docs: docs/dsu.md
    document_title: "\u5E76\u67E5\u96C6"
    links: []
  bundledCode: "#line 1 \"src/data_structure/dsu.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief \u5E76\u67E5\u96C6\r\n@docs docs/dsu.md\r\
    \n*/\r\nstruct DSU {\r\n    std::vector<int> f;\r\n    DSU(int n) : f(n) { std::iota(f.begin(),\
    \ f.end(), 0); }\r\n    int leader(int x) {\r\n        if (f[x] == x) {\r\n  \
    \          return x;\r\n        }\r\n        int y = leader(f[x]);\r\n       \
    \ f[x] = y;\r\n        return f[x];\r\n    }\r\n    bool merge(int a, int b) {\r\
    \n        auto x = leader(a);\r\n        auto y = leader(b);\r\n        if (x\
    \ == y) {\r\n            return false;\r\n        }\r\n        f[x] = y;\r\n \
    \       return true;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u5E76\u67E5\
    \u96C6\r\n@docs docs/dsu.md\r\n*/\r\nstruct DSU {\r\n    std::vector<int> f;\r\
    \n    DSU(int n) : f(n) { std::iota(f.begin(), f.end(), 0); }\r\n    int leader(int\
    \ x) {\r\n        if (f[x] == x) {\r\n            return x;\r\n        }\r\n \
    \       int y = leader(f[x]);\r\n        f[x] = y;\r\n        return f[x];\r\n\
    \    }\r\n    bool merge(int a, int b) {\r\n        auto x = leader(a);\r\n  \
    \      auto y = leader(b);\r\n        if (x == y) {\r\n            return false;\r\
    \n        }\r\n        f[x] = y;\r\n        return true;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/dsu.hpp
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dsu.test.cpp
documentation_of: src/data_structure/dsu.hpp
layout: document
redirect_from:
- /library/src/data_structure/dsu.hpp
- /library/src/data_structure/dsu.hpp.html
title: "\u5E76\u67E5\u96C6"
---
