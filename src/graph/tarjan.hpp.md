---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/graph_template.hpp
    title: "\u5E26\u6743\u5E76\u67E5\u96C6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/tarjan.md
    document_title: Tarjan
    links: []
  bundledCode: "#line 1 \"src/graph/tarjan.hpp\"\n#include <bits/stdc++.h>\r\n\r\n\
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
    \ T = int>\r\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/tarjan.hpp\"\
    \nusing namespace std;\r\n/*\r\n@brief Tarjan\r\n@docs docs/tarjan.md\r\ntodo:\
    \ \u5F85\u6574\u7406\r\n*/\r\n\r\n// template <typename T = int>\r\n// struct\
    \ Tarjan : Graph<T> {\r\n//     vector<int> low, dfn, stk;\r\n//     vector<bool>\
    \ in_stk;\r\n//     int timestamp, scc_cnt;\r\n\r\n//     Tarjan() = default;\r\
    \n//     explicit Tarjan(int n) : Graph<T>(n), low(n), dfn(n), in_stk(n), timestamp(0),\
    \ scc_cnt(0) {}\r\n\r\n//     void dfs(int u) {\r\n//         low[u] = dfn[u]\
    \ = ++timestamp;\r\n//         stk.push_back(u);\r\n//         in_stk[u] = true;\r\
    \n\r\n//         int flag = 0;\r\n//         for (auto& e : this->g[u]) {\r\n\
    //             int v = e.to;\r\n//             if (!dfn[v]) {\r\n//          \
    \       dfs(v);\r\n//                 low[u] = min(low[u], low[v]);\r\n\r\n//\
    \                 if (low[v] == dfn[u]) {\r\n//                     flag++;\r\n\
    //                     if (u !=)\r\n//                 }\r\n\r\n//           \
    \  } else if (in_stk[v]) {\r\n//                 low[u] = min(low[u], dfn[v]);\r\
    \n//             }\r\n//         }\r\n\r\n//         if (low[u] == dfn[u]) {\r\
    \n//             scc_cnt++;\r\n//             while (true) {\r\n//           \
    \      int x = stk.back();\r\n//                 stk.pop_back();\r\n//       \
    \          in_stk[x] = false;\r\n//                 if (x == u) {\r\n//      \
    \               break;\r\n//                 }\r\n//             }\r\n//     \
    \    }\r\n//     }\r\n\r\n//     void solve() {\r\n//         for (int i = 0;\
    \ i < this->g.size(); i++) {\r\n//             if (!dfn[i]) {\r\n//          \
    \       dfs(i);\r\n//             }\r\n//         }\r\n//     }\r\n// };\r\n\r\
    \n//\u8FB9\u4ECE0\u5230tot-1\uFF0C\u70B9\u4ECE1\u5230N\r\n//\u5982\u679C\u6709\
    \u91CD\u8FB9\u7684\u8BDD\uFF0C\u5728tarjan\u51FD\u6570\u81EA\u5DF1\u52A0\u4E0A\
    \u5224\u65AD\u51FD\u6570\u5373\u53EF\u3002\r\n//\u4E0D\u7BA1\u662F\u6709\u5411\
    \u56FE\u8FD8\u662F\u65E0\u5411\u56FE\uFF0CLOW\u6570\u7EC4\u90FD\u4E0D\u80FD\u4EE3\
    \u8868\u70B9\u6240\u5728\u7684\u8FDE\u901A\u5206\u91CF\u3002\r\nconst int maxn\
    \ = 1e5;\r\nconst int maxm = 1e5 + 5;\r\nstruct Edge {\r\n    int u, v, next;\r\
    \n    Edge(int _u, int _v, int _nxt) : u(_u), v(_v), next(_nxt) {}\r\n    Edge()\
    \ {}\r\n} edges[maxm * 2];\r\nint head[maxn], tot;\r\nvoid addedge(int u, int\
    \ v) {\r\n    edges[tot] = Edge(u, v, head[u]);\r\n    head[u] = tot++;\r\n}\r\
    \nint DFN[maxn], LOW[maxn], id;\r\nint stk[maxn], tot1;\r\nbool is_cut[maxn];\r\
    \nvector<vector<int>> dcc;\r\nvoid tarjan(int u) {\r\n    DFN[u] = LOW[u] = ++id;\r\
    \n    stk[tot1++] = u;\r\n    int flag = 0;\r\n    for (int i = head[u]; ~i; i\
    \ = edges[i].next) {\r\n        int v = edges[i].v;\r\n        if (!DFN[v]) {\r\
    \n            tarjan(v);\r\n            LOW[u] = min(LOW[u], LOW[v]);\r\n    \
    \        if (LOW[v] == DFN[u]) {\r\n                flag++;\r\n              \
    \  if (u != 1 || flag > 1) is_cut[u] = true;\r\n                int t;\r\n   \
    \             dcc.push_back({});\r\n                do {\r\n                 \
    \   t = stk[tot1 - 1];\r\n                    tot1--;\r\n                    dcc.back().push_back(t);\r\
    \n                } while (t != v);\r\n                dcc.back().push_back(u);\r\
    \n            }\r\n        } else {\r\n            LOW[u] = min(LOW[u], DFN[v]);\r\
    \n        }\r\n    }\r\n}\r\nvoid init() {\r\n    id = 0;\r\n    tot = 0;\r\n\
    \    memset(head, -1, sizeof(head));\r\n    memset(DFN, 0, sizeof(DFN));\r\n \
    \   memset(LOW, 0, sizeof(LOW));\r\n    memset(is_cut, 0, sizeof(is_cut));\r\n\
    \    dcc.clear();\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief Tarjan\r\n@docs docs/tarjan.md\r\ntodo:\
    \ \u5F85\u6574\u7406\r\n*/\r\n\r\n// template <typename T = int>\r\n// struct\
    \ Tarjan : Graph<T> {\r\n//     vector<int> low, dfn, stk;\r\n//     vector<bool>\
    \ in_stk;\r\n//     int timestamp, scc_cnt;\r\n\r\n//     Tarjan() = default;\r\
    \n//     explicit Tarjan(int n) : Graph<T>(n), low(n), dfn(n), in_stk(n), timestamp(0),\
    \ scc_cnt(0) {}\r\n\r\n//     void dfs(int u) {\r\n//         low[u] = dfn[u]\
    \ = ++timestamp;\r\n//         stk.push_back(u);\r\n//         in_stk[u] = true;\r\
    \n\r\n//         int flag = 0;\r\n//         for (auto& e : this->g[u]) {\r\n\
    //             int v = e.to;\r\n//             if (!dfn[v]) {\r\n//          \
    \       dfs(v);\r\n//                 low[u] = min(low[u], low[v]);\r\n\r\n//\
    \                 if (low[v] == dfn[u]) {\r\n//                     flag++;\r\n\
    //                     if (u !=)\r\n//                 }\r\n\r\n//           \
    \  } else if (in_stk[v]) {\r\n//                 low[u] = min(low[u], dfn[v]);\r\
    \n//             }\r\n//         }\r\n\r\n//         if (low[u] == dfn[u]) {\r\
    \n//             scc_cnt++;\r\n//             while (true) {\r\n//           \
    \      int x = stk.back();\r\n//                 stk.pop_back();\r\n//       \
    \          in_stk[x] = false;\r\n//                 if (x == u) {\r\n//      \
    \               break;\r\n//                 }\r\n//             }\r\n//     \
    \    }\r\n//     }\r\n\r\n//     void solve() {\r\n//         for (int i = 0;\
    \ i < this->g.size(); i++) {\r\n//             if (!dfn[i]) {\r\n//          \
    \       dfs(i);\r\n//             }\r\n//         }\r\n//     }\r\n// };\r\n\r\
    \n//\u8FB9\u4ECE0\u5230tot-1\uFF0C\u70B9\u4ECE1\u5230N\r\n//\u5982\u679C\u6709\
    \u91CD\u8FB9\u7684\u8BDD\uFF0C\u5728tarjan\u51FD\u6570\u81EA\u5DF1\u52A0\u4E0A\
    \u5224\u65AD\u51FD\u6570\u5373\u53EF\u3002\r\n//\u4E0D\u7BA1\u662F\u6709\u5411\
    \u56FE\u8FD8\u662F\u65E0\u5411\u56FE\uFF0CLOW\u6570\u7EC4\u90FD\u4E0D\u80FD\u4EE3\
    \u8868\u70B9\u6240\u5728\u7684\u8FDE\u901A\u5206\u91CF\u3002\r\nconst int maxn\
    \ = 1e5;\r\nconst int maxm = 1e5 + 5;\r\nstruct Edge {\r\n    int u, v, next;\r\
    \n    Edge(int _u, int _v, int _nxt) : u(_u), v(_v), next(_nxt) {}\r\n    Edge()\
    \ {}\r\n} edges[maxm * 2];\r\nint head[maxn], tot;\r\nvoid addedge(int u, int\
    \ v) {\r\n    edges[tot] = Edge(u, v, head[u]);\r\n    head[u] = tot++;\r\n}\r\
    \nint DFN[maxn], LOW[maxn], id;\r\nint stk[maxn], tot1;\r\nbool is_cut[maxn];\r\
    \nvector<vector<int>> dcc;\r\nvoid tarjan(int u) {\r\n    DFN[u] = LOW[u] = ++id;\r\
    \n    stk[tot1++] = u;\r\n    int flag = 0;\r\n    for (int i = head[u]; ~i; i\
    \ = edges[i].next) {\r\n        int v = edges[i].v;\r\n        if (!DFN[v]) {\r\
    \n            tarjan(v);\r\n            LOW[u] = min(LOW[u], LOW[v]);\r\n    \
    \        if (LOW[v] == DFN[u]) {\r\n                flag++;\r\n              \
    \  if (u != 1 || flag > 1) is_cut[u] = true;\r\n                int t;\r\n   \
    \             dcc.push_back({});\r\n                do {\r\n                 \
    \   t = stk[tot1 - 1];\r\n                    tot1--;\r\n                    dcc.back().push_back(t);\r\
    \n                } while (t != v);\r\n                dcc.back().push_back(u);\r\
    \n            }\r\n        } else {\r\n            LOW[u] = min(LOW[u], DFN[v]);\r\
    \n        }\r\n    }\r\n}\r\nvoid init() {\r\n    id = 0;\r\n    tot = 0;\r\n\
    \    memset(head, -1, sizeof(head));\r\n    memset(DFN, 0, sizeof(DFN));\r\n \
    \   memset(LOW, 0, sizeof(LOW));\r\n    memset(is_cut, 0, sizeof(is_cut));\r\n\
    \    dcc.clear();\r\n}"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/tarjan.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/tarjan.hpp
layout: document
redirect_from:
- /library/src/graph/tarjan.hpp
- /library/src/graph/tarjan.hpp.html
title: Tarjan
---
# Tarjan

## 概要


## 常见问题

## 题集