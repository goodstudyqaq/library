---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/spfa.md
    document_title: "\u6700\u5C0F\u8D39\u7528\u6700\u5927\u6D41"
    links: []
  bundledCode: "#line 1 \"src/graph/spfa.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n/*\r\n@brief \u6700\u5C0F\u8D39\u7528\u6700\u5927\u6D41\r\n@docs\
    \ docs/spfa.md\r\n*/\r\n\r\nnamespace Network {\r\ntemplate <typename IntType>\r\
    \nclass IntValue {\r\n   public:\r\n    using ValueType = IntType;\r\n\r\n   \
    \ static bool greater_than_zero(ValueType x) { return x > 0; }\r\n};\r\n\r\ntemplate\
    \ <int PRECISION>\r\nclass DoubleValue {\r\n   public:\r\n    using ValueType\
    \ = double;\r\n    constexpr static double EPSILON = pow(10, -PRECISION);\r\n\r\
    \n    static bool greater_than_zero(ValueType x) { return x > EPSILON; }\r\n};\r\
    \n\r\n//\u4E0B\u6807\u4ECE0\u5230N-1\r\n//\u6700\u5C0F\u8D39\u7528\u6700\u5927\
    \u6D41\uFF0C\u6C42\u6700\u5927\u8D39\u7528\u53EA\u9700\u53D6\u76F8\u53CD\u6570\
    \uFF0C\u7ED3\u679C\u53D6\u76F8\u53CD\u6570\u5373\u53EF\u3002\r\ntemplate <typename\
    \ Derived = Network::IntValue<int>>\r\nstruct SPFA {\r\n    using T = typename\
    \ Derived::ValueType;\r\n\r\n   public:\r\n    SPFA(int n, int m = 0) : N(n),\
    \ head(n, -1), pre(n), dis(n), vis(n) {\r\n        edges.reserve(m);\r\n    }\r\
    \n    SPFA() {}\r\n\r\n    void addedge(int u, int v, T cap, T cost) {\r\n   \
    \     edges.push_back(Edge(v, head[u], cap, 0, cost));\r\n        head[u] = int(edges.size()\
    \ - 1);\r\n        edges.push_back(Edge(u, head[v], 0, 0, -cost));\r\n       \
    \ head[v] = int(edges.size() - 1);\r\n    }\r\n\r\n    T minCostMaxflow(int s,\
    \ int t, T& cost) {\r\n        T flow = 0;\r\n        cost = 0;\r\n        while\
    \ (spfa(s, t)) {\r\n            T Min = inf;\r\n            for (int i = pre[t];\
    \ ~i; i = pre[edges[i ^ 1].to]) {\r\n                if (greater_than_zero(Min\
    \ - (edges[i].cap - edges[i].flow))) {\r\n                    Min = edges[i].cap\
    \ - edges[i].flow;\r\n                }\r\n            }\r\n            for (int\
    \ i = pre[t]; ~i; i = pre[edges[i ^ 1].to]) {\r\n                edges[i].flow\
    \ += Min;\r\n                edges[i ^ 1].flow -= Min;\r\n                cost\
    \ += edges[i].cost * Min;\r\n            }\r\n            flow += Min;\r\n   \
    \     }\r\n        return flow;\r\n    }\r\n\r\n   private:\r\n    const T inf\
    \ = numeric_limits<T>::max() / 2;\r\n    struct Edge {\r\n        int to, next;\r\
    \n        T cap, flow, cost;\r\n        Edge(int _to, int _next, T _cap, T _flow,\
    \ T _cost) : to(_to), next(_next), cap(_cap), flow(_flow), cost(_cost) {}\r\n\
    \        Edge() {}\r\n    };\r\n    int N;\r\n    vector<int> head;\r\n    vector<Edge>\
    \ edges;\r\n    vector<T> pre, dis;\r\n    vector<bool> vis;\r\n\r\n    bool spfa(int\
    \ s, int t) {\r\n        queue<int> q;\r\n        for (int i = 0; i < N; i++)\
    \ {\r\n            dis[i] = inf;\r\n            vis[i] = false;\r\n          \
    \  pre[i] = -1;\r\n        }\r\n        dis[s] = 0;\r\n        vis[s] = true;\r\
    \n        q.push(s);\r\n        while (!q.empty()) {\r\n            int u = q.front();\r\
    \n            q.pop();\r\n            vis[u] = false;\r\n            for (int\
    \ i = head[u]; ~i; i = edges[i].next) {\r\n                int v = edges[i].to;\r\
    \n                if (greater_than_zero(edges[i].cap - edges[i].flow) && greater_than_zero(dis[v]\
    \ - (dis[u] + edges[i].cost))) {\r\n                    dis[v] = dis[u] + edges[i].cost;\r\
    \n                    pre[v] = i;\r\n                    if (!vis[v]) {\r\n  \
    \                      vis[v] = true;\r\n                        q.push(v);\r\n\
    \                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        if (pre[t] == -1) return 0;\r\n        return 1;\r\n    }\r\n\r\n   \
    \ static bool greater_than_zero(T x) {\r\n        return Derived::greater_than_zero(x);\r\
    \n    }\r\n};\r\n}  // namespace Network\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief \u6700\
    \u5C0F\u8D39\u7528\u6700\u5927\u6D41\r\n@docs docs/spfa.md\r\n*/\r\n\r\nnamespace\
    \ Network {\r\ntemplate <typename IntType>\r\nclass IntValue {\r\n   public:\r\
    \n    using ValueType = IntType;\r\n\r\n    static bool greater_than_zero(ValueType\
    \ x) { return x > 0; }\r\n};\r\n\r\ntemplate <int PRECISION>\r\nclass DoubleValue\
    \ {\r\n   public:\r\n    using ValueType = double;\r\n    constexpr static double\
    \ EPSILON = pow(10, -PRECISION);\r\n\r\n    static bool greater_than_zero(ValueType\
    \ x) { return x > EPSILON; }\r\n};\r\n\r\n//\u4E0B\u6807\u4ECE0\u5230N-1\r\n//\u6700\
    \u5C0F\u8D39\u7528\u6700\u5927\u6D41\uFF0C\u6C42\u6700\u5927\u8D39\u7528\u53EA\
    \u9700\u53D6\u76F8\u53CD\u6570\uFF0C\u7ED3\u679C\u53D6\u76F8\u53CD\u6570\u5373\
    \u53EF\u3002\r\ntemplate <typename Derived = Network::IntValue<int>>\r\nstruct\
    \ SPFA {\r\n    using T = typename Derived::ValueType;\r\n\r\n   public:\r\n \
    \   SPFA(int n, int m = 0) : N(n), head(n, -1), pre(n), dis(n), vis(n) {\r\n \
    \       edges.reserve(m);\r\n    }\r\n    SPFA() {}\r\n\r\n    void addedge(int\
    \ u, int v, T cap, T cost) {\r\n        edges.push_back(Edge(v, head[u], cap,\
    \ 0, cost));\r\n        head[u] = int(edges.size() - 1);\r\n        edges.push_back(Edge(u,\
    \ head[v], 0, 0, -cost));\r\n        head[v] = int(edges.size() - 1);\r\n    }\r\
    \n\r\n    T minCostMaxflow(int s, int t, T& cost) {\r\n        T flow = 0;\r\n\
    \        cost = 0;\r\n        while (spfa(s, t)) {\r\n            T Min = inf;\r\
    \n            for (int i = pre[t]; ~i; i = pre[edges[i ^ 1].to]) {\r\n       \
    \         if (greater_than_zero(Min - (edges[i].cap - edges[i].flow))) {\r\n \
    \                   Min = edges[i].cap - edges[i].flow;\r\n                }\r\
    \n            }\r\n            for (int i = pre[t]; ~i; i = pre[edges[i ^ 1].to])\
    \ {\r\n                edges[i].flow += Min;\r\n                edges[i ^ 1].flow\
    \ -= Min;\r\n                cost += edges[i].cost * Min;\r\n            }\r\n\
    \            flow += Min;\r\n        }\r\n        return flow;\r\n    }\r\n\r\n\
    \   private:\r\n    const T inf = numeric_limits<T>::max() / 2;\r\n    struct\
    \ Edge {\r\n        int to, next;\r\n        T cap, flow, cost;\r\n        Edge(int\
    \ _to, int _next, T _cap, T _flow, T _cost) : to(_to), next(_next), cap(_cap),\
    \ flow(_flow), cost(_cost) {}\r\n        Edge() {}\r\n    };\r\n    int N;\r\n\
    \    vector<int> head;\r\n    vector<Edge> edges;\r\n    vector<T> pre, dis;\r\
    \n    vector<bool> vis;\r\n\r\n    bool spfa(int s, int t) {\r\n        queue<int>\
    \ q;\r\n        for (int i = 0; i < N; i++) {\r\n            dis[i] = inf;\r\n\
    \            vis[i] = false;\r\n            pre[i] = -1;\r\n        }\r\n    \
    \    dis[s] = 0;\r\n        vis[s] = true;\r\n        q.push(s);\r\n        while\
    \ (!q.empty()) {\r\n            int u = q.front();\r\n            q.pop();\r\n\
    \            vis[u] = false;\r\n            for (int i = head[u]; ~i; i = edges[i].next)\
    \ {\r\n                int v = edges[i].to;\r\n                if (greater_than_zero(edges[i].cap\
    \ - edges[i].flow) && greater_than_zero(dis[v] - (dis[u] + edges[i].cost))) {\r\
    \n                    dis[v] = dis[u] + edges[i].cost;\r\n                   \
    \ pre[v] = i;\r\n                    if (!vis[v]) {\r\n                      \
    \  vis[v] = true;\r\n                        q.push(v);\r\n                  \
    \  }\r\n                }\r\n            }\r\n        }\r\n        if (pre[t]\
    \ == -1) return 0;\r\n        return 1;\r\n    }\r\n\r\n    static bool greater_than_zero(T\
    \ x) {\r\n        return Derived::greater_than_zero(x);\r\n    }\r\n};\r\n}  //\
    \ namespace Network"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/spfa.h
  requiredBy: []
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/spfa.h
layout: document
redirect_from:
- /library/src/graph/spfa.h
- /library/src/graph/spfa.h.html
title: "\u6700\u5C0F\u8D39\u7528\u6700\u5927\u6D41"
---
# SOS DP

## 概要


## 常见问题

## 题集
