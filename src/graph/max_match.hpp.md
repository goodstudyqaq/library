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
    _deprecated_at_docs: docs/max_match.md
    document_title: "\u6700\u5927\u5339\u914D"
    links: []
  bundledCode: "#line 1 \"src/graph/max_match.hpp\"\n#include <bits/stdc++.h>\r\n\r\
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
    \uFF0C\u6C42\u5B50\u6811\u5927\u5C0F\u7B49\r\n};\r\n#line 4 \"src/graph/max_match.hpp\"\
    \nusing namespace std;\r\n/*\r\n@brief \u6700\u5927\u5339\u914D\r\n@docs docs/max_match.md\r\
    \ntodo: \u5224\u65AD\u662F\u5426\u662F\u4E8C\u5206\u56FE\uFF0C\u5982\u679C\u4E0D\
    \u662F\u4E8C\u5206\u56FE\uFF0C\u9700\u8981\u62A5\u9519\r\n*/\r\ntemplate <typename\
    \ T = int>\r\nstruct Hungary : Graph<T> {\r\n    vector<int> cx, cy;\r\n    vector<bool>\
    \ used;\r\n    int count;\r\n\r\n    bool dfs(int u) {\r\n        for (auto v\
    \ : g[u]) {\r\n            if (!used[v]) {\r\n                used[v] = 1;\r\n\
    \                if (cy[v] == -1 || dfs(cy[v])) {\r\n                    cy[v]\
    \ = u;\r\n                    cx[u] = v;\r\n                    return 1;\r\n\
    \                }\r\n            }\r\n        }\r\n        return 0;\r\n    }\r\
    \n\r\n    void hungary() {\r\n        // \u9700\u8981\u4FDD\u8BC1 graph \u4E3A\
    \u4E8C\u5206\u56FE\r\n        int n = g.size();\r\n        cx.resize(n);\r\n \
    \       cy.reserve(n);\r\n        used.resize(n);\r\n        for (int i = 0; i\
    \ < n; i++) {\r\n            cx[i] = cy[i] = -1;\r\n            used[i] = 0;\r\
    \n        }\r\n        int res = 0;\r\n        for (int u = 0; u < n; u++) {\r\
    \n            if (cx[u] == -1) {\r\n                for (int i = 0; i < n; i++)\
    \ used[i] = 0;\r\n                if (dfs(u)) res++;\r\n            }\r\n    \
    \    }\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"src/graph/graph_template.hpp\"\
    \r\nusing namespace std;\r\n/*\r\n@brief \u6700\u5927\u5339\u914D\r\n@docs docs/max_match.md\r\
    \ntodo: \u5224\u65AD\u662F\u5426\u662F\u4E8C\u5206\u56FE\uFF0C\u5982\u679C\u4E0D\
    \u662F\u4E8C\u5206\u56FE\uFF0C\u9700\u8981\u62A5\u9519\r\n*/\r\ntemplate <typename\
    \ T = int>\r\nstruct Hungary : Graph<T> {\r\n    vector<int> cx, cy;\r\n    vector<bool>\
    \ used;\r\n    int count;\r\n\r\n    bool dfs(int u) {\r\n        for (auto v\
    \ : g[u]) {\r\n            if (!used[v]) {\r\n                used[v] = 1;\r\n\
    \                if (cy[v] == -1 || dfs(cy[v])) {\r\n                    cy[v]\
    \ = u;\r\n                    cx[u] = v;\r\n                    return 1;\r\n\
    \                }\r\n            }\r\n        }\r\n        return 0;\r\n    }\r\
    \n\r\n    void hungary() {\r\n        // \u9700\u8981\u4FDD\u8BC1 graph \u4E3A\
    \u4E8C\u5206\u56FE\r\n        int n = g.size();\r\n        cx.resize(n);\r\n \
    \       cy.reserve(n);\r\n        used.resize(n);\r\n        for (int i = 0; i\
    \ < n; i++) {\r\n            cx[i] = cy[i] = -1;\r\n            used[i] = 0;\r\
    \n        }\r\n        int res = 0;\r\n        for (int u = 0; u < n; u++) {\r\
    \n            if (cx[u] == -1) {\r\n                for (int i = 0; i < n; i++)\
    \ used[i] = 0;\r\n                if (dfs(u)) res++;\r\n            }\r\n    \
    \    }\r\n    }\r\n};"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/max_match.hpp
  requiredBy: []
  timestamp: '2022-10-12 21:42:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/max_match.hpp
layout: document
redirect_from:
- /library/src/graph/max_match.hpp
- /library/src/graph/max_match.hpp.html
title: "\u6700\u5927\u5339\u914D"
---
# 最大匹配

## 概要
二分图最大匹配 Hungary 算法, 时间复杂度 $O(n^3)$
### `Hungary`
`Hungary` 为二分图最大匹配的主体,继承自 `Graph` 类。在使用时需保证图为二分图,否则会出现错误。主要有以下几个方法:
- `void hungary()` : 构造二分图最大匹配



## 常见问题

## 题集
h