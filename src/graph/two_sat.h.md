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
    _deprecated_at_docs: docs/two_sat.md
    document_title: two-sat
    links: []
  bundledCode: "#line 1 \"src/graph/two_sat.h\"\n#include <bits/stdc++.h>\r\n\r\n\
    #line 3 \"src/graph/graph_template.hpp\"\nusing namespace std;\r\n\r\n/*\r\n@brief\
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
    \ T = int>\r\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/two_sat.h\"\n\
    /*\r\n@brief two-sat\r\n@docs docs/two_sat.md\r\n*/\r\ntemplate <typename T =\
    \ int>\r\nstruct TwoSat : Graph<T> {\r\n    // [0, 2 * n]\r\n    int n;\r\n  \
    \  std::vector<bool> ans;\r\n    TwoSat(int n) : n(n), ans(n), Graph<T>(2 * n)\
    \ {}\r\n    void addClause(int u, bool f, int v, bool g) {\r\n        // (u, f)\
    \ \u548C (v, g) \u6709\u77DB\u76FE\r\n        add_directed_edge(2 * u + !f, 2\
    \ * v + g);\r\n        add_directed_edge(2 * v + !g, 2 * u + f);\r\n    }\r\n\
    \    bool satisfiable() {\r\n        std::vector<int> id(2 * n, -1), dfn(2 * n,\
    \ -1), low(2 * n, -1);\r\n        std::vector<int> stk;\r\n        int now = 0,\
    \ cnt = 0;\r\n        std::function<void(int)> tarjan = [&](int u) {\r\n     \
    \       stk.push_back(u);\r\n            dfn[u] = low[u] = now++;\r\n        \
    \    for (auto v : e[u]) {\r\n                if (dfn[v] == -1) {\r\n        \
    \            tarjan(v);\r\n                    low[u] = std::min(low[u], low[v]);\r\
    \n                } else if (id[v] == -1) {\r\n                    low[u] = std::min(low[u],\
    \ dfn[v]);\r\n                }\r\n            }\r\n            if (dfn[u] ==\
    \ low[u]) {\r\n                int v;\r\n                do {\r\n            \
    \        v = stk.back();\r\n                    stk.pop_back();\r\n          \
    \          id[v] = cnt;\r\n                } while (v != u);\r\n             \
    \   ++cnt;\r\n            }\r\n        };\r\n        for (int i = 0; i < 2 * n;\
    \ ++i)\r\n            if (dfn[i] == -1) tarjan(i);\r\n\r\n        /*\r\n     \
    \       \u65B9\u6848\u53EF\u4EE5\u901A\u8FC7\u53D8\u91CF\u5728\u56FE\u4E2D\u7684\
    \u62D3\u6251\u5E8F\u786E\u5B9A\u8BE5\u53D8\u91CF\u7684\u503C\uFF0C\u5982\u679C\
    \u53D8\u91CF !x \u7684\u62D3\u6251\u5E8F\u5728 x \u4E4B\u540E\uFF0C\u90A3\u4E48\
    \ x \u4E3A\u771F.\r\n            \u5E94\u7528\u5230 tarjan \u5F53\u4E2D\uFF0C\u5373\
    \ x \u7684 SCC \u7F16\u53F7\u5728 !x \u4E4B\u524D\uFF0C\u53D6 x \u4E3A\u771F\u3002\
    \u56E0\u4E3A tarjan \u7528\u5230\u4E86\u6808\uFF0C\u6240\u4EE5 tarjan \u6C42\u51FA\
    \u7684 SCC \u7F16\u53F7\u76F8\u5F53\u4E8E\u53CD\u62D3\u6251\u5E8F\u3002\r\n  \
    \      */\r\n\r\n        for (int i = 0; i < n; ++i) {\r\n            if (id[2\
    \ * i] == id[2 * i + 1]) return false;\r\n            ans[i] = id[2 * i] < id[2\
    \ * i + 1];\r\n        }\r\n        return true;\r\n    }\r\n    std::vector<bool>\
    \ answer() { return ans; }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\n/*\r\n@brief two-sat\r\n@docs docs/two_sat.md\r\n*/\r\ntemplate <typename\
    \ T = int>\r\nstruct TwoSat : Graph<T> {\r\n    // [0, 2 * n]\r\n    int n;\r\n\
    \    std::vector<bool> ans;\r\n    TwoSat(int n) : n(n), ans(n), Graph<T>(2 *\
    \ n) {}\r\n    void addClause(int u, bool f, int v, bool g) {\r\n        // (u,\
    \ f) \u548C (v, g) \u6709\u77DB\u76FE\r\n        add_directed_edge(2 * u + !f,\
    \ 2 * v + g);\r\n        add_directed_edge(2 * v + !g, 2 * u + f);\r\n    }\r\n\
    \    bool satisfiable() {\r\n        std::vector<int> id(2 * n, -1), dfn(2 * n,\
    \ -1), low(2 * n, -1);\r\n        std::vector<int> stk;\r\n        int now = 0,\
    \ cnt = 0;\r\n        std::function<void(int)> tarjan = [&](int u) {\r\n     \
    \       stk.push_back(u);\r\n            dfn[u] = low[u] = now++;\r\n        \
    \    for (auto v : e[u]) {\r\n                if (dfn[v] == -1) {\r\n        \
    \            tarjan(v);\r\n                    low[u] = std::min(low[u], low[v]);\r\
    \n                } else if (id[v] == -1) {\r\n                    low[u] = std::min(low[u],\
    \ dfn[v]);\r\n                }\r\n            }\r\n            if (dfn[u] ==\
    \ low[u]) {\r\n                int v;\r\n                do {\r\n            \
    \        v = stk.back();\r\n                    stk.pop_back();\r\n          \
    \          id[v] = cnt;\r\n                } while (v != u);\r\n             \
    \   ++cnt;\r\n            }\r\n        };\r\n        for (int i = 0; i < 2 * n;\
    \ ++i)\r\n            if (dfn[i] == -1) tarjan(i);\r\n\r\n        /*\r\n     \
    \       \u65B9\u6848\u53EF\u4EE5\u901A\u8FC7\u53D8\u91CF\u5728\u56FE\u4E2D\u7684\
    \u62D3\u6251\u5E8F\u786E\u5B9A\u8BE5\u53D8\u91CF\u7684\u503C\uFF0C\u5982\u679C\
    \u53D8\u91CF !x \u7684\u62D3\u6251\u5E8F\u5728 x \u4E4B\u540E\uFF0C\u90A3\u4E48\
    \ x \u4E3A\u771F.\r\n            \u5E94\u7528\u5230 tarjan \u5F53\u4E2D\uFF0C\u5373\
    \ x \u7684 SCC \u7F16\u53F7\u5728 !x \u4E4B\u524D\uFF0C\u53D6 x \u4E3A\u771F\u3002\
    \u56E0\u4E3A tarjan \u7528\u5230\u4E86\u6808\uFF0C\u6240\u4EE5 tarjan \u6C42\u51FA\
    \u7684 SCC \u7F16\u53F7\u76F8\u5F53\u4E8E\u53CD\u62D3\u6251\u5E8F\u3002\r\n  \
    \      */\r\n\r\n        for (int i = 0; i < n; ++i) {\r\n            if (id[2\
    \ * i] == id[2 * i + 1]) return false;\r\n            ans[i] = id[2 * i] < id[2\
    \ * i + 1];\r\n        }\r\n        return true;\r\n    }\r\n    std::vector<bool>\
    \ answer() { return ans; }\r\n};"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/two_sat.h
  requiredBy: []
  timestamp: '2022-10-06 23:48:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/two_sat.h
layout: document
redirect_from:
- /library/src/graph/two_sat.h
- /library/src/graph/two_sat.h.html
title: two-sat
---
# TwoSat
## 概要
TwoSat 是一个用于解决 2-SAT 问题的算法。它的时间复杂度为 O(n+m)。
### `TwoSat` 
`TwoSat` 类是一个用于解决 2-SAT 问题的类。它继承自 `Graph` 类。主要有以下函数：
- `TwoSat(int n)`：构造函数，参数为变量的个数。
- `void addClause(int u, bool f, int v, bool g)`: (u, f) 和 (v, g) 有矛盾。
- `bool satisfiable()`: 判断是否有解。
- `vector<bool> answer()`: 返回解。


## 常见问题

## 题集