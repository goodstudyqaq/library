---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/aho_corasick.hpp
    title: "AC \u81EA\u52A8\u673A"
  - icon: ':x:'
    path: src/string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/yukicoder-430.test.cpp: line 7: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\r\n#include <bits/stdc++.h>\r\
    \n\r\nusing namespace std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\
    \r\n#else\r\n#define debug(...) 42\r\n#endif\r\n#include \"src/data_structure/aho_corasick.hpp\"\
    \r\n\r\n#define endl '\\n'\r\ntypedef long long ll;\r\ntypedef pair<int, int>\
    \ pii;\r\ntypedef pair<ll, ll> pll;\r\n\r\nstruct fast_ios {\r\n    fast_ios()\
    \ {\r\n        cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\n \
    \       cout << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\n\r\nint\
    \ main() {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\n#endif\r\
    \n\r\n    string s;\r\n    cin >> s;\r\n    int n;\r\n    cin >> n;\r\n\r\n  \
    \  AhoCorasick aho = AhoCorasick(26, 'A');\r\n    for (int i = 0; i < n; i++)\
    \ {\r\n        string t;\r\n        cin >> t;\r\n        aho.add(t);\r\n    }\r\
    \n\r\n    aho.build();\r\n}"
  dependsOn:
  - src/data_structure/aho_corasick.hpp
  - src/string/trie.hpp
  isVerificationFile: true
  path: test/yukicoder-430.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 23:04:20+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder-430.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder-430.test.cpp
- /verify/test/yukicoder-430.test.cpp.html
title: test/yukicoder-430.test.cpp
---
