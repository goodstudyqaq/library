---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/lca.h
    title: LCA
  - icon: ':warning:'
    path: src/graph/max_match.h
    title: "\u6700\u5927\u5339\u914D"
  - icon: ':warning:'
    path: src/graph/shortest_path.h
    title: "\u6700\u77ED\u8DEF"
  - icon: ':warning:'
    path: src/graph/tarjan.h
    title: Tarjan
  - icon: ':warning:'
    path: src/graph/two_sat.h
    title: two-sat
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/weighted_dsu.md
    document_title: "\u5E26\u6743\u5E76\u67E5\u96C6"
    links: []
  bundledCode: "#line 2 \"src/graph/graph_template.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n/*\r\n@brief \u5E26\u6743\u5E76\u67E5\u96C6\r\n\
    @docs docs/weighted_dsu.md\r\n*/\r\n\r\ntemplate <typename T = int>\r\nstruct\
    \ Edge {\r\n    int from, to;\r\n    T cost;\r\n    int idx;\r\n\r\n    Edge()\
    \ = default;\r\n    Edge(int from, int to, T cost = 1, int idx = -1) : from(from),\
    \ to(to), cost(cost), idx(idx) {}\r\n\r\n    // Edge e = Edge(); int to = e;\r\
    \n    operator int() const { return to; }\r\n};\r\n\r\ntemplate <typename T =\
    \ int>\r\nstruct Graph {\r\n    vector<vector<Edge<T>>> g;\r\n    int es;  //\
    \ \u8FB9\u6570\r\n\r\n    Graph() = default;\r\n    explicit Graph(int n) : g(n),\
    \ es(0) {}\r\n\r\n    size_t size() const {\r\n        return g.size();\r\n  \
    \  }\r\n\r\n    void add_directed_edge(int from, int to, T cost = 1) {\r\n   \
    \     g[from].emplace_back(from, to, cost, es++);\r\n    }\r\n\r\n    void add_undirected_edge(int\
    \ from, int to, T cost = 1) {\r\n        g[from].emplace_back(from, to, cost,\
    \ es);\r\n        g[to].emplace_back(to, from, cost, es++);  // \u65E0\u5411\u8FB9\
    \u7684\u7F16\u53F7\u76F8\u540C\r\n    }\r\n\r\n    void read(int m, int offset\
    \ = -1, bool directed = false, bool weighted = false) {\r\n        for (int i\
    \ = 0; i < m; i++) {\r\n            int u, v;\r\n            // \u9700\u8981\u5173\
    \u95ED\u540C\u6B65 IO\r\n            cin >> u >> v;\r\n            // \u9ED8\u8BA4\
    \u4ECE 0 \u5F00\u59CB\u7F16\u53F7\r\n            u += offset;\r\n            v\
    \ += offset;\r\n\r\n            T w = 1;\r\n            if (weighted) {\r\n  \
    \              cin >> w;\r\n            }\r\n\r\n            if (directed) {\r\
    \n                add_directed_edge(u, v, w);\r\n            } else {\r\n    \
    \            add_undirected_edge(u, v, w);\r\n            }\r\n        }\r\n \
    \   }\r\n\r\n    inline vector<Edge<T>> &operator[](const int &u) {\r\n      \
    \  return g[u];\r\n    }\r\n\r\n    inline const vector<Edge<T>> &operator[](const\
    \ int &u) const {\r\n        return g[u];\r\n    }\r\n};\r\n\r\ntemplate <typename\
    \ T = int>\r\nusing Edges = vector<Edge<T>>;\n"
  code: "#pragma once\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n\
    /*\r\n@brief \u5E26\u6743\u5E76\u67E5\u96C6\r\n@docs docs/weighted_dsu.md\r\n\
    */\r\n\r\ntemplate <typename T = int>\r\nstruct Edge {\r\n    int from, to;\r\n\
    \    T cost;\r\n    int idx;\r\n\r\n    Edge() = default;\r\n    Edge(int from,\
    \ int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx)\
    \ {}\r\n\r\n    // Edge e = Edge(); int to = e;\r\n    operator int() const {\
    \ return to; }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct Graph {\r\n\
    \    vector<vector<Edge<T>>> g;\r\n    int es;  // \u8FB9\u6570\r\n\r\n    Graph()\
    \ = default;\r\n    explicit Graph(int n) : g(n), es(0) {}\r\n\r\n    size_t size()\
    \ const {\r\n        return g.size();\r\n    }\r\n\r\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\r\n        g[from].emplace_back(from, to, cost,\
    \ es++);\r\n    }\r\n\r\n    void add_undirected_edge(int from, int to, T cost\
    \ = 1) {\r\n        g[from].emplace_back(from, to, cost, es);\r\n        g[to].emplace_back(to,\
    \ from, cost, es++);  // \u65E0\u5411\u8FB9\u7684\u7F16\u53F7\u76F8\u540C\r\n\
    \    }\r\n\r\n    void read(int m, int offset = -1, bool directed = false, bool\
    \ weighted = false) {\r\n        for (int i = 0; i < m; i++) {\r\n           \
    \ int u, v;\r\n            // \u9700\u8981\u5173\u95ED\u540C\u6B65 IO\r\n    \
    \        cin >> u >> v;\r\n            // \u9ED8\u8BA4\u4ECE 0 \u5F00\u59CB\u7F16\
    \u53F7\r\n            u += offset;\r\n            v += offset;\r\n\r\n       \
    \     T w = 1;\r\n            if (weighted) {\r\n                cin >> w;\r\n\
    \            }\r\n\r\n            if (directed) {\r\n                add_directed_edge(u,\
    \ v, w);\r\n            } else {\r\n                add_undirected_edge(u, v,\
    \ w);\r\n            }\r\n        }\r\n    }\r\n\r\n    inline vector<Edge<T>>\
    \ &operator[](const int &u) {\r\n        return g[u];\r\n    }\r\n\r\n    inline\
    \ const vector<Edge<T>> &operator[](const int &u) const {\r\n        return g[u];\r\
    \n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nusing Edges = vector<Edge<T>>;"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/graph_template.hpp
  requiredBy:
  - src/graph/tarjan.h
  - src/graph/shortest_path.h
  - src/graph/two_sat.h
  - src/graph/lca.h
  - src/graph/max_match.h
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/graph_template.hpp
layout: document
redirect_from:
- /library/src/graph/graph_template.hpp
- /library/src/graph/graph_template.hpp.html
title: "\u5E26\u6743\u5E76\u67E5\u96C6"
---
# 带权并查集

## 概要
带权并查集是一种在并查集的基础上加入了权值的数据结构，它可以用来维护一些关于并查集的性质，例如：两个集合的大小，两个集合的和，两个集合的最大值，两个集合的最小值等等。
### `WeightedDSU`
`WeightedDSU` 是该算法的模板类，`T` 类需要支持 `+` 和 `-` 运算符。
- `WeightedDSU(int n)`：创建一个包含 `n` 个元素的并查集。区间范围为 `[0, n)` 。
- `pair<int, T> leader(int x)`：返回 `x` 所在集合的代表元素和 `x` 到代表元素的距离。
- `bool merge(int x, int y, T z)`：将 `x` 和 `y` 所在的集合合并，如果 `x` 和 `y` 已经在同一个集合中，且关系和 `z` 矛盾，则返回 `false` ，否则返回 `true` 。`z` 表示 `x` 到 `y` 的距离。


## 常见问题

# 题集