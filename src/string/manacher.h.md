---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/manacher.md
    document_title: Manacher
    links: []
  bundledCode: "#line 1 \"src/string/manacher.h\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief  Manacher\r\n@docs docs/manacher.md\r\n*/\r\
    \n\r\nstruct Manacher {\r\n    string s;\r\n    vector<int> Mp;\r\n    Manacher(string\
    \ &_s) {\r\n        s = \"\";\r\n        int n = _s.size();\r\n        s += \"\
    $\";\r\n        s += \"#\";\r\n        for (int i = 0; i < n; i++) {\r\n     \
    \       s += _s[i];\r\n            s += \"#\";\r\n        }\r\n        s += \"\
    ?\";\r\n        int id = 0, mx = 0;\r\n        int l = s.size();\r\n        Mp.resize(l);\r\
    \n        for (int i = 0; i < l - 1; i++) {\r\n            Mp[i] = mx > i ? min(Mp[2\
    \ * id - i], mx - i) : 1;\r\n            while (i + Mp[i] < l && i - Mp[i] >=\
    \ 0 && s[i + Mp[i]] == s[i - Mp[i]]) Mp[i]++;\r\n            if (i + Mp[i] > mx)\
    \ {\r\n                mx = i + Mp[i];\r\n                id = i;\r\n        \
    \    }\r\n        }\r\n    }\r\n    Manacher() {}\r\n\r\n    int query(int l,\
    \ int r) {\r\n        // l = r \u90A3\u4E48\u5C31\u8868\u793A\u4EE5 l \u4E3A\u4E2D\
    \u5FC3\u7684\u6700\u957F\u56DE\u6587\u4E32\r\n        // l + 1 = r \u90A3\u4E48\
    \u5C31\u8868\u793A\u4EE5 l \u548C r \u4E2D\u95F4\u4E3A\u4E2D\u5FC3\u7684\u6700\
    \u957F\u56DE\u6587\u4E32\r\n        // \u8FD4\u56DE\u957F\u5EA6\r\n        int\
    \ idx = (l + 1) * 2;\r\n        if (l != r) {\r\n            idx++;\r\n      \
    \  }\r\n        int length = Mp[idx];\r\n        return length / 2;\r\n    }\r\
    \n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief  Manacher\r\
    \n@docs docs/manacher.md\r\n*/\r\n\r\nstruct Manacher {\r\n    string s;\r\n \
    \   vector<int> Mp;\r\n    Manacher(string &_s) {\r\n        s = \"\";\r\n   \
    \     int n = _s.size();\r\n        s += \"$\";\r\n        s += \"#\";\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            s += _s[i];\r\n           \
    \ s += \"#\";\r\n        }\r\n        s += \"?\";\r\n        int id = 0, mx =\
    \ 0;\r\n        int l = s.size();\r\n        Mp.resize(l);\r\n        for (int\
    \ i = 0; i < l - 1; i++) {\r\n            Mp[i] = mx > i ? min(Mp[2 * id - i],\
    \ mx - i) : 1;\r\n            while (i + Mp[i] < l && i - Mp[i] >= 0 && s[i +\
    \ Mp[i]] == s[i - Mp[i]]) Mp[i]++;\r\n            if (i + Mp[i] > mx) {\r\n  \
    \              mx = i + Mp[i];\r\n                id = i;\r\n            }\r\n\
    \        }\r\n    }\r\n    Manacher() {}\r\n\r\n    int query(int l, int r) {\r\
    \n        // l = r \u90A3\u4E48\u5C31\u8868\u793A\u4EE5 l \u4E3A\u4E2D\u5FC3\u7684\
    \u6700\u957F\u56DE\u6587\u4E32\r\n        // l + 1 = r \u90A3\u4E48\u5C31\u8868\
    \u793A\u4EE5 l \u548C r \u4E2D\u95F4\u4E3A\u4E2D\u5FC3\u7684\u6700\u957F\u56DE\
    \u6587\u4E32\r\n        // \u8FD4\u56DE\u957F\u5EA6\r\n        int idx = (l +\
    \ 1) * 2;\r\n        if (l != r) {\r\n            idx++;\r\n        }\r\n    \
    \    int length = Mp[idx];\r\n        return length / 2;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/manacher.h
layout: document
redirect_from:
- /library/src/string/manacher.h
- /library/src/string/manacher.h.html
title: Manacher
---
# Manacher

## 概要
Manacher 算法是一个用于求解最长回文子串的算法，时间复杂度为 O(n)。
### `Manacher`
`Manacher` 类是 Manacher 算法的核心类，它提供了一些方法来求解最长回文子串。
- `Manacher(string &s)`: 构造一个 `Manacher` 类，用于求解字符串 `s` 的最长回文子串。
- `int query(int l, int r)`: 如果 $l = r$ ，则返回以 $l$ 为中心的最长回文子串的长度。如果 $l + 1 = r$ ，则返回以 $l$ 和 $r$ 为中心的最长回文子串的长度。

## 常见问题

## 题集