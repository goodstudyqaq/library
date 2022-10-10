---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/yosupo_range_affine_range_sum.cpp: line 9: unable to process #include in\
    \ #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n#include <bits/stdc++.h>\r\n\r\n#include \"src/data_structure/lazy_segment_tree.hpp\"\
    \r\n\r\nusing namespace std;\r\n\r\n#ifdef LOCAL\r\n#include \"copypaste/debug.h\"\
    \r\n#else\r\n#define debug(...) 42\r\n#endif\r\n\r\n#define endl '\\n'\r\ntypedef\
    \ long long ll;\r\ntypedef pair<int, int> pii;\r\ntypedef pair<ll, ll> pll;\r\n\
    \r\nstruct fast_ios {\r\n    fast_ios() {\r\n        cin.tie(nullptr);\r\n   \
    \     ios::sync_with_stdio(false);\r\n        cout << fixed << setprecision(10);\r\
    \n    };\r\n} fast_ios_;\r\nconst int mod = 998244353;\r\n\r\nstruct MyTag {\r\
    \n    int a, c;\r\n    MyTag() {\r\n        a = 1;\r\n        c = 0;\r\n    }\r\
    \n    MyTag(int a, int c) : a(a), c(c) {}\r\n    // apply \u4E4B\u524D\u9700\u8981\
    \u5224\u65AD v \u662F\u5426\u4E3A\u9ED8\u8BA4\u503C\r\n    void apply(const MyTag\
    \ &v, int l, int r) {\r\n        a = 1LL * a * v.a % mod;\r\n        c = (1LL\
    \ * c * v.a % mod + v.c) % mod;\r\n    }\r\n};\r\n\r\nstruct MyInfo {\r\n    int\
    \ sum;\r\n    MyInfo() {\r\n        sum = 0;\r\n    }\r\n    MyInfo(int sum) :\
    \ sum(sum) {}\r\n    // apply \u4E4B\u524D\u9700\u8981\u5224\u65AD v \u662F\u5426\
    \u4E3A\u9ED8\u8BA4\u503C\r\n    // [l, r]\r\n    void apply(const MyTag &v, int\
    \ l, int r) {\r\n        sum = (1LL * sum * v.a % mod + 1LL * (r - l + 1) * v.c\
    \ % mod) % mod;\r\n    }\r\n\r\n    static MyInfo merge(const MyInfo &left_info,\
    \ const MyInfo &right_info, int l, int r) {\r\n        return MyInfo((left_info.sum\
    \ + right_info.sum) % mod);\r\n    }\r\n};\r\n\r\nint main() {\r\n#ifdef LOCAL\r\
    \n    freopen(\"./data.in\", \"r\", stdin);\r\n#endif\r\n\r\n    int n, q;\r\n\
    \    cin >> n >> q;\r\n    LazySegmentTree<MyInfo, MyTag> seg(n);\r\n\r\n    for\
    \ (int i = 0; i < n; i++) {\r\n        int a;\r\n        cin >> a;\r\n       \
    \ seg.update(i, MyInfo(a));\r\n    }\r\n\r\n    while (q--) {\r\n        int t;\r\
    \n        cin >> t;\r\n        if (t == 0) {\r\n            int l, r, b, c;\r\n\
    \            cin >> l >> r >> b >> c;\r\n            seg.rangeUpdate(l, r - 1,\
    \ MyTag(b, c));\r\n        } else {\r\n            int l, r;\r\n            cin\
    \ >> l >> r;\r\n            debug(l, r);\r\n            int res = seg.rangeQuery(l,\
    \ r - 1).sum;\r\n            cout << res << endl;\r\n        }\r\n    }\r\n  \
    \  return 0;\r\n}"
  dependsOn:
  - src/data_structure/lazy_segment_tree.hpp
  isVerificationFile: false
  path: test/yosupo_range_affine_range_sum.cpp
  requiredBy: []
  timestamp: '2022-10-09 22:22:10+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo_range_affine_range_sum.cpp
layout: document
redirect_from:
- /library/test/yosupo_range_affine_range_sum.cpp
- /library/test/yosupo_range_affine_range_sum.cpp.html
title: test/yosupo_range_affine_range_sum.cpp
---
