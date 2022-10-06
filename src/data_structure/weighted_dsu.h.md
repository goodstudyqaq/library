---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/weighted_dsu.md
    document_title: "\u5E26\u6743\u5E76\u67E5\u96C6"
    links: []
  bundledCode: "#line 1 \"src/data_structure/weighted_dsu.h\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\nusing i64 = long long;\r\n/*\r\n@brief \u5E26\u6743\u5E76\
    \u67E5\u96C6\r\n@docs docs/weighted_dsu.md\r\n*/\r\n\r\n// \u5E26\u6743\u5E76\u67E5\
    \u96C6\r\nstruct WeightedDSU {\r\n    std::vector<int> f, g;\r\n    WeightedDSU(int\
    \ n) : f(n), g(n) { std::iota(f.begin(), f.end(), 0); }\r\n    std::array<int,\
    \ 2> leader(int x) {\r\n        if (f[x] == x) {\r\n            return {x, 0};\r\
    \n        }\r\n        auto [y, z] = leader(f[x]);\r\n        f[x] = y;\r\n  \
    \      g[x] ^= z;\r\n        return {f[x], g[x]};\r\n    }\r\n    bool merge(int\
    \ a, int b, int z) {\r\n        auto [x, u] = leader(a);\r\n        auto [y, v]\
    \ = leader(b);\r\n        if (x == y) {\r\n            return (u ^ v ^ z) == 0;\r\
    \n        }\r\n        f[x] = y;\r\n        g[x] = u ^ v ^ z;\r\n        return\
    \ true;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\nusing i64 = long long;\r\
    \n/*\r\n@brief \u5E26\u6743\u5E76\u67E5\u96C6\r\n@docs docs/weighted_dsu.md\r\n\
    */\r\n\r\n// \u5E26\u6743\u5E76\u67E5\u96C6\r\nstruct WeightedDSU {\r\n    std::vector<int>\
    \ f, g;\r\n    WeightedDSU(int n) : f(n), g(n) { std::iota(f.begin(), f.end(),\
    \ 0); }\r\n    std::array<int, 2> leader(int x) {\r\n        if (f[x] == x) {\r\
    \n            return {x, 0};\r\n        }\r\n        auto [y, z] = leader(f[x]);\r\
    \n        f[x] = y;\r\n        g[x] ^= z;\r\n        return {f[x], g[x]};\r\n\
    \    }\r\n    bool merge(int a, int b, int z) {\r\n        auto [x, u] = leader(a);\r\
    \n        auto [y, v] = leader(b);\r\n        if (x == y) {\r\n            return\
    \ (u ^ v ^ z) == 0;\r\n        }\r\n        f[x] = y;\r\n        g[x] = u ^ v\
    \ ^ z;\r\n        return true;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/weighted_dsu.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/weighted_dsu.h
layout: document
redirect_from:
- /library/src/data_structure/weighted_dsu.h
- /library/src/data_structure/weighted_dsu.h.html
title: "\u5E26\u6743\u5E76\u67E5\u96C6"
---
