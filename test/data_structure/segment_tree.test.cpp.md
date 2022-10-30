---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segment_tree.hpp
    title: "\u7EBF\u6BB5\u6811"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/data_structure/segment_tree.test.cpp: line 9: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n#include \"src/data_structure/segment_tree.hpp\"\r\n\r\n#include <bits/stdc++.h>\r\
    \n\r\nusing namespace std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\
    \r\n#else\r\n#define debug(...) 42\r\n#endif\r\n\r\n#define endl '\\n'\r\ntypedef\
    \ long long ll;\r\ntypedef pair<int, int> pii;\r\ntypedef pair<ll, ll> pll;\r\n\
    \r\nstruct fast_ios {\r\n    fast_ios() {\r\n        cin.tie(nullptr);\r\n   \
    \     ios::sync_with_stdio(false);\r\n        cout << fixed << setprecision(10);\r\
    \n    };\r\n} fast_ios_;\r\n\r\nstruct MyInfo {\r\n    // \u9ED8\u8BA4\u503C\r\
    \n    ll sum;\r\n    MyInfo() { sum = 0; }\r\n    MyInfo(ll x) { sum = x; }\r\n\
    \    static MyInfo merge(const MyInfo& left_info, const MyInfo& right_info, int\
    \ l, int r) { return MyInfo(left_info.sum + right_info.sum); }\r\n};\r\nint main()\
    \ {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\n#endif\r\n\
    \    int n, q;\r\n    cin >> n >> q;\r\n    vector<int> a(n);\r\n    SegmentTree<MyInfo>\
    \ seg(n);\r\n\r\n    for (int i = 0; i < n; i++) {\r\n        cin >> a[i];\r\n\
    \        seg.update(i, MyInfo(a[i]));\r\n    }\r\n    while (q--) {\r\n      \
    \  int t;\r\n        cin >> t;\r\n        if (t == 0) {\r\n            int p,\
    \ x;\r\n            cin >> p >> x;\r\n            seg.update(p, MyInfo(x));\r\n\
    \        } else {\r\n            int l, r;\r\n            cin >> l >> r;\r\n \
    \           cout << seg.rangeQuery(l, r - 1).sum << endl;\r\n        }\r\n   \
    \ }\r\n    return 0;\r\n}"
  dependsOn:
  - src/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/data_structure/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2022-10-10 22:48:16+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/segment_tree.test.cpp
- /verify/test/data_structure/segment_tree.test.cpp.html
title: test/data_structure/segment_tree.test.cpp
---
