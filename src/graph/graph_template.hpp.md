---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: src/graph/lca.hpp
    title: LCA
  - icon: ':warning:'
    path: src/graph/max_match.hpp
    title: "\u6700\u5927\u5339\u914D"
  - icon: ':warning:'
    path: src/graph/tarjan.hpp
    title: Tarjan
  - icon: ':warning:'
    path: src/graph/two_sat.hpp
    title: two-sat
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.test.cpp
    title: test/graph/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph_template.md
    document_title: Graph template
    links: []
  bundledCode: "#line 2 \"src/graph/graph_template.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n/*\r\n@brief Graph template\r\n@docs docs/graph_template.md\r\
    \n*/\r\n\r\nstruct Edge {\r\n    int from, to;\r\n    int cost;\r\n\r\n    Edge()\
    \ = default;\r\n    Edge(int from, int to, int cost = 1) : from(from), to(to),\
    \ cost(cost) {}\r\n\r\n    // Edge e = Edge(); int to = e;\r\n    operator int()\
    \ const { return to; }\r\n};\r\n\r\n// [0, n)\r\ntemplate <typename Edge>\r\n\
    struct Graph {\r\n    vector<vector<Edge>> g;\r\n\r\n    Graph() = default;\r\n\
    \    explicit Graph(int n) : g(n) {}\r\n\r\n    size_t size() const {\r\n    \
    \    return g.size();\r\n    }\r\n\r\n    void add_directed_edge(const Edge &e)\
    \ {\r\n        g[e.from].push_back(e);\r\n    }\r\n\r\n    void add_undirected_edge(const\
    \ Edge &e) {\r\n        g[e.from].push_back(e);\r\n        Edge rev = e;\r\n \
    \       swap(rev.from, rev.to);\r\n        g[rev.from].push_back(rev);\r\n   \
    \ }\r\n\r\n    inline const vector<Edge> &operator[](const int &u) const {\r\n\
    \        return g[u];\r\n    }\r\n};\r\n\r\ntemplate <typename Edge>\r\nstruct\
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
    \   }\r\n};\n"
  code: "#pragma once\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n\
    /*\r\n@brief Graph template\r\n@docs docs/graph_template.md\r\n*/\r\n\r\nstruct\
    \ Edge {\r\n    int from, to;\r\n    int cost;\r\n\r\n    Edge() = default;\r\n\
    \    Edge(int from, int to, int cost = 1) : from(from), to(to), cost(cost) {}\r\
    \n\r\n    // Edge e = Edge(); int to = e;\r\n    operator int() const { return\
    \ to; }\r\n};\r\n\r\n// [0, n)\r\ntemplate <typename Edge>\r\nstruct Graph {\r\
    \n    vector<vector<Edge>> g;\r\n\r\n    Graph() = default;\r\n    explicit Graph(int\
    \ n) : g(n) {}\r\n\r\n    size_t size() const {\r\n        return g.size();\r\n\
    \    }\r\n\r\n    void add_directed_edge(const Edge &e) {\r\n        g[e.from].push_back(e);\r\
    \n    }\r\n\r\n    void add_undirected_edge(const Edge &e) {\r\n        g[e.from].push_back(e);\r\
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
    \   }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/graph_template.hpp
  requiredBy:
  - src/graph/lca.hpp
  - src/graph/two_sat.hpp
  - src/graph/max_match.hpp
  - src/graph/tarjan.hpp
  - src/graph/dijkstra.hpp
  timestamp: '2022-10-12 22:34:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/lca.test.cpp
documentation_of: src/graph/graph_template.hpp
layout: document
redirect_from:
- /library/src/graph/graph_template.hpp
- /library/src/graph/graph_template.hpp.html
title: Graph template
---
# 概要
Grap 的基本类，其中包括 `Edge`, `Graph`, `Tree`。

# 常见问题

# 题集