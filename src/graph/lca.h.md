---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/lca.md
    document_title: LCA
    links: []
  bundledCode: "#line 1 \"src/graph/lca.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n/*\r\n@brief LCA\r\n@docs docs/lca.md\r\n*/\r\nint lg2(long long x)\
    \ { return sizeof(long long) * 8 - 1 - __builtin_clzll(x); }\r\nstruct Lca {\r\
    \n    // [1, n]\r\n    vector<vector<int>>& g;\r\n    vector<int> dep;\r\n   \
    \ vector<vector<int>> parent;\r\n    int LOG;\r\n    void dfs(int u, int pre,\
    \ int d) {\r\n        parent[u][0] = pre;\r\n        dep[u] = d;\r\n        for\
    \ (auto v : g[u]) {\r\n            if (v == pre) continue;\r\n            dfs(v,\
    \ u, d + 1);\r\n        }\r\n    }\r\n    void rmq(int n) {\r\n        for (int\
    \ i = 1; i < LOG; i++) {\r\n            for (int j = 1; j <= n; j++) {\r\n   \
    \             if ((1 << i) > dep[j]) continue;\r\n                int k = parent[j][i\
    \ - 1];\r\n                parent[j][i] = parent[k][i - 1];\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    Lca(vector<vector<int>>& Graph, int rt = -1) :\
    \ g(Graph) {\r\n        int n = Graph.size();\r\n        LOG = lg2(n);\r\n   \
    \     dep.resize(n + 1);\r\n        parent.resize(n + 1, vector<int>(LOG, -1));\r\
    \n        if (rt == -1) {\r\n            rt = 1;\r\n        }\r\n        dfs(rt,\
    \ -1, 0);\r\n        rmq(n);\r\n    }\r\n\r\n    int get_lca(int x, int y) {\r\
    \n        if (dep[x] > dep[y]) swap(x, y);\r\n        for (int j = LOG - 1; j\
    \ >= 0 && dep[x] != dep[y]; j--) {\r\n            if (dep[y] - (1 << j) < dep[x])\
    \ continue;\r\n            y = parent[y][j];\r\n        }\r\n        if (x ==\
    \ y) return x;\r\n        for (int j = LOG - 1; j >= 0; j--) {\r\n           \
    \ if (dep[x] - (1 << j) < 0 || parent[x][j] == parent[y][j]) continue;\r\n   \
    \         x = parent[x][j], y = parent[y][j];\r\n        }\r\n        return parent[x][0];\r\
    \n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief LCA\r\n\
    @docs docs/lca.md\r\n*/\r\nint lg2(long long x) { return sizeof(long long) * 8\
    \ - 1 - __builtin_clzll(x); }\r\nstruct Lca {\r\n    // [1, n]\r\n    vector<vector<int>>&\
    \ g;\r\n    vector<int> dep;\r\n    vector<vector<int>> parent;\r\n    int LOG;\r\
    \n    void dfs(int u, int pre, int d) {\r\n        parent[u][0] = pre;\r\n   \
    \     dep[u] = d;\r\n        for (auto v : g[u]) {\r\n            if (v == pre)\
    \ continue;\r\n            dfs(v, u, d + 1);\r\n        }\r\n    }\r\n    void\
    \ rmq(int n) {\r\n        for (int i = 1; i < LOG; i++) {\r\n            for (int\
    \ j = 1; j <= n; j++) {\r\n                if ((1 << i) > dep[j]) continue;\r\n\
    \                int k = parent[j][i - 1];\r\n                parent[j][i] = parent[k][i\
    \ - 1];\r\n            }\r\n        }\r\n    }\r\n\r\n    Lca(vector<vector<int>>&\
    \ Graph, int rt = -1) : g(Graph) {\r\n        int n = Graph.size();\r\n      \
    \  LOG = lg2(n);\r\n        dep.resize(n + 1);\r\n        parent.resize(n + 1,\
    \ vector<int>(LOG, -1));\r\n        if (rt == -1) {\r\n            rt = 1;\r\n\
    \        }\r\n        dfs(rt, -1, 0);\r\n        rmq(n);\r\n    }\r\n\r\n    int\
    \ get_lca(int x, int y) {\r\n        if (dep[x] > dep[y]) swap(x, y);\r\n    \
    \    for (int j = LOG - 1; j >= 0 && dep[x] != dep[y]; j--) {\r\n            if\
    \ (dep[y] - (1 << j) < dep[x]) continue;\r\n            y = parent[y][j];\r\n\
    \        }\r\n        if (x == y) return x;\r\n        for (int j = LOG - 1; j\
    \ >= 0; j--) {\r\n            if (dep[x] - (1 << j) < 0 || parent[x][j] == parent[y][j])\
    \ continue;\r\n            x = parent[x][j], y = parent[y][j];\r\n        }\r\n\
    \        return parent[x][0];\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/lca.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lca.h
layout: document
redirect_from:
- /library/src/graph/lca.h
- /library/src/graph/lca.h.html
title: LCA
---
