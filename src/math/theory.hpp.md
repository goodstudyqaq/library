---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math_theory.md
    document_title: Theory
    links: []
  bundledCode: "#line 1 \"src/math/theory.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief Theory\r\n@docs docs/math_theory.md\r\n*/\r\
    \n\r\nstruct IntegerChunk {\r\n    int n;\r\n    IntegerChunk(int n) : n(n) {}\r\
    \n\r\n    struct Iterator {\r\n        int i;\r\n        int n;\r\n        int\
    \ l, r, val;\r\n        // n / [l, r] = val\r\n        //\u6B63\u7740\r\n    \
    \    // a / val \u80FD\u6C42\u5230\u4E00\u4E2A\u4E0A\u9650 r\uFF0C a / r = val\
    \ \u5373\u6700\u5927\u7684 r \u4F7F\u5F97 a / r = val\r\n        Iterator(int\
    \ _i, int _n) : i(_i),\r\n                                   n(_n) {\r\n     \
    \       l = i;\r\n            val = n / l;\r\n            r = n / val;\r\n   \
    \     }\r\n        int operator*() const {\r\n            return i;\r\n      \
    \  }\r\n        bool operator!=(const Iterator& a) const {\r\n            return\
    \ i != a.i;\r\n        }\r\n        Iterator& operator++() {\r\n            return\
    \ *this = Iterator(r + 1, n);\r\n        }\r\n    };\r\n    Iterator begin() const\
    \ {\r\n        return Iterator(1, n);\r\n    }\r\n    Iterator end() const {\r\
    \n        return Iterator(n, n);\r\n    }\r\n};\r\n\r\nstruct ReverseIntegerChunk\
    \ {\r\n    int n;\r\n    ReverseIntegerChunk(int n) : n(n) {}\r\n\r\n    struct\
    \ Iterator {\r\n        int i;\r\n        int n;\r\n        int l, r, val;\r\n\
    \        /*\r\n        \u53CD\u7740\u679A\u4E3E\r\n        \u5927\u6982\u7684\u903B\
    \u8F91\uFF1A a / i \u80FD\u591F\u5F97\u5230\u5F53\u524D\u7684 val\uFF0C\u800C\
    \ val \u4E5F\u80FD\u7406\u89E3\u6210\u4E00\u4E2A\u662F\u5F97\u5230 i \u7684\u6700\
    \u5927\u7684 r\uFF0C\u5373 val \u662F\u6EE1\u8DB3 a / val = i \u7684\u6700\u5927\
    \u7684\u503C\uFF0C\u90A3\u4E48 val + 1 \u662F\u4E0B\u4E00\u5C42\u7684\u5DE6\u7AEF\
    \u70B9\uFF0C\r\n        \u518D\u8FDB\u884C\u4E00\u4E2A / \u5C31\u80FD\u5F97\u5230\
    \u4E0B\u4E00\u5C42\u7684\u503C\uFF0C\u5373\u4E5F\u662F\u80FD\u5F97\u5230\u4E0B\
    \u4E00\u5C42\u7684\u503C\u7684\u53F3\u7AEF\u70B9\u3002\r\n        \u6709\u70B9\
    \u7ED5\uFF0C\u4F30\u8BA1\u9762\u5BF9\u8FD9\u4E2A\u95EE\u9898\u7684\u65F6\u5019\
    \u8FD9\u4E2A\u903B\u8F91\u4E5F\u662F\u770B\u4E0D\u61C2\u7684\u3002\u8FD8\u662F\
    \u770B\u4E0B\u9762\u7684\u6CE8\u91CA\u5427\u3002\r\n        */\r\n        Iterator(int\
    \ _i, int _n) : i(_i), n(_n) {\r\n            r = i;\r\n            val = n /\
    \ r;\r\n            l = n / (val + 1) + 1;\r\n        }\r\n        int operator*()\
    \ const {\r\n            return i;\r\n        }\r\n        bool operator!=(const\
    \ Iterator& a) const {\r\n            return i != a.i;\r\n        }\r\n      \
    \  Iterator& operator++() {\r\n            return *this = Iterator(l - 1, n);\r\
    \n        }\r\n    };\r\n    Iterator begin() const {\r\n        return Iterator(n,\
    \ n);\r\n    }\r\n    Iterator end() const {\r\n        return Iterator(1, n);\r\
    \n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief Theory\r\
    \n@docs docs/math_theory.md\r\n*/\r\n\r\nstruct IntegerChunk {\r\n    int n;\r\
    \n    IntegerChunk(int n) : n(n) {}\r\n\r\n    struct Iterator {\r\n        int\
    \ i;\r\n        int n;\r\n        int l, r, val;\r\n        // n / [l, r] = val\r\
    \n        //\u6B63\u7740\r\n        // a / val \u80FD\u6C42\u5230\u4E00\u4E2A\u4E0A\
    \u9650 r\uFF0C a / r = val \u5373\u6700\u5927\u7684 r \u4F7F\u5F97 a / r = val\r\
    \n        Iterator(int _i, int _n) : i(_i),\r\n                              \
    \     n(_n) {\r\n            l = i;\r\n            val = n / l;\r\n          \
    \  r = n / val;\r\n        }\r\n        int operator*() const {\r\n          \
    \  return i;\r\n        }\r\n        bool operator!=(const Iterator& a) const\
    \ {\r\n            return i != a.i;\r\n        }\r\n        Iterator& operator++()\
    \ {\r\n            return *this = Iterator(r + 1, n);\r\n        }\r\n    };\r\
    \n    Iterator begin() const {\r\n        return Iterator(1, n);\r\n    }\r\n\
    \    Iterator end() const {\r\n        return Iterator(n, n);\r\n    }\r\n};\r\
    \n\r\nstruct ReverseIntegerChunk {\r\n    int n;\r\n    ReverseIntegerChunk(int\
    \ n) : n(n) {}\r\n\r\n    struct Iterator {\r\n        int i;\r\n        int n;\r\
    \n        int l, r, val;\r\n        /*\r\n        \u53CD\u7740\u679A\u4E3E\r\n\
    \        \u5927\u6982\u7684\u903B\u8F91\uFF1A a / i \u80FD\u591F\u5F97\u5230\u5F53\
    \u524D\u7684 val\uFF0C\u800C val \u4E5F\u80FD\u7406\u89E3\u6210\u4E00\u4E2A\u662F\
    \u5F97\u5230 i \u7684\u6700\u5927\u7684 r\uFF0C\u5373 val \u662F\u6EE1\u8DB3 a\
    \ / val = i \u7684\u6700\u5927\u7684\u503C\uFF0C\u90A3\u4E48 val + 1 \u662F\u4E0B\
    \u4E00\u5C42\u7684\u5DE6\u7AEF\u70B9\uFF0C\r\n        \u518D\u8FDB\u884C\u4E00\
    \u4E2A / \u5C31\u80FD\u5F97\u5230\u4E0B\u4E00\u5C42\u7684\u503C\uFF0C\u5373\u4E5F\
    \u662F\u80FD\u5F97\u5230\u4E0B\u4E00\u5C42\u7684\u503C\u7684\u53F3\u7AEF\u70B9\
    \u3002\r\n        \u6709\u70B9\u7ED5\uFF0C\u4F30\u8BA1\u9762\u5BF9\u8FD9\u4E2A\
    \u95EE\u9898\u7684\u65F6\u5019\u8FD9\u4E2A\u903B\u8F91\u4E5F\u662F\u770B\u4E0D\
    \u61C2\u7684\u3002\u8FD8\u662F\u770B\u4E0B\u9762\u7684\u6CE8\u91CA\u5427\u3002\
    \r\n        */\r\n        Iterator(int _i, int _n) : i(_i), n(_n) {\r\n      \
    \      r = i;\r\n            val = n / r;\r\n            l = n / (val + 1) + 1;\r\
    \n        }\r\n        int operator*() const {\r\n            return i;\r\n  \
    \      }\r\n        bool operator!=(const Iterator& a) const {\r\n           \
    \ return i != a.i;\r\n        }\r\n        Iterator& operator++() {\r\n      \
    \      return *this = Iterator(l - 1, n);\r\n        }\r\n    };\r\n    Iterator\
    \ begin() const {\r\n        return Iterator(n, n);\r\n    }\r\n    Iterator end()\
    \ const {\r\n        return Iterator(1, n);\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/theory.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/theory.hpp
layout: document
redirect_from:
- /library/src/math/theory.hpp
- /library/src/math/theory.hpp.html
title: Theory
---
# 数论

## 概要
记录一些数论的知识点

### 分块
分块是一种常见的优化算法，它的基本思想是将一个序列分成若干个块，每个块的长度为 $O(\sqrt{n})$，然后对每个块进行预处理，这样就可以在 $O(1)$ 的时间内回答询问。
#### `IntegerChunk`
`IntegerChunk` 是一个分块的模板, 它返回一个正着分块的迭代器, 用法如下:
```cpp
IntegerChunk chunk(100);
for (auto it = chunk.begin(); it != chunk.end(); ++it) {
    cout << *it << endl;
}
```
#### `ReverseIntegerChunk`
`ReverseIntegerChunk` 是一个分块的模板, 它返回一个反着分块的迭代器, 用法与 `IntegerChunk` 相同.



## 常见问题

## 题集
h