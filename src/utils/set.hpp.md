---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/set.md
    document_title: Set
    links:
    - https://atcoder.jp/contests/abc254/tasks/abc254_g
    - https://atcoder.jp/contests/abc256/tasks/abc256_h
    - https://leetcode.com/problems/count-integers-in-intervals/
  bundledCode: "#line 1 \"src/utils/set.hpp\"\n/*\r\n@brief Set\r\n@docs docs/set.md\r\
    \n*/\r\n// set \u5E38\u89C1\u4F7F\u7528\u5957\u8DEF\r\n// \u7EF4\u62A4\u533A\u95F4\
    \r\n/*\r\n\u73B0\u5728\u6A21\u677F\u7684\u903B\u8F91\uFF1A[l, r], [r+1, r2] =>\
    \ [l, r2], \u5982\u679C\u60F3\u6539\u6210 [l, r], [r, r2] => [l, r2] \u53EF\u4EE5\
    \u81EA\u5DF1\u53D8\u901A\r\nhttps://atcoder.jp/contests/abc254/tasks/abc254_g\r\
    \nhttps://leetcode.com/problems/count-integers-in-intervals/\r\nhttps://atcoder.jp/contests/abc256/tasks/abc256_h\r\
    \n*/\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\nclass CountIntervals\
    \ {\r\n    typedef pair<int, int> pii;\r\n\r\n    int ans = 0;\r\n    set<pii>\
    \ S;\r\n\r\n   public:\r\n    CountIntervals() {\r\n        ans = 0;\r\n     \
    \   S.clear();\r\n    }\r\n\r\n    void add(int left, int right) {\r\n       \
    \ auto it = S.lower_bound({left, -1});  // \u76EE\u7684\u662F\u60F3\u627E\u5230\
    \u7B2C\u4E00\u4E2A\u5305\u56F4 [left - 1, right + 1] \u7684\u533A\u95F4\u3002\r\
    \n        if (it != S.begin()) {\r\n            if (prev(it)->second >= left -\
    \ 1) {\r\n                it--;\r\n            }\r\n        }\r\n\r\n        int\
    \ L = left, R = right;\r\n        while (it != S.end()) {\r\n            if (it->first\
    \ > right + 1) break;\r\n            L = min(L, it->first);\r\n            R =\
    \ max(R, it->second);\r\n            ans -= it->second - it->first + 1;\r\n  \
    \          it = S.erase(it);\r\n        }\r\n        ans += R - L + 1;\r\n   \
    \     S.insert({L, R});\r\n    }\r\n\r\n    int count() {\r\n        return ans;\r\
    \n    }\r\n\r\n    pii get_interval(int idx) {\r\n        auto it = S.lower_bound({idx\
    \ + 1, -1});  // \u5199\u6CD5\u5F88\u5173\u952E\uFF0C\u627E\u6700\u540E\u4E00\u4E2A\
    \u5305\u56F4 idx \u7684\u533A\u95F4\u53EF\u4EE5\u8FD9\u4E48\u5199\r\n        if\
    \ (it == S.begin()) {\r\n            return {-1, -1};\r\n        }\r\n       \
    \ it--;\r\n        if (it->second < idx) {\r\n            return {-1, -1};\r\n\
    \        }\r\n        return *it;\r\n    }\r\n};\r\n"
  code: "/*\r\n@brief Set\r\n@docs docs/set.md\r\n*/\r\n// set \u5E38\u89C1\u4F7F\u7528\
    \u5957\u8DEF\r\n// \u7EF4\u62A4\u533A\u95F4\r\n/*\r\n\u73B0\u5728\u6A21\u677F\u7684\
    \u903B\u8F91\uFF1A[l, r], [r+1, r2] => [l, r2], \u5982\u679C\u60F3\u6539\u6210\
    \ [l, r], [r, r2] => [l, r2] \u53EF\u4EE5\u81EA\u5DF1\u53D8\u901A\r\nhttps://atcoder.jp/contests/abc254/tasks/abc254_g\r\
    \nhttps://leetcode.com/problems/count-integers-in-intervals/\r\nhttps://atcoder.jp/contests/abc256/tasks/abc256_h\r\
    \n*/\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\nclass CountIntervals\
    \ {\r\n    typedef pair<int, int> pii;\r\n\r\n    int ans = 0;\r\n    set<pii>\
    \ S;\r\n\r\n   public:\r\n    CountIntervals() {\r\n        ans = 0;\r\n     \
    \   S.clear();\r\n    }\r\n\r\n    void add(int left, int right) {\r\n       \
    \ auto it = S.lower_bound({left, -1});  // \u76EE\u7684\u662F\u60F3\u627E\u5230\
    \u7B2C\u4E00\u4E2A\u5305\u56F4 [left - 1, right + 1] \u7684\u533A\u95F4\u3002\r\
    \n        if (it != S.begin()) {\r\n            if (prev(it)->second >= left -\
    \ 1) {\r\n                it--;\r\n            }\r\n        }\r\n\r\n        int\
    \ L = left, R = right;\r\n        while (it != S.end()) {\r\n            if (it->first\
    \ > right + 1) break;\r\n            L = min(L, it->first);\r\n            R =\
    \ max(R, it->second);\r\n            ans -= it->second - it->first + 1;\r\n  \
    \          it = S.erase(it);\r\n        }\r\n        ans += R - L + 1;\r\n   \
    \     S.insert({L, R});\r\n    }\r\n\r\n    int count() {\r\n        return ans;\r\
    \n    }\r\n\r\n    pii get_interval(int idx) {\r\n        auto it = S.lower_bound({idx\
    \ + 1, -1});  // \u5199\u6CD5\u5F88\u5173\u952E\uFF0C\u627E\u6700\u540E\u4E00\u4E2A\
    \u5305\u56F4 idx \u7684\u533A\u95F4\u53EF\u4EE5\u8FD9\u4E48\u5199\r\n        if\
    \ (it == S.begin()) {\r\n            return {-1, -1};\r\n        }\r\n       \
    \ it--;\r\n        if (it->second < idx) {\r\n            return {-1, -1};\r\n\
    \        }\r\n        return *it;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utils/set.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utils/set.hpp
layout: document
redirect_from:
- /library/src/utils/set.hpp
- /library/src/utils/set.hpp.html
title: Set
---
# Set

## 概要
记录 set 常见使用套路

### `CountIntervals`
维护一个区间集合，求出区间集合中包含的整数个数
- `void add(int left, int right)`: 向集合中添加一个区间 `[left, right]` 。
- `int count()`: 求出集合中包含的整数个数。
- `pii get_interval(int idx)`: 求出包含 `idx` 的区间。如果没有包含 `idx` 的区间，返回 `{-1, -1}` 。

## 常见问题

## 题集
- https://atcoder.jp/contests/abc254/tasks/abc254_g
- https://leetcode.com/problems/count-integers-in-intervals/
- https://atcoder.jp/contests/abc256/tasks/abc256_h