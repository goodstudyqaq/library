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
    _deprecated_at_docs: docs/shortest_path.md
    document_title: "\u6700\u77ED\u8DEF"
    links:
    - https://atcoder.jp/contests/abc245/submissions/32661509
    - https://atcoder.jp/contests/abc245/tasks/abc245_g
  bundledCode: "#line 1 \"src/graph/shortest_path.h\"\n#include <bits/stdc++.h>\r\n\
    \r\n#line 3 \"src/graph/graph_template.hpp\"\nusing namespace std;\r\n\r\n/*\r\
    \n@brief \u5E26\u6743\u5E76\u67E5\u96C6\r\n@docs docs/weighted_dsu.md\r\n*/\r\n\
    \r\ntemplate <typename T = int>\r\nstruct Edge {\r\n    int from, to;\r\n    T\
    \ cost;\r\n    int idx;\r\n\r\n    Edge() = default;\r\n    Edge(int from, int\
    \ to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\r\
    \n\r\n    // Edge e = Edge(); int to = e;\r\n    operator int() const { return\
    \ to; }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct Graph {\r\n    vector<vector<Edge<T>>>\
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
    \ T = int>\r\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/shortest_path.h\"\
    \nusing namespace std;\r\n/*\r\n@brief \u6700\u77ED\u8DEF\r\n@docs docs/shortest_path.md\r\
    \n*/\r\n\r\n/*\r\n\u5957\u8DEF\u9898\uFF1A\u4E8C\u8FDB\u5236\u5224\u4E0D\u540C\
    \u8272\u6700\u77ED\u8DEF or \u6B21\u77ED\u8DEF\u3002https://atcoder.jp/contests/abc245/tasks/abc245_g\r\
    \n\u6B21\u77ED\u8DEF\u505A\u6CD5\uFF1A\u518D\u52A0\u4E00\u4E2A\u8DDD\u79BB\u6570\
    \u7EC4 dis2, \u5177\u4F53\u770B\uFF1Ahttps://atcoder.jp/contests/abc245/submissions/32661509\r\
    \n*/\r\n\r\n// \u4E00\u822C\u5F62\u5F0F\u7684 dijkstra\r\ntemplate <typename T\
    \ = int>\r\nstruct Dijkstra : Graph<T> {\r\n    // \u4E0B\u6807\u4ECE 1 \u5230\
    \ n\r\n\r\n    vector<T> normal_dijkstra(int s) {\r\n        // O(n ^ 2)\r\n \
    \       const T inf = numeric_limits<T>::max();\r\n        int n = g.size();\r\
    \n        vector<bool> vis(n, 0);\r\n        vector<T> d(n, inf);\r\n\r\n    \
    \    d[s] = 0;\r\n        for (int i = 0; i < n; i++) {\r\n            int x,\
    \ m = inf;\r\n            for (int y = 1; y <= n; y++) {\r\n                if\
    \ (!vis[y] && d[y] <= m) {\r\n                    m = d[x = y];\r\n          \
    \      }\r\n            }\r\n            vis[x] = 1;\r\n            for (auto\
    \ e : g[x]) {\r\n                int y = e.to;\r\n                if (d[y] > d[x]\
    \ + e.w) {\r\n                    d[y] = d[x] + e.w;\r\n                }\r\n\
    \            }\r\n        }\r\n        return d;\r\n    }\r\n\r\n    vector<T>\
    \ dijkstra(int s) {\r\n        // O(m * log n)\r\n        const T inf = numeric_limits<T>::max();\r\
    \n        int n = g.size();\r\n        vector<T> d(n, inf);\r\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;\r\n        vector<bool>\
    \ vis(n, 0);\r\n\r\n        d[s] = 0;\r\n        Q.push({0, s});\r\n        while\
    \ (!Q.empty()) {\r\n            auto [dis, x] = Q.top();\r\n            Q.pop();\r\
    \n            if (vis[x]) continue;\r\n            vis[x] = 1;\r\n\r\n       \
    \     for (auto e : g[x]) {\r\n                int y = e.to;\r\n             \
    \   if (d[y] > d[x] + e.w) {\r\n                    d[y] = d[x] + e.w;\r\n   \
    \                 Q.push({d[y], y});\r\n                }\r\n            }\r\n\
    \        }\r\n        return d;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief \u6700\u77ED\u8DEF\r\n@docs docs/shortest_path.md\r\
    \n*/\r\n\r\n/*\r\n\u5957\u8DEF\u9898\uFF1A\u4E8C\u8FDB\u5236\u5224\u4E0D\u540C\
    \u8272\u6700\u77ED\u8DEF or \u6B21\u77ED\u8DEF\u3002https://atcoder.jp/contests/abc245/tasks/abc245_g\r\
    \n\u6B21\u77ED\u8DEF\u505A\u6CD5\uFF1A\u518D\u52A0\u4E00\u4E2A\u8DDD\u79BB\u6570\
    \u7EC4 dis2, \u5177\u4F53\u770B\uFF1Ahttps://atcoder.jp/contests/abc245/submissions/32661509\r\
    \n*/\r\n\r\n// \u4E00\u822C\u5F62\u5F0F\u7684 dijkstra\r\ntemplate <typename T\
    \ = int>\r\nstruct Dijkstra : Graph<T> {\r\n    // \u4E0B\u6807\u4ECE 1 \u5230\
    \ n\r\n\r\n    vector<T> normal_dijkstra(int s) {\r\n        // O(n ^ 2)\r\n \
    \       const T inf = numeric_limits<T>::max();\r\n        int n = g.size();\r\
    \n        vector<bool> vis(n, 0);\r\n        vector<T> d(n, inf);\r\n\r\n    \
    \    d[s] = 0;\r\n        for (int i = 0; i < n; i++) {\r\n            int x,\
    \ m = inf;\r\n            for (int y = 1; y <= n; y++) {\r\n                if\
    \ (!vis[y] && d[y] <= m) {\r\n                    m = d[x = y];\r\n          \
    \      }\r\n            }\r\n            vis[x] = 1;\r\n            for (auto\
    \ e : g[x]) {\r\n                int y = e.to;\r\n                if (d[y] > d[x]\
    \ + e.w) {\r\n                    d[y] = d[x] + e.w;\r\n                }\r\n\
    \            }\r\n        }\r\n        return d;\r\n    }\r\n\r\n    vector<T>\
    \ dijkstra(int s) {\r\n        // O(m * log n)\r\n        const T inf = numeric_limits<T>::max();\r\
    \n        int n = g.size();\r\n        vector<T> d(n, inf);\r\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;\r\n        vector<bool>\
    \ vis(n, 0);\r\n\r\n        d[s] = 0;\r\n        Q.push({0, s});\r\n        while\
    \ (!Q.empty()) {\r\n            auto [dis, x] = Q.top();\r\n            Q.pop();\r\
    \n            if (vis[x]) continue;\r\n            vis[x] = 1;\r\n\r\n       \
    \     for (auto e : g[x]) {\r\n                int y = e.to;\r\n             \
    \   if (d[y] > d[x] + e.w) {\r\n                    d[y] = d[x] + e.w;\r\n   \
    \                 Q.push({d[y], y});\r\n                }\r\n            }\r\n\
    \        }\r\n        return d;\r\n    }\r\n};\r\n"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/shortest_path.h
  requiredBy: []
  timestamp: '2022-10-06 23:48:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/shortest_path.h
layout: document
redirect_from:
- /library/src/graph/shortest_path.h
- /library/src/graph/shortest_path.h.html
title: "\u6700\u77ED\u8DEF"
---
# 单源最短路(dijkstra)
## 概要
Dijkstra 算法是一种用于计算有向图中单源最短路径的算法。堆优化的时间复杂度为 $O(m\log n)$，其中 $m$ 为边数，$n$ 为点数。普通写法的时间复杂度为 $O(mn)$。

### `Dijkstra`
`Dijkstra` 类为 Dijkstra 算法的主体，它继承自 `Graph` 类。主要有以下几个方法:
- `vector<T> dijkstra(int s)` : 从点 $s$ 开始计算所有点到 $s$ 的最短距离, 该函数使用堆优化，时间复杂度为 $O(m\log n)$。
- `vector<T> normal_dijkstra(int s)`: 从点 $s$ 开始计算所有点到 $s$ 的最短距离, 该函数为普通写法，时间复杂度为 $O(mn)$。

## 常见问题

## 题集