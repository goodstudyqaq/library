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
    _deprecated_at_docs: docs/lca.md
    document_title: LCA
    links: []
  bundledCode: "#line 1 \"src/graph/lca.h\"\n#include <bits/stdc++.h>\r\n\r\n#line\
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
    \ T = int>\r\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/lca.h\"\nusing\
    \ namespace std;\r\n/*\r\n@brief LCA\r\n@docs docs/lca.md\r\n*/\r\ntemplate <typename\
    \ T = int>\r\nstruct Lca : Graph<T> {\r\n    vector<int> dep;\r\n    vector<vector<int>>\
    \ parent;\r\n    int LOG;\r\n    int lg2(long long x) { return sizeof(long long)\
    \ * 8 - 1 - __builtin_clzll(x); }\r\n    void dfs(int u, int pre, int d) {\r\n\
    \        parent[u][0] = pre;\r\n        dep[u] = d;\r\n        for (auto v : g[u])\
    \ {\r\n            if (v == pre) continue;\r\n            dfs(v, u, d + 1);\r\n\
    \        }\r\n    }\r\n    void rmq(int n) {\r\n        for (int i = 1; i < LOG;\
    \ i++) {\r\n            for (int j = 0; j < n; j++) {\r\n                if ((1\
    \ << i) > dep[j]) continue;\r\n                int k = parent[j][i - 1];\r\n \
    \               parent[j][i] = parent[k][i - 1];\r\n            }\r\n        }\r\
    \n    }\r\n\r\n    void build(int rt = 0) {\r\n        int n = g.size();\r\n \
    \       // 2^k <= n\r\n        LOG = lg2(n) + 1;\r\n        dep.resize(n);\r\n\
    \        parent.resize(n, vector<int>(LOG, -1));\r\n        dfs(rt, -1, 0);\r\n\
    \        rmq(n);\r\n    }\r\n\r\n    int get_lca(int x, int y) {\r\n        if\
    \ (dep[x] > dep[y]) swap(x, y);\r\n        for (int j = LOG - 1; j >= 0 && dep[x]\
    \ != dep[y]; j--) {\r\n            if (dep[y] - (1 << j) < dep[x]) continue;\r\
    \n            y = parent[y][j];\r\n        }\r\n        if (x == y) return x;\r\
    \n        for (int j = LOG - 1; j >= 0; j--) {\r\n            if (dep[x] - (1\
    \ << j) < 0 || parent[x][j] == parent[y][j]) continue;\r\n            x = parent[x][j],\
    \ y = parent[y][j];\r\n        }\r\n        return parent[x][0];\r\n    }\r\n\
    };\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief LCA\r\n@docs docs/lca.md\r\n*/\r\ntemplate\
    \ <typename T = int>\r\nstruct Lca : Graph<T> {\r\n    vector<int> dep;\r\n  \
    \  vector<vector<int>> parent;\r\n    int LOG;\r\n    int lg2(long long x) { return\
    \ sizeof(long long) * 8 - 1 - __builtin_clzll(x); }\r\n    void dfs(int u, int\
    \ pre, int d) {\r\n        parent[u][0] = pre;\r\n        dep[u] = d;\r\n    \
    \    for (auto v : g[u]) {\r\n            if (v == pre) continue;\r\n        \
    \    dfs(v, u, d + 1);\r\n        }\r\n    }\r\n    void rmq(int n) {\r\n    \
    \    for (int i = 1; i < LOG; i++) {\r\n            for (int j = 0; j < n; j++)\
    \ {\r\n                if ((1 << i) > dep[j]) continue;\r\n                int\
    \ k = parent[j][i - 1];\r\n                parent[j][i] = parent[k][i - 1];\r\n\
    \            }\r\n        }\r\n    }\r\n\r\n    void build(int rt = 0) {\r\n \
    \       int n = g.size();\r\n        // 2^k <= n\r\n        LOG = lg2(n) + 1;\r\
    \n        dep.resize(n);\r\n        parent.resize(n, vector<int>(LOG, -1));\r\n\
    \        dfs(rt, -1, 0);\r\n        rmq(n);\r\n    }\r\n\r\n    int get_lca(int\
    \ x, int y) {\r\n        if (dep[x] > dep[y]) swap(x, y);\r\n        for (int\
    \ j = LOG - 1; j >= 0 && dep[x] != dep[y]; j--) {\r\n            if (dep[y] -\
    \ (1 << j) < dep[x]) continue;\r\n            y = parent[y][j];\r\n        }\r\
    \n        if (x == y) return x;\r\n        for (int j = LOG - 1; j >= 0; j--)\
    \ {\r\n            if (dep[x] - (1 << j) < 0 || parent[x][j] == parent[y][j])\
    \ continue;\r\n            x = parent[x][j], y = parent[y][j];\r\n        }\r\n\
    \        return parent[x][0];\r\n    }\r\n};"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/lca.h
  requiredBy: []
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lca.h
layout: document
redirect_from:
- /library/src/graph/lca.h
- /library/src/graph/lca.h.html
title: LCA
---
# LCA(最小公共祖先)

## 概要
LCA 是 Lowest Common Ancestor 的缩写，即最小公共祖先。在树上，两个节点的最小公共祖先是指这两个节点的最近公共祖先，且这个祖先的深度最小。在一般的树上，两个节点的最小公共祖先可能不唯一，但在有根树上，两个节点的最小公共祖先是唯一的。

### `LCA`
`LCA` 是该算法的模板类，该类继承自 `Graph`，并且在 `Graph` 的基础上增加了 `LCA` 的相关算法。它主要有 2 个函数。
- `void build(int rt = 0)`
  - 功能：预处理，建立 `LCA` 的相关数据结构。
  - 参数：
    - `rt`：根节点的编号，默认为 0。
  - 时间复杂度：$O(n\log n)$
- `int get_lca(int x, int y)`: 
  - 功能：求两个节点的最小公共祖先。
  - 参数：
    - `x`：节点的编号。
    - `y`：节点的编号。
  - 返回值：两个节点的最小公共祖先的编号。
  - 时间复杂度：$O(\log n)$


## 常见问题

## 题集
h