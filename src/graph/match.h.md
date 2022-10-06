---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/graph_template.hpp
    title: "\u5E26\u6743\u5E76\u67E5\u96C6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/match.md
    document_title: "\u6700\u5927\u5339\u914D"
    links: []
  bundledCode: "#line 1 \"src/graph/match.h\"\n#include <bits/stdc++.h>\r\n\r\n#line\
    \ 3 \"src/graph/graph_template.hpp\"\nusing namespace std;\r\n\r\n/*\r\n@brief\
    \ \u5E26\u6743\u5E76\u67E5\u96C6\r\n@docs docs/weighted_dsu.md\r\n*/\r\n\r\ntemplate\
    \ <typename T = int>\r\nstruct Edge {\r\n    int from, to;\r\n    T cost;\r\n\
    \    int idx;\r\n\r\n    Edge() = default;\r\n    Edge(int from, int to, T cost\
    \ = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\r\n\r\n   \
    \ // Edge e = Edge(); int to = e;\r\n    operator int() const { return to; }\r\
    \n};\r\n\r\ntemplate <typename T = int>\r\nstruct Graph {\r\n    vector<vector<Edge<T>>>\
    \ g;\r\n    int es;  // \u8FB9\u6570\r\n\r\n    Graph() = default;\r\n    explicit\
    \ Graph(int n) : g(n), es(0) {}\r\n\r\n    size_t size() const {\r\n        return\
    \ g.size();\r\n    }\r\n\r\n    void add_directed_edge(int from, int to, T cost\
    \ = 1) {\r\n        g[from].emplace_back(from, to, cost, es++);\r\n    }\r\n\r\
    \n    void add_undirected_edge(int from, int to, T cost = 1) {\r\n        g[from].emplace_back(from,\
    \ to, cost, es);\r\n        g[to].emplace_back(to, from, cost, es++);  // \u65E0\
    \u5411\u8FB9\u7684\u7F16\u53F7\u76F8\u540C\r\n    }\r\n\r\n    void read(int m,\
    \ int offset = -1, bool directed = false, bool weighted = false) {\r\n       \
    \ for (int i = 0; i < m; i++) {\r\n            int u, v;\r\n            // \u9700\
    \u8981\u5173\u95ED\u540C\u6B65 IO\r\n            cin >> u >> v;\r\n          \
    \  // \u9ED8\u8BA4\u4ECE 0 \u5F00\u59CB\u7F16\u53F7\r\n            u += offset;\r\
    \n            v += offset;\r\n\r\n            T w = 1;\r\n            if (weighted)\
    \ {\r\n                cin >> w;\r\n            }\r\n\r\n            if (directed)\
    \ {\r\n                add_directed_edge(u, v, w);\r\n            } else {\r\n\
    \                add_undirected_edge(u, v, w);\r\n            }\r\n        }\r\
    \n    }\r\n\r\n    inline vector<Edge<T>> &operator[](const int &u) {\r\n    \
    \    return g[u];\r\n    }\r\n\r\n    inline const vector<Edge<T>> &operator[](const\
    \ int &u) const {\r\n        return g[u];\r\n    }\r\n};\r\n\r\ntemplate <typename\
    \ T = int>\r\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/match.h\"\n\
    using namespace std;\r\n/*\r\n@brief \u6700\u5927\u5339\u914D\r\n@docs docs/match.md\r\
    \ntodo: \u5F85\u6574\u7406\r\n*/\r\ntemplate <typename T = int>\r\nstruct Hungary\
    \ : Graph<T> {\r\n    vector<int> cx, cy;\r\n    vector<bool> used;\r\n    int\
    \ count;\r\n\r\n    bool dfs(int u) {\r\n        for (auto v : g[u]) {\r\n   \
    \         if (!used[v]) {\r\n                used[v] = 1;\r\n                if\
    \ (cy[v] == -1 || dfs(cy[v])) {\r\n                    cy[v] = u;\r\n        \
    \            cx[u] = v;\r\n                    return 1;\r\n                }\r\
    \n            }\r\n        }\r\n        return 0;\r\n    }\r\n\r\n    Hungary()\
    \ {}\r\n    Hungary(int uN, int vN, vector<vector<int>> &_g) {\r\n        g =\
    \ _g;\r\n        cx.resize(uN, -1);\r\n        cy.resize(vN, -1);\r\n        used.resize(vN,\
    \ 0);\r\n        int res = 0;\r\n        for (int u = 0; u < uN; u++) {\r\n  \
    \          used.assign(vN, 0);\r\n            if (dfs(u)) res++;\r\n        }\r\
    \n        count = res;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief \u6700\u5927\u5339\u914D\r\n@docs docs/match.md\r\
    \ntodo: \u5F85\u6574\u7406\r\n*/\r\ntemplate <typename T = int>\r\nstruct Hungary\
    \ : Graph<T> {\r\n    vector<int> cx, cy;\r\n    vector<bool> used;\r\n    int\
    \ count;\r\n\r\n    bool dfs(int u) {\r\n        for (auto v : g[u]) {\r\n   \
    \         if (!used[v]) {\r\n                used[v] = 1;\r\n                if\
    \ (cy[v] == -1 || dfs(cy[v])) {\r\n                    cy[v] = u;\r\n        \
    \            cx[u] = v;\r\n                    return 1;\r\n                }\r\
    \n            }\r\n        }\r\n        return 0;\r\n    }\r\n\r\n    Hungary()\
    \ {}\r\n    Hungary(int uN, int vN, vector<vector<int>> &_g) {\r\n        g =\
    \ _g;\r\n        cx.resize(uN, -1);\r\n        cy.resize(vN, -1);\r\n        used.resize(vN,\
    \ 0);\r\n        int res = 0;\r\n        for (int u = 0; u < uN; u++) {\r\n  \
    \          used.assign(vN, 0);\r\n            if (dfs(u)) res++;\r\n        }\r\
    \n        count = res;\r\n    }\r\n};"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/match.h
  requiredBy: []
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/match.h
layout: document
redirect_from:
- /library/src/graph/match.h
- /library/src/graph/match.h.html
title: "\u6700\u5927\u5339\u914D"
---
