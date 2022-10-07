---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph_utils.md
    document_title: Utils
    links:
    - https://codeforces.com/contest/1695/problem/E
  bundledCode: "#line 1 \"src/graph/util.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief Utils\r\n@docs docs/graph_utils.md\r\ntodo\
    \ : \u5F85\u6574\u7406\r\n*/\r\n/*\r\nhttps://codeforces.com/contest/1695/problem/E\r\
    \n\u7279\u522B\u7684\u904D\u5386\u56FE\uFF0C\u80FD\u4FDD\u8BC1 stk \u91CC\u6709\
    \ 2k + 1 \u4E2A\u70B9\uFF0C\u4E14\u7B2C\u4E00\u4E2A\u548C\u6700\u540E\u4E00\u4E2A\
    \u76F8\u7B49\uFF0C[2t, 2t + 1] \u548C [2t - 1, 2t] \u90FD\u662F\u4E00\u6761\u8FB9\
    \r\n*/\r\nvector<int>\r\n    stk;\r\nvector<int> vis;\r\nvector<int> vis2;\r\n\
    typedef pair<int, int> pii;\r\nvector<vector<pii>> V;\r\nvoid dfs(int u) {\r\n\
    \    stk.emplace_back(u);\r\n    if (vis[u]) return;\r\n    vis[u] = 1;\r\n\r\n\
    \    for (auto e : V[u]) {\r\n        if (vis2[e.second]) continue;\r\n      \
    \  vis2[e.second] = 1;\r\n        dfs(e.first);\r\n        stk.emplace_back(u);\r\
    \n    }\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief Utils\r\
    \n@docs docs/graph_utils.md\r\ntodo : \u5F85\u6574\u7406\r\n*/\r\n/*\r\nhttps://codeforces.com/contest/1695/problem/E\r\
    \n\u7279\u522B\u7684\u904D\u5386\u56FE\uFF0C\u80FD\u4FDD\u8BC1 stk \u91CC\u6709\
    \ 2k + 1 \u4E2A\u70B9\uFF0C\u4E14\u7B2C\u4E00\u4E2A\u548C\u6700\u540E\u4E00\u4E2A\
    \u76F8\u7B49\uFF0C[2t, 2t + 1] \u548C [2t - 1, 2t] \u90FD\u662F\u4E00\u6761\u8FB9\
    \r\n*/\r\nvector<int>\r\n    stk;\r\nvector<int> vis;\r\nvector<int> vis2;\r\n\
    typedef pair<int, int> pii;\r\nvector<vector<pii>> V;\r\nvoid dfs(int u) {\r\n\
    \    stk.emplace_back(u);\r\n    if (vis[u]) return;\r\n    vis[u] = 1;\r\n\r\n\
    \    for (auto e : V[u]) {\r\n        if (vis2[e.second]) continue;\r\n      \
    \  vis2[e.second] = 1;\r\n        dfs(e.first);\r\n        stk.emplace_back(u);\r\
    \n    }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/util.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/util.hpp
layout: document
redirect_from:
- /library/src/graph/util.hpp
- /library/src/graph/util.hpp.html
title: Utils
---
