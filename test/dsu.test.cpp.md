---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/dsu.hpp
    title: "\u5E76\u67E5\u96C6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \r\n\r\n#line 1 \"src/data_structure/dsu.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n/*\r\n@brief \u5E76\u67E5\u96C6\r\n@docs docs/dsu.md\r\n*/\r\
    \nstruct DSU {\r\n    std::vector<int> f;\r\n    DSU(int n) : f(n) { std::iota(f.begin(),\
    \ f.end(), 0); }\r\n    int leader(int x) {\r\n        if (f[x] == x) {\r\n  \
    \          return x;\r\n        }\r\n        int y = leader(f[x]);\r\n       \
    \ f[x] = y;\r\n        return f[x];\r\n    }\r\n    bool merge(int a, int b) {\r\
    \n        auto x = leader(a);\r\n        auto y = leader(b);\r\n        if (x\
    \ == y) {\r\n            return false;\r\n        }\r\n        f[x] = y;\r\n \
    \       return true;\r\n    }\r\n};\n#line 4 \"test/dsu.test.cpp\"\n\r\n#line\
    \ 6 \"test/dsu.test.cpp\"\nusing namespace std;\r\n\r\n#ifdef LOCAL\r\n#else\r\
    \n#define debug(...) 42\r\n#endif\r\n\r\n#define endl '\\n'\r\ntypedef long long\
    \ ll;\r\ntypedef pair<int, int> pii;\r\ntypedef pair<ll, ll> pll;\r\n\r\nstruct\
    \ fast_ios {\r\n    fast_ios() {\r\n        cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\
    \n        cout << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\n\r\n\
    int main() {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\n\
    #endif\r\n    int n, q;\r\n    cin >> n >> q;\r\n\r\n    DSU dsu(n);\r\n\r\n \
    \   for (int i = 0; i < q; i++) {\r\n        int t, u, v;\r\n        cin >> t\
    \ >> u >> v;\r\n        if (t == 0) {\r\n            dsu.merge(u, v);\r\n    \
    \    } else {\r\n            bool f = (dsu.leader(u) == dsu.leader(v));\r\n  \
    \          cout << f << endl;\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ \"src/data_structure/dsu.hpp\"\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#ifdef LOCAL\r\n#else\r\n#define debug(...) 42\r\n#endif\r\n\r\n\
    #define endl '\\n'\r\ntypedef long long ll;\r\ntypedef pair<int, int> pii;\r\n\
    typedef pair<ll, ll> pll;\r\n\r\nstruct fast_ios {\r\n    fast_ios() {\r\n   \
    \     cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\n        cout\
    \ << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\n\r\nint main() {\r\
    \n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\n#endif\r\n    int\
    \ n, q;\r\n    cin >> n >> q;\r\n\r\n    DSU dsu(n);\r\n\r\n    for (int i = 0;\
    \ i < q; i++) {\r\n        int t, u, v;\r\n        cin >> t >> u >> v;\r\n   \
    \     if (t == 0) {\r\n            dsu.merge(u, v);\r\n        } else {\r\n  \
    \          bool f = (dsu.leader(u) == dsu.leader(v));\r\n            cout << f\
    \ << endl;\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - src/data_structure/dsu.hpp
  isVerificationFile: true
  path: test/dsu.test.cpp
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dsu.test.cpp
layout: document
redirect_from:
- /verify/test/dsu.test.cpp
- /verify/test/dsu.test.cpp.html
title: test/dsu.test.cpp
---
