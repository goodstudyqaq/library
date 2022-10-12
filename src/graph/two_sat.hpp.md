---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/two_sat.md
    document_title: two-sat
    links: []
  bundledCode: "#line 1 \"src/graph/two_sat.hpp\"\n#include <bits/stdc++.h>\r\n\r\n\
    #line 3 \"src/graph/graph_template.hpp\"\nusing namespace std;\r\n\r\n/*\r\n@brief\
    \ Graph template\r\n@docs docs/graph_template.md\r\n*/\r\n\r\nstruct Edge {\r\n\
    \    int from, to;\r\n    int cost;\r\n\r\n    Edge() = default;\r\n    Edge(int\
    \ from, int to, int cost = 1) : from(from), to(to), cost(cost) {}\r\n\r\n    //\
    \ Edge e = Edge(); int to = e;\r\n    operator int() const { return to; }\r\n\
    };\r\n\r\n// [0, n)\r\ntemplate <typename Edge>\r\nstruct Graph {\r\n    vector<vector<Edge>>\
    \ g;\r\n\r\n    Graph() = default;\r\n    explicit Graph(int n) : g(n) {}\r\n\r\
    \n    size_t size() const {\r\n        return g.size();\r\n    }\r\n\r\n    void\
    \ add_directed_edge(const Edge &e) {\r\n        g[e.from].push_back(e);\r\n  \
    \  }\r\n\r\n    void add_undirected_edge(const Edge &e) {\r\n        g[e.from].push_back(e);\r\
    \n        Edge rev = e;\r\n        swap(rev.from, rev.to);\r\n        g[rev.from].push_back(rev);\r\
    \n    }\r\n\r\n    inline const vector<Edge> &operator[](const int &u) const {\r\
    \n        return g[u];\r\n    }\r\n};\r\n\r\ntemplate <typename Edge>\r\nstruct\
    \ Tree : Graph<Edge> {\r\n    using Graph<Edge>::g;\r\n    using Graph<Edge>::add_directed_edge;\r\
    \n    using Graph<Edge>::add_undirected_edge;\r\n    using Graph<Edge>::size;\r\
    \n    int root;\r\n\r\n    Tree() = default;\r\n    // root = -1 \u4E3A\u65E0\u6839\
    \u6811\r\n    explicit Tree(int n, int root = -1) : Graph<Edge>(n), root(root)\
    \ {}\r\n\r\n    // todo: \u53EF\u4EE5\u52A0\u4E00\u4E9B\u5E38\u7528\u7684\u6811\
    \u7684\u64CD\u4F5C\uFF0C\u6BD4\u5982\u6C42\u91CD\u5FC3\uFF0C\u6C42\u76F4\u5F84\
    \uFF0C\u6C42\u5B50\u6811\u5927\u5C0F\u7B49\r\n};\r\n\r\ntemplate <typename Edge>\r\
    \nstruct BipartiteGraph : Graph<Edge> {\r\n    using Graph<Edge>::g;\r\n    using\
    \ Graph<Edge>::add_directed_edge;\r\n    using Graph<Edge>::add_undirected_edge;\r\
    \n    using Graph<Edge>::size;\r\n    int n, m;\r\n    // \u4E8C\u5206\u56FE\u7684\
    \u5DE6\u53F3\u4E24\u8FB9\u7684\u70B9\r\n    vector<int> bl, br;\r\n\r\n    BipartiteGraph()\
    \ = default;\r\n    explicit BipartiteGraph(int n, int m) : Graph<Edge>(n + m),\
    \ n(n), m(m) {\r\n        for (int i = 0; i < n; i++) bl.push_back(i);\r\n   \
    \     for (int i = n; i < n + m; i++) br.push_back(i);\r\n    }\r\n\r\n    void\
    \ add_edge(int u, int v) {\r\n        add_directed_edge(Edge(u, v + n));\r\n \
    \   }\r\n};\n#line 4 \"src/graph/two_sat.hpp\"\n/*\r\n@brief two-sat\r\n@docs\
    \ docs/two_sat.md\r\n*/\r\ntemplate <typename T = int>\r\nstruct TwoSat : Graph<T>\
    \ {\r\n    // [0, 2 * n]\r\n    int n;\r\n    std::vector<bool> ans;\r\n    TwoSat(int\
    \ n) : n(n), ans(n), Graph<T>(2 * n) {}\r\n    void addClause(int u, bool f, int\
    \ v, bool g) {\r\n        // (u, f) \u548C (v, g) \u6709\u77DB\u76FE\r\n     \
    \   add_directed_edge(2 * u + !f, 2 * v + g);\r\n        add_directed_edge(2 *\
    \ v + !g, 2 * u + f);\r\n    }\r\n    bool satisfiable() {\r\n        std::vector<int>\
    \ id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);\r\n        std::vector<int> stk;\r\
    \n        int now = 0, cnt = 0;\r\n        std::function<void(int)> tarjan = [&](int\
    \ u) {\r\n            stk.push_back(u);\r\n            dfn[u] = low[u] = now++;\r\
    \n            for (auto v : e[u]) {\r\n                if (dfn[v] == -1) {\r\n\
    \                    tarjan(v);\r\n                    low[u] = std::min(low[u],\
    \ low[v]);\r\n                } else if (id[v] == -1) {\r\n                  \
    \  low[u] = std::min(low[u], dfn[v]);\r\n                }\r\n            }\r\n\
    \            if (dfn[u] == low[u]) {\r\n                int v;\r\n           \
    \     do {\r\n                    v = stk.back();\r\n                    stk.pop_back();\r\
    \n                    id[v] = cnt;\r\n                } while (v != u);\r\n  \
    \              ++cnt;\r\n            }\r\n        };\r\n        for (int i = 0;\
    \ i < 2 * n; ++i)\r\n            if (dfn[i] == -1) tarjan(i);\r\n\r\n        /*\r\
    \n            \u65B9\u6848\u53EF\u4EE5\u901A\u8FC7\u53D8\u91CF\u5728\u56FE\u4E2D\
    \u7684\u62D3\u6251\u5E8F\u786E\u5B9A\u8BE5\u53D8\u91CF\u7684\u503C\uFF0C\u5982\
    \u679C\u53D8\u91CF !x \u7684\u62D3\u6251\u5E8F\u5728 x \u4E4B\u540E\uFF0C\u90A3\
    \u4E48 x \u4E3A\u771F.\r\n            \u5E94\u7528\u5230 tarjan \u5F53\u4E2D\uFF0C\
    \u5373 x \u7684 SCC \u7F16\u53F7\u5728 !x \u4E4B\u524D\uFF0C\u53D6 x \u4E3A\u771F\
    \u3002\u56E0\u4E3A tarjan \u7528\u5230\u4E86\u6808\uFF0C\u6240\u4EE5 tarjan \u6C42\
    \u51FA\u7684 SCC \u7F16\u53F7\u76F8\u5F53\u4E8E\u53CD\u62D3\u6251\u5E8F\u3002\r\
    \n        */\r\n\r\n        for (int i = 0; i < n; ++i) {\r\n            if (id[2\
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
  path: src/graph/two_sat.hpp
  requiredBy: []
  timestamp: '2022-10-12 22:34:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/two_sat.hpp
layout: document
redirect_from:
- /library/src/graph/two_sat.hpp
- /library/src/graph/two_sat.hpp.html
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