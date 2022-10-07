---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/kmp.md
    document_title: KMP
    links: []
  bundledCode: "#line 1 \"src/string/kmp.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief  KMP\r\n@docs docs/kmp.md\r\n*/\r\n\r\n/*\r\
    \nKMP \u7684\u672C\u8D28\u662F next \u6570\u7EC4\uFF0C\u5373\u627E\u5230\u4EE5\
    \u5F53\u524D i \u7ED3\u5C3E\u7684 s \u5B50\u4E32\u4E0E\u524D\u7F00\u5B8C\u5168\
    \u7B49\u4EF7\u7684\u6700\u957F\u540E\u7F00\u7684\u957F\u5EA6\u3002\r\n\u6CE8\u610F\
    \u8FD9\u91CC\u6CA1\u6709\u7528\u76F8\u540C\uFF0C\u800C\u662F\u7528\u5B8C\u5168\
    \u7B49\u4EF7\u8FD9\u4E2A\u8BCD\uFF0C\u6839\u636E\u4E0D\u540C\u9898\u610F\uFF0C\
    \u5B8C\u5168\u7B49\u4EF7\u7684\u610F\u4E49\u662F\u4E0D\u540C\u7684\uFF0C\u4F46\
    \u6838\u5FC3\u662F\u6700\u7EC8\u53D8\u51FA\u6765\u7684\u4E1C\u897F\u662F\u4E00\
    \u6A21\u4E00\u6837\u7684\u3002\r\n\u4F46\u611F\u89C9\u597D\u50CF\u53EA\u80FD\u662F\
    \u76F8\u7B49\u554A\uFF1F\uFF1F\uFF1F\uFF1F\r\n*/\r\nstruct KMP {\r\n    string\
    \ s;\r\n    vector<int> next;  // next[i] \u8868\u793A\u524D\u7F00\u957F\u5EA6\
    \u4E3A i \u7684\u5B50\u4E32 s \u7684\u4E0E\u524D\u7F00\u76F8\u540C\u7684\u6700\
    \u957F\u540E\u7F00\u7684\u957F\u5EA6\r\n    KMP(string &_s) {\r\n        s = _s;\r\
    \n    }\r\n\r\n    void kmp_pre() {\r\n        int m = s.size();\r\n        next.resize(m\
    \ + 1);\r\n        int i, j;\r\n        j = next[0] = -1;\r\n        i = 0;\r\n\
    \        while (i < m) {\r\n            while (j != -1 && s[i] != s[j]) j = next[j];\r\
    \n            next[++i] = ++j;\r\n        }\r\n    }\r\n\r\n    void fast_kmp_pre()\
    \ {\r\n        int m = s.size();\r\n        next.resize(m + 1);\r\n        int\
    \ i, j;\r\n        j = next[0] = -1;\r\n        i = 0;\r\n        while (i < m)\
    \ {\r\n            while (j != -1 && s[i] != s[j]) j = next[j];\r\n          \
    \  if (s[++i] == s[++j])\r\n                next[i] = next[j];\r\n           \
    \ else\r\n                next[i] = j;\r\n        }\r\n    }\r\n\r\n    // \u8BA1\
    \u7B97 s \u5728 s2 \u4E2D\u51FA\u73B0\u7684\u6B21\u6570, \u9700\u8981\u5148\u8C03\
    \u7528 kmp_pre \u51FD\u6570\r\n    int count(string &s2) {\r\n        int m =\
    \ s.size();\r\n        int n = s2.size();\r\n        int i = 0, j = 0;\r\n   \
    \     int ans = 0;\r\n        while (i < n) {\r\n            while (j != -1 &&\
    \ s2[i] != s[j]) {\r\n                j = next[j];\r\n            }\r\n      \
    \      i++, j++;\r\n            if (j >= m) {\r\n                ans++;\r\n  \
    \          }\r\n        }\r\n        return ans;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief  KMP\r\
    \n@docs docs/kmp.md\r\n*/\r\n\r\n/*\r\nKMP \u7684\u672C\u8D28\u662F next \u6570\
    \u7EC4\uFF0C\u5373\u627E\u5230\u4EE5\u5F53\u524D i \u7ED3\u5C3E\u7684 s \u5B50\
    \u4E32\u4E0E\u524D\u7F00\u5B8C\u5168\u7B49\u4EF7\u7684\u6700\u957F\u540E\u7F00\
    \u7684\u957F\u5EA6\u3002\r\n\u6CE8\u610F\u8FD9\u91CC\u6CA1\u6709\u7528\u76F8\u540C\
    \uFF0C\u800C\u662F\u7528\u5B8C\u5168\u7B49\u4EF7\u8FD9\u4E2A\u8BCD\uFF0C\u6839\
    \u636E\u4E0D\u540C\u9898\u610F\uFF0C\u5B8C\u5168\u7B49\u4EF7\u7684\u610F\u4E49\
    \u662F\u4E0D\u540C\u7684\uFF0C\u4F46\u6838\u5FC3\u662F\u6700\u7EC8\u53D8\u51FA\
    \u6765\u7684\u4E1C\u897F\u662F\u4E00\u6A21\u4E00\u6837\u7684\u3002\r\n\u4F46\u611F\
    \u89C9\u597D\u50CF\u53EA\u80FD\u662F\u76F8\u7B49\u554A\uFF1F\uFF1F\uFF1F\uFF1F\
    \r\n*/\r\nstruct KMP {\r\n    string s;\r\n    vector<int> next;  // next[i] \u8868\
    \u793A\u524D\u7F00\u957F\u5EA6\u4E3A i \u7684\u5B50\u4E32 s \u7684\u4E0E\u524D\
    \u7F00\u76F8\u540C\u7684\u6700\u957F\u540E\u7F00\u7684\u957F\u5EA6\r\n    KMP(string\
    \ &_s) {\r\n        s = _s;\r\n    }\r\n\r\n    void kmp_pre() {\r\n        int\
    \ m = s.size();\r\n        next.resize(m + 1);\r\n        int i, j;\r\n      \
    \  j = next[0] = -1;\r\n        i = 0;\r\n        while (i < m) {\r\n        \
    \    while (j != -1 && s[i] != s[j]) j = next[j];\r\n            next[++i] = ++j;\r\
    \n        }\r\n    }\r\n\r\n    void fast_kmp_pre() {\r\n        int m = s.size();\r\
    \n        next.resize(m + 1);\r\n        int i, j;\r\n        j = next[0] = -1;\r\
    \n        i = 0;\r\n        while (i < m) {\r\n            while (j != -1 && s[i]\
    \ != s[j]) j = next[j];\r\n            if (s[++i] == s[++j])\r\n             \
    \   next[i] = next[j];\r\n            else\r\n                next[i] = j;\r\n\
    \        }\r\n    }\r\n\r\n    // \u8BA1\u7B97 s \u5728 s2 \u4E2D\u51FA\u73B0\u7684\
    \u6B21\u6570, \u9700\u8981\u5148\u8C03\u7528 kmp_pre \u51FD\u6570\r\n    int count(string\
    \ &s2) {\r\n        int m = s.size();\r\n        int n = s2.size();\r\n      \
    \  int i = 0, j = 0;\r\n        int ans = 0;\r\n        while (i < n) {\r\n  \
    \          while (j != -1 && s2[i] != s[j]) {\r\n                j = next[j];\r\
    \n            }\r\n            i++, j++;\r\n            if (j >= m) {\r\n    \
    \            ans++;\r\n            }\r\n        }\r\n        return ans;\r\n \
    \   }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/kmp.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/kmp.hpp
layout: document
redirect_from:
- /library/src/string/kmp.hpp
- /library/src/string/kmp.hpp.html
title: KMP
---
# KMP

## 概要
KMP 是一个用于快速匹配字符串的算法。它的时间复杂度为 O(n+m)。
### `KMP`
`KMP` 类是 KMP 的核心类，它提供了一些方法来快速匹配字符串。
- `KMP(const string &s)` : 构造一个 `KMP` 类，用于匹配字符串 `s` 。
- `void kmp_pre()`: 预处理字符串 `s` ，计算出 `next` 数组。
- `void fast_kmp_pre()`: 更快的预处理字符串 `s` ，计算出 `next` 数组。
- `int count(string &s2)`: 返回字符串 `s2` 在字符串 `s` 中出现的次数。需要先调用 `kmp_pre()` 或 `fast_kmp_pre()` 。

## 常见问题

## 题集