---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/graph/dijkstra.test.cpp: line 9: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\r\n#include\
    \ \"src/graph/dijkstra.hpp\"\r\n\r\n#include <bits/stdc++.h>\r\n\r\nusing namespace\
    \ std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\r\n#else\r\n#define\
    \ debug(...) 42\r\n#endif\r\n\r\n#define endl '\\n'\r\ntypedef long long ll;\r\
    \ntypedef pair<int, int> pii;\r\ntypedef pair<ll, ll> pll;\r\n\r\nstruct fast_ios\
    \ {\r\n    fast_ios() {\r\n        cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\
    \n        cout << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\nstruct\
    \ MyEdge {\r\n    int from, to;\r\n    ll cost;\r\n\r\n    MyEdge() = default;\r\
    \n    MyEdge(int from, int to, ll cost = 1) : from(from), to(to), cost(cost) {}\r\
    \n\r\n    // Edge e = Edge(); int to = e;\r\n    operator int() const { return\
    \ to; }\r\n};\r\n\r\nint main() {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\"\
    , \"r\", stdin);\r\n#endif\r\n\r\n    int n, m, s, t;\r\n    cin >> n >> m >>\
    \ s >> t;\r\n    Graph<MyEdge> g(n);\r\n\r\n    for (int i = 0; i < m; i++) {\r\
    \n        int a, b, c;\r\n        cin >> a >> b >> c;\r\n        g.add_directed_edge(MyEdge(a,\
    \ b, c));\r\n    }\r\n\r\n    Dijkstra<Graph<MyEdge>, ll> dijkstra(g);\r\n\r\n\
    \    dijkstra.dijkstra(s);\r\n\r\n    if (dijkstra.dist[t] == dijkstra.inf) {\r\
    \n        cout << -1 << endl;\r\n    } else {\r\n        debug(dijkstra.dist,\
    \ dijkstra.num);\r\n        int now = t;\r\n        vector<pii> ans;\r\n     \
    \   while (now != s) {\r\n            int prev = dijkstra.prev[now];\r\n     \
    \       ans.emplace_back(prev, now);\r\n            now = prev;\r\n        }\r\
    \n        cout << dijkstra.dist[t] << ' ' << ans.size() << endl;\r\n        reverse(ans.begin(),\
    \ ans.end());\r\n        for (auto [a, b] : ans) {\r\n            cout << a <<\
    \ \" \" << b << endl;\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: true
  path: test/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-10-12 22:34:49+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.test.cpp
- /verify/test/graph/dijkstra.test.cpp.html
title: test/graph/dijkstra.test.cpp
---
