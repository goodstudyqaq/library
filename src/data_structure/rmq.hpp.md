---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/string/sa.hpp
    title: Suffix Array
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/rmq.test.cpp
    title: test/data_structure/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/sa.test.cpp
    title: test/string/sa.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/rmq.md
    document_title: RMQ
    links:
    - https://codeforces.com/contest/1736/problem/C2
  bundledCode: "#line 1 \"src/data_structure/rmq.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n/*\r\n@brief RMQ\r\n@docs docs/rmq.md\r\n*/\r\n\r\
    \n/*\r\nhttps://codeforces.com/contest/1736/problem/C2\r\n*/\r\ntemplate <typename\
    \ T>\r\nstruct RMQ {\r\n    int n = 0, levels = 0;\r\n    vector<T> values;\r\n\
    \    vector<vector<int>> range_high;\r\n    function<bool(T, T)> func;\r\n\r\n\
    \    RMQ(const vector<T>& _values, function<bool(T, T)> f) {\r\n        func =\
    \ f;\r\n        if (!_values.empty())\r\n            build(_values, f);\r\n  \
    \  }\r\n    RMQ() {}\r\n\r\n    static int largest_bit(int x) {\r\n        return\
    \ 31 - __builtin_clz(x);\r\n    }\r\n\r\n    int max_index(int a, int b) const\
    \ {\r\n        return func(values[a], values[b]) ? a : b;\r\n        // return\
    \ values[a] > values[b] ? a : b;\r\n    }\r\n\r\n    void build(const vector<T>&\
    \ _values, function<bool(T, T)> f) {\r\n        values = _values;\r\n        func\
    \ = f;\r\n        n = values.size();\r\n        levels = largest_bit(n) + 1;\r\
    \n        range_high.resize(levels);\r\n\r\n        for (int k = 0; k < levels;\
    \ k++)\r\n            range_high[k].resize(n - (1 << k) + 1);\r\n\r\n        for\
    \ (int i = 0; i < n; i++)\r\n            range_high[0][i] = i;\r\n\r\n       \
    \ for (int k = 1; k < levels; k++)\r\n            for (int i = 0; i <= n - (1\
    \ << k); i++) {\r\n                range_high[k][i] = max_index(range_high[k -\
    \ 1][i], range_high[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n    }\r\n\
    \    // [a, b]\r\n    int rmq_index(int a, int b) const {\r\n        assert(a\
    \ <= b);\r\n        int level = largest_bit(b + 1 - a);\r\n        return max_index(range_high[level][a],\
    \ range_high[level][b + 1 - (1 << level)]);\r\n    }\r\n\r\n    // [a, b]\r\n\
    \    T rmq_value(int a, int b) const {\r\n        return values[rmq_index(a, b)];\r\
    \n    }\r\n\r\n    int nxt_idx(int idx) {\r\n        int sz = range_high.size()\
    \ - 1;\r\n        int now = idx;\r\n        for (int i = sz; i >= 0; i--) {\r\n\
    \            if (now + (1 << i) - 1 < n && max_index(range_high[i][now], idx)\
    \ == idx) {\r\n                now += (1 << i);\r\n            }\r\n        }\r\
    \n        return now;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief RMQ\r\
    \n@docs docs/rmq.md\r\n*/\r\n\r\n/*\r\nhttps://codeforces.com/contest/1736/problem/C2\r\
    \n*/\r\ntemplate <typename T>\r\nstruct RMQ {\r\n    int n = 0, levels = 0;\r\n\
    \    vector<T> values;\r\n    vector<vector<int>> range_high;\r\n    function<bool(T,\
    \ T)> func;\r\n\r\n    RMQ(const vector<T>& _values, function<bool(T, T)> f) {\r\
    \n        func = f;\r\n        if (!_values.empty())\r\n            build(_values,\
    \ f);\r\n    }\r\n    RMQ() {}\r\n\r\n    static int largest_bit(int x) {\r\n\
    \        return 31 - __builtin_clz(x);\r\n    }\r\n\r\n    int max_index(int a,\
    \ int b) const {\r\n        return func(values[a], values[b]) ? a : b;\r\n   \
    \     // return values[a] > values[b] ? a : b;\r\n    }\r\n\r\n    void build(const\
    \ vector<T>& _values, function<bool(T, T)> f) {\r\n        values = _values;\r\
    \n        func = f;\r\n        n = values.size();\r\n        levels = largest_bit(n)\
    \ + 1;\r\n        range_high.resize(levels);\r\n\r\n        for (int k = 0; k\
    \ < levels; k++)\r\n            range_high[k].resize(n - (1 << k) + 1);\r\n\r\n\
    \        for (int i = 0; i < n; i++)\r\n            range_high[0][i] = i;\r\n\r\
    \n        for (int k = 1; k < levels; k++)\r\n            for (int i = 0; i <=\
    \ n - (1 << k); i++) {\r\n                range_high[k][i] = max_index(range_high[k\
    \ - 1][i], range_high[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n    }\r\
    \n    // [a, b]\r\n    int rmq_index(int a, int b) const {\r\n        assert(a\
    \ <= b);\r\n        int level = largest_bit(b + 1 - a);\r\n        return max_index(range_high[level][a],\
    \ range_high[level][b + 1 - (1 << level)]);\r\n    }\r\n\r\n    // [a, b]\r\n\
    \    T rmq_value(int a, int b) const {\r\n        return values[rmq_index(a, b)];\r\
    \n    }\r\n\r\n    int nxt_idx(int idx) {\r\n        int sz = range_high.size()\
    \ - 1;\r\n        int now = idx;\r\n        for (int i = sz; i >= 0; i--) {\r\n\
    \            if (now + (1 << i) - 1 < n && max_index(range_high[i][now], idx)\
    \ == idx) {\r\n                now += (1 << i);\r\n            }\r\n        }\r\
    \n        return now;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/rmq.hpp
  requiredBy:
  - src/string/sa.hpp
  timestamp: '2022-10-30 15:53:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/rmq.test.cpp
  - test/string/sa.test.cpp
documentation_of: src/data_structure/rmq.hpp
layout: document
redirect_from:
- /library/src/data_structure/rmq.hpp
- /library/src/data_structure/rmq.hpp.html
title: RMQ
---
# 概要
RMQ 为 Range Minimum Query 的缩写，用于查询区间内的最值问题。时间复杂度为 $O(n\log n)$。

## `RMQ`
`RMQ` 是一个该算法的模板类，主要有以下几个方法：
- `RMQ(const vector<T>& _values, function<bool(T, T)> f)`: 构造函数，传入一个数组和一个比较函数，用于比较两个值的大小。
- `void build(const vector<T>& _values, function<bool(T, T)> f)`: 重新构造 RMQ，传入一个数组和一个比较函数，用于比较两个值的大小。
- `int rmq_index(int a, int b)`: 查询区间 `[a, b]` 内的最值的下标。
- `T rmq_value(int a, int b)`: 查询区间 `[a, b]` 内的最值。
- `int nxt_idx(int idx)`: 查询下一个不同值的下标。


# 常见问题

# 题集