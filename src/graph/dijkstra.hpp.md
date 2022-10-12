---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/shortest_path.md
    document_title: Dijkstra
    links:
    - https://atcoder.jp/contests/abc245/submissions/32661509
    - https://atcoder.jp/contests/abc245/tasks/abc245_g
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\n#include <bits/stdc++.h>\r\n\r\
    \n#line 3 \"src/graph/graph_template.hpp\"\nusing namespace std;\r\n\r\n/*\r\n\
    @brief Graph template\r\n@docs docs/graph_template.md\r\n*/\r\n\r\nstruct Edge\
    \ {\r\n    int from, to;\r\n    int cost;\r\n\r\n    Edge() = default;\r\n   \
    \ Edge(int from, int to, int cost = 1) : from(from), to(to), cost(cost) {}\r\n\
    \r\n    // Edge e = Edge(); int to = e;\r\n    operator int() const { return to;\
    \ }\r\n};\r\n\r\n// [0, n)\r\ntemplate <typename Edge>\r\nstruct Graph {\r\n \
    \   vector<vector<Edge>> g;\r\n\r\n    Graph() = default;\r\n    explicit Graph(int\
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
    \   }\r\n};\n#line 4 \"src/graph/dijkstra.hpp\"\nusing namespace std;\r\n/*\r\n\
    @brief Dijkstra\r\n@docs docs/shortest_path.md\r\n*/\r\n\r\n/*\r\n\u5957\u8DEF\
    \u9898\uFF1A\u4E8C\u8FDB\u5236\u5224\u4E0D\u540C\u8272\u6700\u77ED\u8DEF or \u6B21\
    \u77ED\u8DEF\u3002https://atcoder.jp/contests/abc245/tasks/abc245_g\r\n\u6B21\u77ED\
    \u8DEF\u505A\u6CD5\uFF1A\u518D\u52A0\u4E00\u4E2A\u8DDD\u79BB\u6570\u7EC4 dis2,\
    \ \u5177\u4F53\u770B\uFF1Ahttps://atcoder.jp/contests/abc245/submissions/32661509\r\
    \n*/\r\n\r\n// \u4E00\u822C\u5F62\u5F0F\u7684 dijkstra\r\ntemplate <typename Graph,\
    \ typename T>\r\nstruct Dijkstra {\r\n    Graph &g;\r\n    T inf;\r\n\r\n    vector<T>\
    \ dist;\r\n    vector<int> prev;\r\n    vector<long long> num;\r\n\r\n    Dijkstra(Graph\
    \ &graph) : g(graph) {\r\n        inf = numeric_limits<T>::max();\r\n    }\r\n\
    \r\n    void init(int n) {\r\n        dist.resize(n, inf);\r\n        prev.resize(n,\
    \ -1);\r\n        num.resize(n, 0);\r\n\r\n        for (int i = 0; i < n; i++)\
    \ {\r\n            dist[i] = inf;\r\n            prev[i] = -1;\r\n           \
    \ num[i] = 0;\r\n        }\r\n    }\r\n\r\n    // [0, n)\r\n    void normal_dijkstra(int\
    \ s) {\r\n        // O(n ^ 2)\r\n        int n = g.size();\r\n        vector<bool>\
    \ vis(n, 0);\r\n        init(n);\r\n\r\n        dist[s] = 0;\r\n        num[s]\
    \ = 1;\r\n\r\n        for (int i = 0; i < n; i++) {\r\n            int x;\r\n\
    \            T m = inf;\r\n            for (int y = 1; y <= n; y++) {\r\n    \
    \            if (!vis[y] && dist[y] <= m) {\r\n                    m = dist[x\
    \ = y];\r\n                }\r\n            }\r\n            vis[x] = 1;\r\n \
    \           for (auto e : g[x]) {\r\n                int y = e.to;\r\n       \
    \         if (dist[y] > dist[x] + e.cost) {\r\n                    dist[y] = dist[x]\
    \ + e.cost;\r\n                    prev[y] = x;\r\n                    num[y]\
    \ = num[x];\r\n                } else if (dist[y] == dist[x] + e.cost) {\r\n \
    \                   num[y] += num[x];\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    void dijkstra(int s) {\r\n        // O(m * log\
    \ n)\r\n        const T inf = numeric_limits<T>::max();\r\n        int n = g.size();\r\
    \n        vector<bool> vis(n, 0);\r\n        init(n);\r\n\r\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;\r\n\r\n        dist[s]\
    \ = 0;\r\n        num[s] = 1;\r\n        Q.push({0, s});\r\n        while (!Q.empty())\
    \ {\r\n            auto [dis, x] = Q.top();\r\n            Q.pop();\r\n      \
    \      if (vis[x]) continue;\r\n            vis[x] = 1;\r\n\r\n            for\
    \ (auto e : g[x]) {\r\n                int y = e.to;\r\n                if (dist[y]\
    \ > dist[x] + e.cost) {\r\n                    dist[y] = dist[x] + e.cost;\r\n\
    \                    prev[y] = x;\r\n                    num[y] = num[x];\r\n\
    \                    Q.push({dist[y], y});\r\n                } else {\r\n   \
    \                 num[y] += num[x];\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief Dijkstra\r\n@docs docs/shortest_path.md\r\
    \n*/\r\n\r\n/*\r\n\u5957\u8DEF\u9898\uFF1A\u4E8C\u8FDB\u5236\u5224\u4E0D\u540C\
    \u8272\u6700\u77ED\u8DEF or \u6B21\u77ED\u8DEF\u3002https://atcoder.jp/contests/abc245/tasks/abc245_g\r\
    \n\u6B21\u77ED\u8DEF\u505A\u6CD5\uFF1A\u518D\u52A0\u4E00\u4E2A\u8DDD\u79BB\u6570\
    \u7EC4 dis2, \u5177\u4F53\u770B\uFF1Ahttps://atcoder.jp/contests/abc245/submissions/32661509\r\
    \n*/\r\n\r\n// \u4E00\u822C\u5F62\u5F0F\u7684 dijkstra\r\ntemplate <typename Graph,\
    \ typename T>\r\nstruct Dijkstra {\r\n    Graph &g;\r\n    T inf;\r\n\r\n    vector<T>\
    \ dist;\r\n    vector<int> prev;\r\n    vector<long long> num;\r\n\r\n    Dijkstra(Graph\
    \ &graph) : g(graph) {\r\n        inf = numeric_limits<T>::max();\r\n    }\r\n\
    \r\n    void init(int n) {\r\n        dist.resize(n, inf);\r\n        prev.resize(n,\
    \ -1);\r\n        num.resize(n, 0);\r\n\r\n        for (int i = 0; i < n; i++)\
    \ {\r\n            dist[i] = inf;\r\n            prev[i] = -1;\r\n           \
    \ num[i] = 0;\r\n        }\r\n    }\r\n\r\n    // [0, n)\r\n    void normal_dijkstra(int\
    \ s) {\r\n        // O(n ^ 2)\r\n        int n = g.size();\r\n        vector<bool>\
    \ vis(n, 0);\r\n        init(n);\r\n\r\n        dist[s] = 0;\r\n        num[s]\
    \ = 1;\r\n\r\n        for (int i = 0; i < n; i++) {\r\n            int x;\r\n\
    \            T m = inf;\r\n            for (int y = 1; y <= n; y++) {\r\n    \
    \            if (!vis[y] && dist[y] <= m) {\r\n                    m = dist[x\
    \ = y];\r\n                }\r\n            }\r\n            vis[x] = 1;\r\n \
    \           for (auto e : g[x]) {\r\n                int y = e.to;\r\n       \
    \         if (dist[y] > dist[x] + e.cost) {\r\n                    dist[y] = dist[x]\
    \ + e.cost;\r\n                    prev[y] = x;\r\n                    num[y]\
    \ = num[x];\r\n                } else if (dist[y] == dist[x] + e.cost) {\r\n \
    \                   num[y] += num[x];\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    void dijkstra(int s) {\r\n        // O(m * log\
    \ n)\r\n        const T inf = numeric_limits<T>::max();\r\n        int n = g.size();\r\
    \n        vector<bool> vis(n, 0);\r\n        init(n);\r\n\r\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;\r\n\r\n        dist[s]\
    \ = 0;\r\n        num[s] = 1;\r\n        Q.push({0, s});\r\n        while (!Q.empty())\
    \ {\r\n            auto [dis, x] = Q.top();\r\n            Q.pop();\r\n      \
    \      if (vis[x]) continue;\r\n            vis[x] = 1;\r\n\r\n            for\
    \ (auto e : g[x]) {\r\n                int y = e.to;\r\n                if (dist[y]\
    \ > dist[x] + e.cost) {\r\n                    dist[y] = dist[x] + e.cost;\r\n\
    \                    prev[y] = x;\r\n                    num[y] = num[x];\r\n\
    \                    Q.push({dist[y], y});\r\n                } else {\r\n   \
    \                 num[y] += num[x];\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n};\r\n"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-10-12 22:34:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: Dijkstra
---
