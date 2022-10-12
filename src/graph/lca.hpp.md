---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.test.cpp
    title: test/graph/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lca.md
    document_title: LCA
    links: []
  bundledCode: "#line 1 \"src/graph/lca.hpp\"\n#include <bits/stdc++.h>\r\n\r\n#line\
    \ 3 \"src/graph/graph_template.hpp\"\nusing namespace std;\r\n\r\n/*\r\n@brief\
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
    \   }\r\n};\n#line 4 \"src/graph/lca.hpp\"\nusing namespace std;\r\n/*\r\n@brief\
    \ LCA\r\n@docs docs/lca.md\r\n*/\r\ntemplate <typename Tree>\r\nstruct Lca {\r\
    \n    Lca(Tree &tree) : tree(tree), root(tree.root) {}\r\n    int get_lca(int\
    \ x, int y) {\r\n        if (dep[x] > dep[y]) swap(x, y);\r\n        for (int\
    \ j = LOG - 1; j >= 0 && dep[x] != dep[y]; j--) {\r\n            if (dep[y] -\
    \ (1 << j) < dep[x]) continue;\r\n            y = parent[y][j];\r\n        }\r\
    \n        if (x == y) return x;\r\n        for (int j = LOG - 1; j >= 0; j--)\
    \ {\r\n            if (dep[x] - (1 << j) < 0 || parent[x][j] == parent[y][j])\
    \ continue;\r\n            x = parent[x][j], y = parent[y][j];\r\n        }\r\n\
    \        return parent[x][0];\r\n    }\r\n\r\n    void build(int rt = -1) {\r\n\
    \        int n = tree.size();\r\n        // 2^k <= n\r\n\r\n        if (rt !=\
    \ -1) root = rt;\r\n        assert(root != -1);\r\n\r\n        LOG = lg2(n) +\
    \ 1;\r\n        dep.resize(n);\r\n        parent.resize(n, vector<int>(LOG, -1));\r\
    \n        dfs(root, -1, 0);\r\n        rmq(n);\r\n    }\r\n\r\n   private:\r\n\
    \    vector<int> dep;\r\n    vector<vector<int>> parent;\r\n    Tree &tree;\r\n\
    \    int root;\r\n    int LOG;\r\n    int lg2(long long x) { return sizeof(long\
    \ long) * 8 - 1 - __builtin_clzll(x); }\r\n    void dfs(int u, int pre, int d)\
    \ {\r\n        parent[u][0] = pre;\r\n        dep[u] = d;\r\n        for (auto\
    \ v : tree[u]) {\r\n            if (v == pre) continue;\r\n            dfs(v,\
    \ u, d + 1);\r\n        }\r\n    }\r\n    void rmq(int n) {\r\n        for (int\
    \ i = 1; i < LOG; i++) {\r\n            for (int j = 0; j < n; j++) {\r\n    \
    \            if ((1 << i) > dep[j]) continue;\r\n                int k = parent[j][i\
    \ - 1];\r\n                parent[j][i] = parent[k][i - 1];\r\n            }\r\
    \n        }\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief LCA\r\n@docs docs/lca.md\r\n*/\r\ntemplate\
    \ <typename Tree>\r\nstruct Lca {\r\n    Lca(Tree &tree) : tree(tree), root(tree.root)\
    \ {}\r\n    int get_lca(int x, int y) {\r\n        if (dep[x] > dep[y]) swap(x,\
    \ y);\r\n        for (int j = LOG - 1; j >= 0 && dep[x] != dep[y]; j--) {\r\n\
    \            if (dep[y] - (1 << j) < dep[x]) continue;\r\n            y = parent[y][j];\r\
    \n        }\r\n        if (x == y) return x;\r\n        for (int j = LOG - 1;\
    \ j >= 0; j--) {\r\n            if (dep[x] - (1 << j) < 0 || parent[x][j] == parent[y][j])\
    \ continue;\r\n            x = parent[x][j], y = parent[y][j];\r\n        }\r\n\
    \        return parent[x][0];\r\n    }\r\n\r\n    void build(int rt = -1) {\r\n\
    \        int n = tree.size();\r\n        // 2^k <= n\r\n\r\n        if (rt !=\
    \ -1) root = rt;\r\n        assert(root != -1);\r\n\r\n        LOG = lg2(n) +\
    \ 1;\r\n        dep.resize(n);\r\n        parent.resize(n, vector<int>(LOG, -1));\r\
    \n        dfs(root, -1, 0);\r\n        rmq(n);\r\n    }\r\n\r\n   private:\r\n\
    \    vector<int> dep;\r\n    vector<vector<int>> parent;\r\n    Tree &tree;\r\n\
    \    int root;\r\n    int LOG;\r\n    int lg2(long long x) { return sizeof(long\
    \ long) * 8 - 1 - __builtin_clzll(x); }\r\n    void dfs(int u, int pre, int d)\
    \ {\r\n        parent[u][0] = pre;\r\n        dep[u] = d;\r\n        for (auto\
    \ v : tree[u]) {\r\n            if (v == pre) continue;\r\n            dfs(v,\
    \ u, d + 1);\r\n        }\r\n    }\r\n    void rmq(int n) {\r\n        for (int\
    \ i = 1; i < LOG; i++) {\r\n            for (int j = 0; j < n; j++) {\r\n    \
    \            if ((1 << i) > dep[j]) continue;\r\n                int k = parent[j][i\
    \ - 1];\r\n                parent[j][i] = parent[k][i - 1];\r\n            }\r\
    \n        }\r\n    }\r\n};"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/lca.hpp
  requiredBy: []
  timestamp: '2022-10-12 22:34:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/lca.test.cpp
documentation_of: src/graph/lca.hpp
layout: document
redirect_from:
- /library/src/graph/lca.hpp
- /library/src/graph/lca.hpp.html
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