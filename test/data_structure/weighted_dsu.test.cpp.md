---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/weighted_dsu.hpp
    title: "\u5E26\u6743\u5E76\u67E5\u96C6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/data_structure/weighted_dsu.test.cpp: line 7: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include \"src/data_structure/weighted_dsu.hpp\"\n\nusing namespace std;\n\n\
    #ifdef LOCAL\n#include \"copypaste/debug.h\"\n#else\n#define debug(...) 42\n#endif\n\
    \n#define endl '\\n'\ntypedef long long ll;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\n\nstruct fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \    };\n} fast_ios_;\n\nint main() {\n#ifdef LOCAL\n    freopen(\"./data.in\"\
    , \"r\", stdin);\n#endif\n\n    int n, q;\n    cin >> n >> q;\n    WeightedDSU<int>\
    \ dsu(n);\n\n    while (q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int x, y, z;\n            // ay = ax + z\n         \
    \   cin >> x >> y >> z;\n            dsu.merge(x, y, z);\n        } else {\n \
    \           int x, y;\n            cin >> x >> y;\n\n            if (dsu.leader(x).first\
    \ != dsu.leader(y).first) {\n                cout << \"?\" << endl;\n        \
    \    } else {\n                // ay - ax\n                cout << dsu.leader(x).second\
    \ - dsu.leader(y).second << endl;\n            }\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - src/data_structure/weighted_dsu.hpp
  isVerificationFile: true
  path: test/data_structure/weighted_dsu.test.cpp
  requiredBy: []
  timestamp: '2022-10-11 21:52:21+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/weighted_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/weighted_dsu.test.cpp
- /verify/test/data_structure/weighted_dsu.test.cpp.html
title: test/data_structure/weighted_dsu.test.cpp
---
