---
data:
  _extendedDependsOn: []
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
    using namespace std;\r\n/*\r\n@brief \u6700\u77ED\u8DEF\r\n@docs docs/shortest_path.md\r\
    \n*/\r\n\r\n/*\r\n\u5957\u8DEF\u9898\uFF1A\u4E8C\u8FDB\u5236\u5224\u4E0D\u540C\
    \u8272\u6700\u77ED\u8DEF or \u6B21\u77ED\u8DEF\u3002https://atcoder.jp/contests/abc245/tasks/abc245_g\r\
    \n\u6B21\u77ED\u8DEF\u505A\u6CD5\uFF1A\u518D\u52A0\u4E00\u4E2A\u8DDD\u79BB\u6570\
    \u7EC4 dis2, \u5177\u4F53\u770B\uFF1Ahttps://atcoder.jp/contests/abc245/submissions/32661509\r\
    \n*/\r\n\r\n// \u4E00\u822C\u5F62\u5F0F\u7684 dijkstra\r\nstruct NormalDijkstra\
    \ {\r\n    // \u4E0B\u6807\u4ECE 1 \u5230 n\r\n    vector<vector<int>> Map;  //\
    \ \u56FE Map[i][j] = dis\r\n    vector<bool> vis;\r\n    vector<int> d;\r\n  \
    \  const int inf = 0x3f3f3f3f;\r\n\r\n    void dijkstra(int s, int n) {\r\n  \
    \      // O(n ^ 2)\r\n        vis.clear(), vis.resize(n + 1, 0);\r\n        d.clear(),\
    \ d.resize(n + 1, inf);\r\n        d[s] = 0;\r\n        for (int i = 0; i < n;\
    \ i++) {\r\n            int x, m = inf;\r\n            for (int y = 1; y <= n;\
    \ y++) {\r\n                if (!vis[y] && d[y] <= m) {\r\n                  \
    \  m = d[x = y];\r\n                }\r\n            }\r\n            vis[x] =\
    \ 1;\r\n            for (int y = 1; y <= n; y++) {\r\n                d[y] = min(d[y],\
    \ d[x] + Map[x][y]);\r\n            }\r\n        }\r\n    }\r\n};\r\n\r\n// \u6700\
    \u77ED\u8DEF\r\n// \u590D\u6742\u5EA6 O(mlogn) m <= n ^ 2, \u9002\u5408\u7A00\u758F\
    \u56FE, \u5982\u679C m \u5F88\u591A\u5219\u6BD4\u666E\u901A\u7684 dijkstra \u66F4\
    \u6162\r\nnamespace ShortestPath {\r\ntypedef long long ll;\r\ntypedef pair<int,\
    \ int> pii;\r\ntypedef pair<ll, int> pli;\r\npriority_queue<pli, vector<pli>,\
    \ greater<pli>> Q;\r\nvector<bool> vis;\r\nvector<ll> dis;\r\nconst ll inf = numeric_limits<ll>::max()\
    \ / 2;\r\nvoid dijkstra(int n, vector<int>& valid, vector<vector<pii>>& V) {\r\
    \n    vis.resize(n + 1);\r\n    dis.resize(n + 1);\r\n    for (int i = 1; i <=\
    \ n; i++) {\r\n        vis[i] = 0;\r\n        dis[i] = inf;\r\n    }\r\n    while\
    \ (!Q.empty()) Q.pop();\r\n\r\n    for (auto it : valid) {\r\n        dis[it]\
    \ = 0;\r\n        Q.push({dis[it], it});\r\n    }\r\n\r\n    while (!Q.empty())\
    \ {\r\n        auto it = Q.top();\r\n        Q.pop();\r\n        if (vis[it.second])\
    \ continue;\r\n        vis[it.second] = true;\r\n        for (auto v : V[it.second])\
    \ {\r\n            if (dis[v.first] > it.first + v.second) {\r\n             \
    \   dis[v.first] = it.first + v.second;\r\n                Q.push({dis[v.first],\
    \ v.first});\r\n            }\r\n        }\r\n    }\r\n}\r\n}  // namespace ShortestPath\r\
    \n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u6700\u77ED\
    \u8DEF\r\n@docs docs/shortest_path.md\r\n*/\r\n\r\n/*\r\n\u5957\u8DEF\u9898\uFF1A\
    \u4E8C\u8FDB\u5236\u5224\u4E0D\u540C\u8272\u6700\u77ED\u8DEF or \u6B21\u77ED\u8DEF\
    \u3002https://atcoder.jp/contests/abc245/tasks/abc245_g\r\n\u6B21\u77ED\u8DEF\u505A\
    \u6CD5\uFF1A\u518D\u52A0\u4E00\u4E2A\u8DDD\u79BB\u6570\u7EC4 dis2, \u5177\u4F53\
    \u770B\uFF1Ahttps://atcoder.jp/contests/abc245/submissions/32661509\r\n*/\r\n\r\
    \n// \u4E00\u822C\u5F62\u5F0F\u7684 dijkstra\r\nstruct NormalDijkstra {\r\n  \
    \  // \u4E0B\u6807\u4ECE 1 \u5230 n\r\n    vector<vector<int>> Map;  // \u56FE\
    \ Map[i][j] = dis\r\n    vector<bool> vis;\r\n    vector<int> d;\r\n    const\
    \ int inf = 0x3f3f3f3f;\r\n\r\n    void dijkstra(int s, int n) {\r\n        //\
    \ O(n ^ 2)\r\n        vis.clear(), vis.resize(n + 1, 0);\r\n        d.clear(),\
    \ d.resize(n + 1, inf);\r\n        d[s] = 0;\r\n        for (int i = 0; i < n;\
    \ i++) {\r\n            int x, m = inf;\r\n            for (int y = 1; y <= n;\
    \ y++) {\r\n                if (!vis[y] && d[y] <= m) {\r\n                  \
    \  m = d[x = y];\r\n                }\r\n            }\r\n            vis[x] =\
    \ 1;\r\n            for (int y = 1; y <= n; y++) {\r\n                d[y] = min(d[y],\
    \ d[x] + Map[x][y]);\r\n            }\r\n        }\r\n    }\r\n};\r\n\r\n// \u6700\
    \u77ED\u8DEF\r\n// \u590D\u6742\u5EA6 O(mlogn) m <= n ^ 2, \u9002\u5408\u7A00\u758F\
    \u56FE, \u5982\u679C m \u5F88\u591A\u5219\u6BD4\u666E\u901A\u7684 dijkstra \u66F4\
    \u6162\r\nnamespace ShortestPath {\r\ntypedef long long ll;\r\ntypedef pair<int,\
    \ int> pii;\r\ntypedef pair<ll, int> pli;\r\npriority_queue<pli, vector<pli>,\
    \ greater<pli>> Q;\r\nvector<bool> vis;\r\nvector<ll> dis;\r\nconst ll inf = numeric_limits<ll>::max()\
    \ / 2;\r\nvoid dijkstra(int n, vector<int>& valid, vector<vector<pii>>& V) {\r\
    \n    vis.resize(n + 1);\r\n    dis.resize(n + 1);\r\n    for (int i = 1; i <=\
    \ n; i++) {\r\n        vis[i] = 0;\r\n        dis[i] = inf;\r\n    }\r\n    while\
    \ (!Q.empty()) Q.pop();\r\n\r\n    for (auto it : valid) {\r\n        dis[it]\
    \ = 0;\r\n        Q.push({dis[it], it});\r\n    }\r\n\r\n    while (!Q.empty())\
    \ {\r\n        auto it = Q.top();\r\n        Q.pop();\r\n        if (vis[it.second])\
    \ continue;\r\n        vis[it.second] = true;\r\n        for (auto v : V[it.second])\
    \ {\r\n            if (dis[v.first] > it.first + v.second) {\r\n             \
    \   dis[v.first] = it.first + v.second;\r\n                Q.push({dis[v.first],\
    \ v.first});\r\n            }\r\n        }\r\n    }\r\n}\r\n}  // namespace ShortestPath\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/shortest_path.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/shortest_path.h
layout: document
redirect_from:
- /library/src/graph/shortest_path.h
- /library/src/graph/shortest_path.h.html
title: "\u6700\u77ED\u8DEF"
---
