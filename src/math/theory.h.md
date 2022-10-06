---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math_theory.md
    document_title: Theory
    links: []
  bundledCode: "#line 1 \"src/math/theory.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n/*\r\n@brief Theory\r\n@docs docs/math_theory.md\r\n*/\r\n\r\nvoid\
    \ integer_chunk(int a) {\r\n    /*\r\n       \u6C42 a / i, i \\in [1, a]\r\n \
    \   */\r\n    /*\r\n    \u6B63\u7740\r\n    a / val \u80FD\u6C42\u5230\u4E00\u4E2A\
    \u4E0A\u9650 r\uFF0C a / r = val \u5373\u6700\u5927\u7684 r \u4F7F\u5F97 a / r\
    \ = val\r\n    */\r\n    for (int i = 1; i <= a; i = (a / (a / i)) + 1) {\r\n\
    \        int l = i, val = a / l;\r\n        int r = a / val;\r\n        // a /\
    \ [l, r] \u90FD\u7B49\u4E8E val\r\n    }\r\n\r\n    /*\r\n    \u53CD\u7740\u679A\
    \u4E3E\r\n    \u5927\u6982\u7684\u903B\u8F91\uFF1A a / i \u80FD\u591F\u5F97\u5230\
    \u5F53\u524D\u7684 val\uFF0C\u800C val \u4E5F\u80FD\u7406\u89E3\u6210\u4E00\u4E2A\
    \u662F\u5F97\u5230 i \u7684\u6700\u5927\u7684 r\uFF0C\u5373 val \u662F\u6EE1\u8DB3\
    \ a / val = i \u7684\u6700\u5927\u7684\u503C\uFF0C\u90A3\u4E48 val + 1 \u662F\u4E0B\
    \u4E00\u5C42\u7684\u5DE6\u7AEF\u70B9\uFF0C\r\n    \u518D\u8FDB\u884C\u4E00\u4E2A\
    \ / \u5C31\u80FD\u5F97\u5230\u4E0B\u4E00\u5C42\u7684\u503C\uFF0C\u5373\u4E5F\u662F\
    \u80FD\u5F97\u5230\u4E0B\u4E00\u5C42\u7684\u503C\u7684\u53F3\u7AEF\u70B9\u3002\
    \r\n    \u6709\u70B9\u7ED5\uFF0C\u4F30\u8BA1\u9762\u5BF9\u8FD9\u4E2A\u95EE\u9898\
    \u7684\u65F6\u5019\u8FD9\u4E2A\u903B\u8F91\u4E5F\u662F\u770B\u4E0D\u61C2\u7684\
    \u3002\u8FD8\u662F\u770B\u4E0B\u9762\u7684\u6CE8\u91CA\u5427\u3002\r\n    */\r\
    \n    for (int i = a; i >= 1; i = (a / (a / i + 1))) {\r\n        int r = i, val\
    \ = a / r;\r\n        int next_depth_r = a / (val + 1);\r\n        int l = next_depth_r\
    \ + 1;\r\n        // a / [l, r] \u90FD\u7B49\u4E8E val\r\n    }\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief Theory\r\
    \n@docs docs/math_theory.md\r\n*/\r\n\r\nvoid integer_chunk(int a) {\r\n    /*\r\
    \n       \u6C42 a / i, i \\in [1, a]\r\n    */\r\n    /*\r\n    \u6B63\u7740\r\
    \n    a / val \u80FD\u6C42\u5230\u4E00\u4E2A\u4E0A\u9650 r\uFF0C a / r = val \u5373\
    \u6700\u5927\u7684 r \u4F7F\u5F97 a / r = val\r\n    */\r\n    for (int i = 1;\
    \ i <= a; i = (a / (a / i)) + 1) {\r\n        int l = i, val = a / l;\r\n    \
    \    int r = a / val;\r\n        // a / [l, r] \u90FD\u7B49\u4E8E val\r\n    }\r\
    \n\r\n    /*\r\n    \u53CD\u7740\u679A\u4E3E\r\n    \u5927\u6982\u7684\u903B\u8F91\
    \uFF1A a / i \u80FD\u591F\u5F97\u5230\u5F53\u524D\u7684 val\uFF0C\u800C val \u4E5F\
    \u80FD\u7406\u89E3\u6210\u4E00\u4E2A\u662F\u5F97\u5230 i \u7684\u6700\u5927\u7684\
    \ r\uFF0C\u5373 val \u662F\u6EE1\u8DB3 a / val = i \u7684\u6700\u5927\u7684\u503C\
    \uFF0C\u90A3\u4E48 val + 1 \u662F\u4E0B\u4E00\u5C42\u7684\u5DE6\u7AEF\u70B9\uFF0C\
    \r\n    \u518D\u8FDB\u884C\u4E00\u4E2A / \u5C31\u80FD\u5F97\u5230\u4E0B\u4E00\u5C42\
    \u7684\u503C\uFF0C\u5373\u4E5F\u662F\u80FD\u5F97\u5230\u4E0B\u4E00\u5C42\u7684\
    \u503C\u7684\u53F3\u7AEF\u70B9\u3002\r\n    \u6709\u70B9\u7ED5\uFF0C\u4F30\u8BA1\
    \u9762\u5BF9\u8FD9\u4E2A\u95EE\u9898\u7684\u65F6\u5019\u8FD9\u4E2A\u903B\u8F91\
    \u4E5F\u662F\u770B\u4E0D\u61C2\u7684\u3002\u8FD8\u662F\u770B\u4E0B\u9762\u7684\
    \u6CE8\u91CA\u5427\u3002\r\n    */\r\n    for (int i = a; i >= 1; i = (a / (a\
    \ / i + 1))) {\r\n        int r = i, val = a / r;\r\n        int next_depth_r\
    \ = a / (val + 1);\r\n        int l = next_depth_r + 1;\r\n        // a / [l,\
    \ r] \u90FD\u7B49\u4E8E val\r\n    }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/theory.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/theory.h
layout: document
redirect_from:
- /library/src/math/theory.h
- /library/src/math/theory.h.html
title: Theory
---
