---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/tarjan.md
    document_title: Tarjan
    links: []
  bundledCode: "#line 1 \"src/graph/tarjan.h\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n/*\r\n@brief Tarjan\r\n@docs docs/tarjan.md\r\ntodo: \u5F85\
    \u6574\u7406\r\n*/\r\n\r\n// todo: \u5F85\u6574\u7406\r\n//\u8FB9\u4ECE0\u5230\
    tot-1\uFF0C\u70B9\u4ECE1\u5230N\r\n//\u5982\u679C\u6709\u91CD\u8FB9\u7684\u8BDD\
    \uFF0C\u5728tarjan\u51FD\u6570\u81EA\u5DF1\u52A0\u4E0A\u5224\u65AD\u51FD\u6570\
    \u5373\u53EF\u3002\r\n//\u4E0D\u7BA1\u662F\u6709\u5411\u56FE\u8FD8\u662F\u65E0\
    \u5411\u56FE\uFF0CLOW\u6570\u7EC4\u90FD\u4E0D\u80FD\u4EE3\u8868\u70B9\u6240\u5728\
    \u7684\u8FDE\u901A\u5206\u91CF\u3002\r\nconst int maxn = 1e5;\r\nconst int maxm\
    \ = 1e5 + 5;\r\nstruct Edge {\r\n    int u, v, next;\r\n    Edge(int _u, int _v,\
    \ int _nxt) : u(_u), v(_v), next(_nxt) {}\r\n    Edge() {}\r\n} edges[maxm * 2];\r\
    \nint head[maxn], tot;\r\nvoid addedge(int u, int v) {\r\n    edges[tot] = Edge(u,\
    \ v, head[u]);\r\n    head[u] = tot++;\r\n}\r\nint DFN[maxn], LOW[maxn], id;\r\
    \nint stk[maxn], tot1;\r\nbool is_cut[maxn];\r\nvector<vector<int>> dcc;\r\nvoid\
    \ tarjan(int u) {\r\n    DFN[u] = LOW[u] = ++id;\r\n    stk[tot1++] = u;\r\n \
    \   int flag = 0;\r\n    for (int i = head[u]; ~i; i = edges[i].next) {\r\n  \
    \      int v = edges[i].v;\r\n        if (!DFN[v]) {\r\n            tarjan(v);\r\
    \n            LOW[u] = min(LOW[u], LOW[v]);\r\n            if (LOW[v] == DFN[u])\
    \ {\r\n                flag++;\r\n                if (u != 1 || flag > 1) is_cut[u]\
    \ = true;\r\n                int t;\r\n                dcc.push_back({});\r\n\
    \                do {\r\n                    t = stk[tot1 - 1];\r\n          \
    \          tot1--;\r\n                    dcc.back().push_back(t);\r\n       \
    \         } while (t != v);\r\n                dcc.back().push_back(u);\r\n  \
    \          }\r\n        } else {\r\n            LOW[u] = min(LOW[u], DFN[v]);\r\
    \n        }\r\n    }\r\n}\r\nvoid init() {\r\n    id = 0;\r\n    tot = 0;\r\n\
    \    memset(head, -1, sizeof(head));\r\n    memset(DFN, 0, sizeof(DFN));\r\n \
    \   memset(LOW, 0, sizeof(LOW));\r\n    memset(is_cut, 0, sizeof(is_cut));\r\n\
    \    dcc.clear();\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Tarjan\r\
    \n@docs docs/tarjan.md\r\ntodo: \u5F85\u6574\u7406\r\n*/\r\n\r\n// todo: \u5F85\
    \u6574\u7406\r\n//\u8FB9\u4ECE0\u5230tot-1\uFF0C\u70B9\u4ECE1\u5230N\r\n//\u5982\
    \u679C\u6709\u91CD\u8FB9\u7684\u8BDD\uFF0C\u5728tarjan\u51FD\u6570\u81EA\u5DF1\
    \u52A0\u4E0A\u5224\u65AD\u51FD\u6570\u5373\u53EF\u3002\r\n//\u4E0D\u7BA1\u662F\
    \u6709\u5411\u56FE\u8FD8\u662F\u65E0\u5411\u56FE\uFF0CLOW\u6570\u7EC4\u90FD\u4E0D\
    \u80FD\u4EE3\u8868\u70B9\u6240\u5728\u7684\u8FDE\u901A\u5206\u91CF\u3002\r\nconst\
    \ int maxn = 1e5;\r\nconst int maxm = 1e5 + 5;\r\nstruct Edge {\r\n    int u,\
    \ v, next;\r\n    Edge(int _u, int _v, int _nxt) : u(_u), v(_v), next(_nxt) {}\r\
    \n    Edge() {}\r\n} edges[maxm * 2];\r\nint head[maxn], tot;\r\nvoid addedge(int\
    \ u, int v) {\r\n    edges[tot] = Edge(u, v, head[u]);\r\n    head[u] = tot++;\r\
    \n}\r\nint DFN[maxn], LOW[maxn], id;\r\nint stk[maxn], tot1;\r\nbool is_cut[maxn];\r\
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
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tarjan.h
  requiredBy: []
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/tarjan.h
layout: document
redirect_from:
- /library/src/graph/tarjan.h
- /library/src/graph/tarjan.h.html
title: Tarjan
---
