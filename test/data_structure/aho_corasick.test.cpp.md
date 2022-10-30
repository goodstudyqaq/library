---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/aho_corasick.hpp
    title: "AC \u81EA\u52A8\u673A"
  - icon: ':heavy_check_mark:'
    path: src/string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/data_structure/aho_corasick.test.cpp: line 7: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\r\n#include <bits/stdc++.h>\r\
    \n\r\nusing namespace std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\
    \r\n#else\r\n#define debug(...) 42\r\n#endif\r\n#include \"src/data_structure/aho_corasick.hpp\"\
    \r\n\r\n#define endl '\\n'\r\ntypedef long long ll;\r\ntypedef pair<int, int>\
    \ pii;\r\ntypedef pair<ll, ll> pll;\r\n\r\nstruct fast_ios {\r\n    fast_ios()\
    \ {\r\n        cin.tie(nullptr);\r\n        ios::sync_with_stdio(false);\r\n \
    \       cout << fixed << setprecision(10);\r\n    };\r\n} fast_ios_;\r\n\r\nstruct\
    \ Node : TrieNode {\r\n    int cnt;\r\n    Node(int char_size) : TrieNode(char_size),\
    \ cnt(0) {}\r\n\r\n    void update_when_finish_in_trie() { cnt++; }\r\n\r\n  \
    \  void update_when_build_fail(const Node &fail) { cnt += fail.cnt; }\r\n};\r\n\
    \r\nint main() {\r\n#ifdef LOCAL\r\n    freopen(\"./data.in\", \"r\", stdin);\r\
    \n#endif\r\n\r\n    string s;\r\n    cin >> s;\r\n    int n;\r\n    cin >> n;\r\
    \n\r\n    AhoCorasick<Node> aho = AhoCorasick<Node>(26, 'A');\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        string t;\r\n        cin >> t;\r\n        aho.add(t);\r\
    \n    }\r\n\r\n    aho.build();\r\n\r\n    int res = 0;\r\n\r\n    Node rt = aho.nodes[aho.root];\r\
    \n\r\n    for (int i = 0; i < s.size(); i++) {\r\n        rt = aho.nodes[rt.nxt[s[i]\
    \ - 'A']];\r\n        res += rt.cnt;\r\n    }\r\n    cout << res << endl;\r\n\
    \    return 0;\r\n}"
  dependsOn:
  - src/data_structure/aho_corasick.hpp
  - src/string/trie.hpp
  isVerificationFile: true
  path: test/data_structure/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2022-10-11 22:28:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/aho_corasick.test.cpp
- /verify/test/data_structure/aho_corasick.test.cpp.html
title: test/data_structure/aho_corasick.test.cpp
---
