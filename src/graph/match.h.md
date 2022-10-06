---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/match.md
    document_title: "\u6700\u5927\u5339\u914D"
    links: []
  bundledCode: "#line 1 \"src/graph/match.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n/*\r\n@brief \u6700\u5927\u5339\u914D\r\n@docs docs/match.md\r\n*/\r\
    \nstruct Hungary {\r\n    vector<int> cx, cy;\r\n    vector<bool> used;\r\n  \
    \  int count;\r\n    vector<vector<int>> g;\r\n\r\n    bool dfs(int u) {\r\n \
    \       for (auto v : g[u]) {\r\n            if (!used[v]) {\r\n             \
    \   used[v] = 1;\r\n                if (cy[v] == -1 || dfs(cy[v])) {\r\n     \
    \               cy[v] = u;\r\n                    cx[u] = v;\r\n             \
    \       return 1;\r\n                }\r\n            }\r\n        }\r\n     \
    \   return 0;\r\n    }\r\n\r\n    Hungary() {}\r\n    Hungary(int uN, int vN,\
    \ vector<vector<int>> &_g) {\r\n        g = _g;\r\n        cx.resize(uN, -1);\r\
    \n        cy.resize(vN, -1);\r\n        used.resize(vN, 0);\r\n        int res\
    \ = 0;\r\n        for (int u = 0; u < uN; u++) {\r\n            used.assign(vN,\
    \ 0);\r\n            if (dfs(u)) res++;\r\n        }\r\n        count = res;\r\
    \n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u6700\u5927\
    \u5339\u914D\r\n@docs docs/match.md\r\n*/\r\nstruct Hungary {\r\n    vector<int>\
    \ cx, cy;\r\n    vector<bool> used;\r\n    int count;\r\n    vector<vector<int>>\
    \ g;\r\n\r\n    bool dfs(int u) {\r\n        for (auto v : g[u]) {\r\n       \
    \     if (!used[v]) {\r\n                used[v] = 1;\r\n                if (cy[v]\
    \ == -1 || dfs(cy[v])) {\r\n                    cy[v] = u;\r\n               \
    \     cx[u] = v;\r\n                    return 1;\r\n                }\r\n   \
    \         }\r\n        }\r\n        return 0;\r\n    }\r\n\r\n    Hungary() {}\r\
    \n    Hungary(int uN, int vN, vector<vector<int>> &_g) {\r\n        g = _g;\r\n\
    \        cx.resize(uN, -1);\r\n        cy.resize(vN, -1);\r\n        used.resize(vN,\
    \ 0);\r\n        int res = 0;\r\n        for (int u = 0; u < uN; u++) {\r\n  \
    \          used.assign(vN, 0);\r\n            if (dfs(u)) res++;\r\n        }\r\
    \n        count = res;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/match.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/match.h
layout: document
redirect_from:
- /library/src/graph/match.h
- /library/src/graph/match.h.html
title: "\u6700\u5927\u5339\u914D"
---
