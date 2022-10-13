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
    _deprecated_at_docs: docs/tarjan.md
    document_title: Tarjan
    links: []
  bundledCode: "#line 1 \"src/graph/tarjan.hpp\"\n#include <bits/stdc++.h>\r\n\r\n\
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
    \   }\r\n};\n#line 4 \"src/graph/tarjan.hpp\"\nusing namespace std;\r\n/*\r\n\
    @brief Tarjan\r\n@docs docs/tarjan.md\r\ntodo: \u5F85\u6574\u7406\r\n*/\r\n\r\n\
    // template <typename T = int>\r\n// struct Tarjan : Graph<T> {\r\n//     vector<int>\
    \ low, dfn, stk;\r\n//     vector<bool> in_stk;\r\n//     int timestamp, scc_cnt;\r\
    \n\r\n//     Tarjan() = default;\r\n//     explicit Tarjan(int n) : Graph<T>(n),\
    \ low(n), dfn(n), in_stk(n), timestamp(0), scc_cnt(0) {}\r\n\r\n//     void dfs(int\
    \ u) {\r\n//         low[u] = dfn[u] = ++timestamp;\r\n//         stk.push_back(u);\r\
    \n//         in_stk[u] = true;\r\n\r\n//         int flag = 0;\r\n//         for\
    \ (auto& e : this->g[u]) {\r\n//             int v = e.to;\r\n//             if\
    \ (!dfn[v]) {\r\n//                 dfs(v);\r\n//                 low[u] = min(low[u],\
    \ low[v]);\r\n\r\n//                 if (low[v] == dfn[u]) {\r\n//           \
    \          flag++;\r\n//                     if (u !=)\r\n//                 }\r\
    \n\r\n//             } else if (in_stk[v]) {\r\n//                 low[u] = min(low[u],\
    \ dfn[v]);\r\n//             }\r\n//         }\r\n\r\n//         if (low[u] ==\
    \ dfn[u]) {\r\n//             scc_cnt++;\r\n//             while (true) {\r\n\
    //                 int x = stk.back();\r\n//                 stk.pop_back();\r\
    \n//                 in_stk[x] = false;\r\n//                 if (x == u) {\r\n\
    //                     break;\r\n//                 }\r\n//             }\r\n\
    //         }\r\n//     }\r\n\r\n//     void solve() {\r\n//         for (int i\
    \ = 0; i < this->g.size(); i++) {\r\n//             if (!dfn[i]) {\r\n//     \
    \            dfs(i);\r\n//             }\r\n//         }\r\n//     }\r\n// };\r\
    \n\r\n//\u8FB9\u4ECE0\u5230tot-1\uFF0C\u70B9\u4ECE1\u5230N\r\n//\u5982\u679C\u6709\
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
  timestamp: '2022-10-12 22:34:49+08:00'
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