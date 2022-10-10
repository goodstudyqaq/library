---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rmq.hpp
    title: RMQ
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/data_structure/rmq.test.cpp: line 9: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n#include\
    \ <bits/stdc++.h>\r\n\r\n#include \"src/data_structure/rmq.hpp\"\r\n\r\nusing\
    \ namespace std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\r\n#else\r\
    \n#define debug(...) 42\r\n#endif\r\n\r\n#define endl '\\n'\r\ntypedef long long\
    \ ll;\r\ntypedef pair<int, int> pii;\r\ntypedef pair<ll, ll> pll;\r\n\r\nstruct\
    \ fast_ios {\r\n    fast_ios() {\r\n        cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\
    \n        cout << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\n\r\n\
    int main() {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\n\
    #endif\r\n    int n, q;\r\n    cin >> n >> q;\r\n\r\n    vector<int> a(n);\r\n\
    \    for (int i = 0; i < n; i++) {\r\n        cin >> a[i];\r\n    }\r\n\r\n  \
    \  RMQ<int> rmq(a, [](int a, int b) { return a < b; });\r\n\r\n    while (q--)\
    \ {\r\n        int l, r;\r\n        cin >> l >> r;\r\n        cout << rmq.rmq_value(l,\
    \ r - 1) << endl;\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - src/data_structure/rmq.hpp
  isVerificationFile: true
  path: test/data_structure/rmq.test.cpp
  requiredBy: []
  timestamp: '2022-10-10 22:05:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/rmq.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/rmq.test.cpp
- /verify/test/data_structure/rmq.test.cpp.html
title: test/data_structure/rmq.test.cpp
---
