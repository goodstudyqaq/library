---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/rmq.hpp
    title: RMQ
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/suffix_array.md
    document_title: Suffix Array
    links: []
  bundledCode: "#line 1 \"src/string/sa.h\"\n#include <bits/stdc++.h>\r\n\r\n#line\
    \ 2 \"src/data_structure/rmq.hpp\"\nusing namespace std;\r\n\r\n/*\r\n@brief RMQ\r\
    \n@docs docs/rmq.md\r\n*/\r\n\r\ntemplate <typename T>\r\nstruct RMQ {\r\n   \
    \ int n = 0, levels = 0;\r\n    vector<T> values;\r\n    vector<vector<int>> range_high;\r\
    \n    function<bool(T, T)> func;\r\n\r\n    RMQ(const vector<T>& _values, function<bool(T,\
    \ T)> f) {\r\n        func = f;\r\n        if (!_values.empty())\r\n         \
    \   build(_values, f);\r\n    }\r\n    RMQ() {}\r\n\r\n    static int largest_bit(int\
    \ x) {\r\n        return 31 - __builtin_clz(x);\r\n    }\r\n\r\n    int max_index(int\
    \ a, int b) const {\r\n        return func(values[a], values[b]) ? a : b;\r\n\
    \        // return values[a] > values[b] ? a : b;\r\n    }\r\n\r\n    void build(const\
    \ vector<T>& _values, function<bool(T, T)> f) {\r\n        values = _values;\r\
    \n        n = values.size();\r\n        levels = largest_bit(n) + 1;\r\n     \
    \   range_high.resize(levels);\r\n\r\n        for (int k = 0; k < levels; k++)\r\
    \n            range_high[k].resize(n - (1 << k) + 1);\r\n\r\n        for (int\
    \ i = 0; i < n; i++)\r\n            range_high[0][i] = i;\r\n\r\n        for (int\
    \ k = 1; k < levels; k++)\r\n            for (int i = 0; i <= n - (1 << k); i++)\r\
    \n                range_high[k][i] = max_index(range_high[k - 1][i], range_high[k\
    \ - 1][i + (1 << (k - 1))]);\r\n    }\r\n    // [a, b)\r\n    int rmq_index(int\
    \ a, int b) const {\r\n        assert(a < b);\r\n        int level = largest_bit(b\
    \ - a);\r\n        return max_index(range_high[level][a], range_high[level][b\
    \ - (1 << level)]);\r\n    }\r\n\r\n    T rmq_value(int a, int b) const {\r\n\
    \        return values[rmq_index(a, b)];\r\n    }\r\n\r\n    int nxt_idx(int idx)\
    \ {\r\n        int sz = range_high.size() - 1;\r\n        int now = idx;\r\n \
    \       for (int i = sz; i >= 0; i--) {\r\n            if (now + (1 << i) - 1\
    \ < n && max_index(range_high[i][now], idx) == idx) {\r\n                now +=\
    \ (1 << i);\r\n            }\r\n        }\r\n        return now;\r\n    }\r\n\
    };\n#line 4 \"src/string/sa.h\"\n\r\n/*\r\n@brief Suffix Array\r\n@docs docs/suffix_array.md\r\
    \n*/\r\n\r\nusing namespace std;\r\n// SA[i]=a \u6392\u540D\u4E3Ai\u7684\u4E0B\
    \u6807\u4E3Aa\r\n// rank[a]=i \u4E0B\u6807\u4E3Aa\u7684\u6392\u540D\u4E3Ai\r\n\
    // height[i]=a \u6392\u540D\u4E3Ai\u7684\u548C\u6392\u540D\u4E3Ai-1\u662F\u6700\
    \u957F\u516C\u5171\u524D\u7F00\r\n//\u4E0B\u6807\u4ECE1\u5230N \u5343\u4E07\u4E0D\
    \u80FD\u641E\u9519\r\nstruct SuffixArray {\r\n    vector<int> SA, rank, height;\r\
    \n    int N;\r\n    RMQ<int> rmq;\r\n    SuffixArray(string& s) {\r\n        vector<int>\
    \ cntA, cntB, A, B, tsa, ch;\r\n        N = s.size();\r\n        int mx_element\
    \ = *max_element(s.begin(), s.end());\r\n        int M = max(N, mx_element);\r\
    \n        ch.resize(N + 1);\r\n        cntA.resize(M + 1, 0);\r\n        cntB.resize(N\
    \ + 1, 0);\r\n        SA.resize(N + 1);\r\n        rank.resize(N + 1);\r\n   \
    \     A.resize(N + 1);\r\n        B.resize(N + 1);\r\n        tsa.resize(N + 1);\r\
    \n        height.resize(N + 1);\r\n\r\n        for (int i = 1; i <= N; i++) {\r\
    \n            ch[i] = s[i - 1];\r\n        }\r\n        for (int i = 1; i <= N;\
    \ i++) {\r\n            cntA[ch[i]]++;\r\n        }\r\n\r\n        for (int i\
    \ = 1; i <= mx_element; i++) {\r\n            cntA[i] += cntA[i - 1];\r\n    \
    \    }\r\n\r\n        for (int i = N; i >= 1; i--) {\r\n            SA[cntA[ch[i]]--]\
    \ = i;\r\n        }\r\n        rank[SA[1]] = 1;\r\n        for (int i = 2; i <=\
    \ N; i++) {\r\n            rank[SA[i]] = rank[SA[i - 1]];\r\n            if (ch[SA[i]]\
    \ != ch[SA[i - 1]])\r\n                rank[SA[i]]++;\r\n        }\r\n       \
    \ // debug(SA);\r\n        for (int step = 1; rank[SA[N]] < N; step <<= 1) {\r\
    \n            // debug(step, SA[N], rank[SA[N]]);\r\n            for (int i =\
    \ 1; i <= N; i++) cntA[i] = cntB[i] = 0;\r\n            for (int i = 1; i <= N;\
    \ i++) {\r\n                cntA[A[i] = rank[i]]++;\r\n                cntB[B[i]\
    \ = (i + step <= N) ? rank[i + step] : 0]++;\r\n            }\r\n            for\
    \ (int i = 1; i <= N; i++) cntA[i] += cntA[i - 1], cntB[i] += cntB[i - 1];\r\n\
    \            for (int i = N; i >= 1; i--) tsa[cntB[B[i]]--] = i;\r\n         \
    \   for (int i = N; i >= 1; i--) SA[cntA[A[tsa[i]]]--] = tsa[i];\r\n         \
    \   rank[SA[1]] = 1;\r\n            for (int i = 2; i <= N; i++) {\r\n       \
    \         rank[SA[i]] = rank[SA[i - 1]];\r\n                if (A[SA[i]] != A[SA[i\
    \ - 1]] || B[SA[i]] != B[SA[i - 1]])\r\n                    rank[SA[i]]++;\r\n\
    \            }\r\n        }\r\n        int i, j, k = 0;\r\n        for (int i\
    \ = 1; i <= N; i++) {\r\n            if (k) k--;\r\n            j = SA[rank[i]\
    \ - 1];\r\n            while (i + k <= N && j + k <= N && ch[i + k] == ch[j +\
    \ k]) k++;\r\n            height[rank[i]] = k;\r\n        }\r\n        rmq.build(height,\
    \ [&](int a, int b) -> bool {\r\n            return a < b;\r\n        });\r\n\
    \    }\r\n\r\n    int get_length(int idx1, int idx2) {\r\n        // s \u7684\u4E0B\
    \u6807\r\n        int rk_idx1 = rank[idx1 + 1], rk_idx2 = rank[idx2 + 1];\r\n\
    \        if (rk_idx1 > rk_idx2) {\r\n            swap(rk_idx1, rk_idx2);\r\n \
    \       }\r\n        return rmq.rmq_value(rk_idx1 + 1, rk_idx2 + 1);\r\n    }\r\
    \n};\r\n"
  code: "#include <bits/stdc++.h>\r\n\r\n#include \"./src/data_structure/rmq.hpp\"\
    \r\n\r\n/*\r\n@brief Suffix Array\r\n@docs docs/suffix_array.md\r\n*/\r\n\r\n\
    using namespace std;\r\n// SA[i]=a \u6392\u540D\u4E3Ai\u7684\u4E0B\u6807\u4E3A\
    a\r\n// rank[a]=i \u4E0B\u6807\u4E3Aa\u7684\u6392\u540D\u4E3Ai\r\n// height[i]=a\
    \ \u6392\u540D\u4E3Ai\u7684\u548C\u6392\u540D\u4E3Ai-1\u662F\u6700\u957F\u516C\
    \u5171\u524D\u7F00\r\n//\u4E0B\u6807\u4ECE1\u5230N \u5343\u4E07\u4E0D\u80FD\u641E\
    \u9519\r\nstruct SuffixArray {\r\n    vector<int> SA, rank, height;\r\n    int\
    \ N;\r\n    RMQ<int> rmq;\r\n    SuffixArray(string& s) {\r\n        vector<int>\
    \ cntA, cntB, A, B, tsa, ch;\r\n        N = s.size();\r\n        int mx_element\
    \ = *max_element(s.begin(), s.end());\r\n        int M = max(N, mx_element);\r\
    \n        ch.resize(N + 1);\r\n        cntA.resize(M + 1, 0);\r\n        cntB.resize(N\
    \ + 1, 0);\r\n        SA.resize(N + 1);\r\n        rank.resize(N + 1);\r\n   \
    \     A.resize(N + 1);\r\n        B.resize(N + 1);\r\n        tsa.resize(N + 1);\r\
    \n        height.resize(N + 1);\r\n\r\n        for (int i = 1; i <= N; i++) {\r\
    \n            ch[i] = s[i - 1];\r\n        }\r\n        for (int i = 1; i <= N;\
    \ i++) {\r\n            cntA[ch[i]]++;\r\n        }\r\n\r\n        for (int i\
    \ = 1; i <= mx_element; i++) {\r\n            cntA[i] += cntA[i - 1];\r\n    \
    \    }\r\n\r\n        for (int i = N; i >= 1; i--) {\r\n            SA[cntA[ch[i]]--]\
    \ = i;\r\n        }\r\n        rank[SA[1]] = 1;\r\n        for (int i = 2; i <=\
    \ N; i++) {\r\n            rank[SA[i]] = rank[SA[i - 1]];\r\n            if (ch[SA[i]]\
    \ != ch[SA[i - 1]])\r\n                rank[SA[i]]++;\r\n        }\r\n       \
    \ // debug(SA);\r\n        for (int step = 1; rank[SA[N]] < N; step <<= 1) {\r\
    \n            // debug(step, SA[N], rank[SA[N]]);\r\n            for (int i =\
    \ 1; i <= N; i++) cntA[i] = cntB[i] = 0;\r\n            for (int i = 1; i <= N;\
    \ i++) {\r\n                cntA[A[i] = rank[i]]++;\r\n                cntB[B[i]\
    \ = (i + step <= N) ? rank[i + step] : 0]++;\r\n            }\r\n            for\
    \ (int i = 1; i <= N; i++) cntA[i] += cntA[i - 1], cntB[i] += cntB[i - 1];\r\n\
    \            for (int i = N; i >= 1; i--) tsa[cntB[B[i]]--] = i;\r\n         \
    \   for (int i = N; i >= 1; i--) SA[cntA[A[tsa[i]]]--] = tsa[i];\r\n         \
    \   rank[SA[1]] = 1;\r\n            for (int i = 2; i <= N; i++) {\r\n       \
    \         rank[SA[i]] = rank[SA[i - 1]];\r\n                if (A[SA[i]] != A[SA[i\
    \ - 1]] || B[SA[i]] != B[SA[i - 1]])\r\n                    rank[SA[i]]++;\r\n\
    \            }\r\n        }\r\n        int i, j, k = 0;\r\n        for (int i\
    \ = 1; i <= N; i++) {\r\n            if (k) k--;\r\n            j = SA[rank[i]\
    \ - 1];\r\n            while (i + k <= N && j + k <= N && ch[i + k] == ch[j +\
    \ k]) k++;\r\n            height[rank[i]] = k;\r\n        }\r\n        rmq.build(height,\
    \ [&](int a, int b) -> bool {\r\n            return a < b;\r\n        });\r\n\
    \    }\r\n\r\n    int get_length(int idx1, int idx2) {\r\n        // s \u7684\u4E0B\
    \u6807\r\n        int rk_idx1 = rank[idx1 + 1], rk_idx2 = rank[idx2 + 1];\r\n\
    \        if (rk_idx1 > rk_idx2) {\r\n            swap(rk_idx1, rk_idx2);\r\n \
    \       }\r\n        return rmq.rmq_value(rk_idx1 + 1, rk_idx2 + 1);\r\n    }\r\
    \n};\r\n"
  dependsOn:
  - src/data_structure/rmq.hpp
  isVerificationFile: false
  path: src/string/sa.h
  requiredBy: []
  timestamp: '2022-10-06 23:48:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/sa.h
layout: document
redirect_from:
- /library/src/string/sa.h
- /library/src/string/sa.h.html
title: Suffix Array
---
# Suffix Array

## 概要
Suffix Array 是一种用于快速查找字符串中所有后缀的数据结构。它的构造时间复杂度为 O(nlogn)，空间复杂度为 O(n)。它的应用有很多，比如在字符串匹配中，可以用于快速查找字符串中所有出现的子串。
### `SuffixArray`
`SuffixArray` 类是 Suffix Array 的核心类，它提供了一些方法来构造后缀数组。
- `SuffixArray(string &s)`: 构造一个 `SuffixArray` 类，用于构造字符串 `s` 的后缀数组。
- `int get_length(int idx1, int idx2)`: 返回字符串中下标为 `idx1` 和 `idx2` 的两个后缀的最长公共前缀的长度。

## 常见问题

## 题集