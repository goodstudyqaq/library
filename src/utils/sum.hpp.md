---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/sum.md
    document_title: "\u524D\u7F00\u548C"
    links:
    - https://atcoder.jp/contests/abc260/tasks/abc260_g
  bundledCode: "#line 1 \"src/utils/sum.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n/*\r\n@brief \u524D\u7F00\u548C\r\n@docs docs/sum.md\r\n*/\r\n/*\r\
    \n\u659C\u7387\u524D\u7F00\u548C\uFF1Ahttps://atcoder.jp/contests/abc260/tasks/abc260_g\r\
    \n\u524D\u7F00\u548C\u5176\u5B9E\u53EF\u4EE5\u4EE5\u4EFB\u610F\u65B9\u5411\u53BB\
    \u9012\u63A8\u3002\r\n*/\r\n\r\ntemplate <typename T = long long>\r\nstruct Sum\
    \ {\r\n    // sum1 \u524D\u7F00\u548C sum2 \u524D\u7F00\u548C\u7684\u524D\u7F00\
    \u548C\r\n    vector<T> sum1, sum2;\r\n    // \u4ECE 1 \u5F00\u59CB\r\n    Sum(vector<T>\
    \ &a) {\r\n        int n = a.size() - 1;\r\n        sum1.resize(n + 1);\r\n  \
    \      sum2.resize(n + 1);\r\n        for (int i = 1; i <= n; i++) {\r\n     \
    \       sum1[i] = sum1[i - 1] + a[i];\r\n            sum2[i] = sum2[i - 1] + sum1[i];\r\
    \n        }\r\n    }\r\n\r\n    // \u8BA1\u7B97 (i, r] \u6240\u6709\u70B9\u5230\
    \ i + 1 \u7684\u533A\u95F4\u548C\u7684\u548C\r\n    T get_special_sum1(int i,\
    \ int r) {\r\n        return (sum2[r] - sum2[i]) - sum1[i] * (r - i);\r\n    \
    \    // \u5982\u679C\u60F3\u8BA1\u7B97 [i, r] \u5230 i \u7684\u533A\u95F4\u548C\
    \uFF0C\u53EA\u9700\u8981\u52A0\u4E0A (r - i) * a[i] \u5373\u53EF\r\n    }\r\n\r\
    \n    // \u4EE5 i \u4E3A\u8D77\u70B9\uFF0C\u8BA1\u7B97 [l, i] \u6240\u6709\u70B9\
    \u5230 i \u7684\u533A\u95F4\u548C\u7684\u548C\r\n    T get_special_sum2(int i,\
    \ int l) {\r\n        return sum1[i] * (i - l + 1) - (sum2[i] - sum2[l - 1]) +\
    \ sum1[i] - sum1[l - 1];\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief \u524D\
    \u7F00\u548C\r\n@docs docs/sum.md\r\n*/\r\n/*\r\n\u659C\u7387\u524D\u7F00\u548C\
    \uFF1Ahttps://atcoder.jp/contests/abc260/tasks/abc260_g\r\n\u524D\u7F00\u548C\u5176\
    \u5B9E\u53EF\u4EE5\u4EE5\u4EFB\u610F\u65B9\u5411\u53BB\u9012\u63A8\u3002\r\n*/\r\
    \n\r\ntemplate <typename T = long long>\r\nstruct Sum {\r\n    // sum1 \u524D\u7F00\
    \u548C sum2 \u524D\u7F00\u548C\u7684\u524D\u7F00\u548C\r\n    vector<T> sum1,\
    \ sum2;\r\n    // \u4ECE 1 \u5F00\u59CB\r\n    Sum(vector<T> &a) {\r\n       \
    \ int n = a.size() - 1;\r\n        sum1.resize(n + 1);\r\n        sum2.resize(n\
    \ + 1);\r\n        for (int i = 1; i <= n; i++) {\r\n            sum1[i] = sum1[i\
    \ - 1] + a[i];\r\n            sum2[i] = sum2[i - 1] + sum1[i];\r\n        }\r\n\
    \    }\r\n\r\n    // \u8BA1\u7B97 (i, r] \u6240\u6709\u70B9\u5230 i + 1 \u7684\
    \u533A\u95F4\u548C\u7684\u548C\r\n    T get_special_sum1(int i, int r) {\r\n \
    \       return (sum2[r] - sum2[i]) - sum1[i] * (r - i);\r\n        // \u5982\u679C\
    \u60F3\u8BA1\u7B97 [i, r] \u5230 i \u7684\u533A\u95F4\u548C\uFF0C\u53EA\u9700\u8981\
    \u52A0\u4E0A (r - i) * a[i] \u5373\u53EF\r\n    }\r\n\r\n    // \u4EE5 i \u4E3A\
    \u8D77\u70B9\uFF0C\u8BA1\u7B97 [l, i] \u6240\u6709\u70B9\u5230 i \u7684\u533A\u95F4\
    \u548C\u7684\u548C\r\n    T get_special_sum2(int i, int l) {\r\n        return\
    \ sum1[i] * (i - l + 1) - (sum2[i] - sum2[l - 1]) + sum1[i] - sum1[l - 1];\r\n\
    \    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utils/sum.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utils/sum.hpp
layout: document
redirect_from:
- /library/src/utils/sum.hpp
- /library/src/utils/sum.hpp.html
title: "\u524D\u7F00\u548C"
---
# Sum

## 概要
记录一些前缀和用法。
**前缀和其实可以以任意方向去递推。**
### `Sum`
`Sum` 是一个前缀和的模板，下标从 1 开始。 它有以下几个参数：
- `vector<T> sum1`：`sum1[i]` 表示 `a[1] + a[2] + ... + a[i]`。
- `vector<T> sum2`: `sum2[i]` 表示 `sum1[1] + sum1[2] + ... + sum1[i]`。

- `Sum(vector<T> &a)`: 构造一个 `Sum` 类，用于求解 `a` 的前缀和。
- `T get_special_sum1(int i, int r)`: 计算 $(i, r]$ 所有元素到 $ i + 1 $ 的区间和的和。
- `T get_special_sum2(int i, int l)`: 以 $ i $ 为起点， 计算 $ [l, i] 所有元素到 $ i $ 的区间和的和。

## 常见问题

## 题集
- 斜率前缀和：https://atcoder.jp/contests/abc260/tasks/abc260_g