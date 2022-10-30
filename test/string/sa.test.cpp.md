---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rmq.hpp
    title: RMQ
  - icon: ':heavy_check_mark:'
    path: src/string/sa.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/string/sa.test.cpp: line 9: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\r\n#include\
    \ \"src/string/sa.hpp\"\r\n\r\n#include <bits/stdc++.h>\r\n\r\nusing namespace\
    \ std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\r\n#else\r\n#define\
    \ debug(...) 42\r\n#endif\r\n\r\n#define endl '\\n'\r\ntypedef long long ll;\r\
    \ntypedef pair<int, int> pii;\r\ntypedef pair<ll, ll> pll;\r\n\r\nstruct fast_ios\
    \ {\r\n    fast_ios() {\r\n        cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\
    \n        cout << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\n\r\n\
    int main() {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\n\
    #endif\r\n    string s;\r\n    cin >> s;\r\n\r\n    SuffixArray sa(s);\r\n   \
    \ int n = s.size();\r\n    for (int i = 1; i <= n; i++) {\r\n        cout << sa.SA[i]\
    \ - 1 << \" \";\r\n    }\r\n    cout << endl;\r\n}"
  dependsOn:
  - src/string/sa.hpp
  - src/data_structure/rmq.hpp
  isVerificationFile: true
  path: test/string/sa.test.cpp
  requiredBy: []
  timestamp: '2022-10-30 15:53:25+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/sa.test.cpp
layout: document
redirect_from:
- /verify/test/string/sa.test.cpp
- /verify/test/string/sa.test.cpp.html
title: test/string/sa.test.cpp
---
