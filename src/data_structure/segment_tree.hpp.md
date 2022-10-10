---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/segment_tree.test.cpp
    title: test/data_structure/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment_tree.md
    document_title: "\u7EBF\u6BB5\u6811"
    links: []
  bundledCode: "#line 1 \"src/data_structure/segment_tree.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief \u7EBF\u6BB5\u6811\r\n@docs docs/segment_tree.md\r\
    \n*/\r\nstruct Info {\r\n    // \u9ED8\u8BA4\u503C\r\n    Info() {}\r\n    static\
    \ Info merge(const Info& left_info, const Info& right_info, int l, int r) { return\
    \ Info(); };\r\n};\r\n\r\n#define lson l, m, rt << 1\r\n#define rson m + 1, r,\
    \ rt << 1 | 1\r\ntemplate <typename Info>\r\nstruct SegmentTree {\r\n    SegmentTree(int\
    \ n) : n(n), merge(Info::merge), info(4 << __lg(n)) {}\r\n    SegmentTree(vector<Info>\
    \ init) : SegmentTree(init.size()) {\r\n        function<void(int, int, int)>\
    \ build = [&](int l, int r, int rt) {\r\n            if (l == r) {\r\n       \
    \         info[rt] = init[l];\r\n                return;\r\n            }\r\n\
    \            int m = l + r >> 1;\r\n            build(lson);\r\n            build(rson);\r\
    \n            push_up(rt, l, r);\r\n        };\r\n        build(0, n - 1, 1);\r\
    \n    }\r\n\r\n    Info rangeQuery(int l, int r) {\r\n        return rangeQuery(l,\
    \ r, 0, n - 1, 1);\r\n    }\r\n\r\n    // \u5355\u70B9\u66F4\u65B0, \u4F1A\u5C06\
    \u4E0B\u6807\u4E3A L \u7684\u70B9\u4E0E v \u8FDB\u884C merge \u64CD\u4F5C\r\n\
    \    void update(int L, const Info& v) {\r\n        return update(L, v, 0, n -\
    \ 1, 1);\r\n    }\r\n\r\n    // \u5355\u70B9\u8D4B\u503C, \u4F1A\u5C06\u4E0B\u6807\
    \u4E3A L \u7684\u70B9\u76F4\u63A5\u8D4B\u503C\u4E3A v\r\n    void assign(int L,\
    \ const Info& v) {\r\n        return assign(L, v, 0, n - 1, 1);\r\n    }\r\n\r\
    \n   private:\r\n    const int n;\r\n    vector<Info> info;\r\n    const function<Info(const\
    \ Info&, const Info&, int, int)> merge;\r\n\r\n    void push_up(int rt, int l,\
    \ int r) {\r\n        info[rt] = merge(info[rt << 1], info[rt << 1 | 1], l, r);\r\
    \n    }\r\n\r\n    Info rangeQuery(int L, int R, int l, int r, int rt) {\r\n \
    \       if (L <= l && r <= R) {\r\n            return info[rt];\r\n        }\r\
    \n        int m = l + r >> 1;\r\n        if (L <= m && R > m) {\r\n          \
    \  return merge(rangeQuery(L, R, lson), rangeQuery(L, R, rson), l, r);\r\n   \
    \     } else if (L <= m) {\r\n            return rangeQuery(L, R, lson);\r\n \
    \       } else {\r\n            return rangeQuery(L, R, rson);\r\n        }\r\n\
    \    }\r\n\r\n    void update(int L, const Info& v, int l, int r, int rt) {\r\n\
    \        if (l == r) {\r\n            info[rt] = merge(info[rt], v, l, r);\r\n\
    \            return;\r\n        }\r\n        int m = l + r >> 1;\r\n        if\
    \ (L <= m) {\r\n            update(L, v, lson);\r\n        } else {\r\n      \
    \      update(L, v, rson);\r\n        }\r\n        push_up(rt, l, r);\r\n    }\r\
    \n\r\n    void assign(int L, const Info& v, int l, int r, int rt) {\r\n      \
    \  if (l == r) {\r\n            info[rt] = v;\r\n            return;\r\n     \
    \   }\r\n        int m = l + r >> 1;\r\n        if (L <= m) {\r\n            assign(L,\
    \ v, lson);\r\n        } else {\r\n            assign(L, v, rson);\r\n       \
    \ }\r\n        push_up(rt, l, r);\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u7EBF\u6BB5\
    \u6811\r\n@docs docs/segment_tree.md\r\n*/\r\nstruct Info {\r\n    // \u9ED8\u8BA4\
    \u503C\r\n    Info() {}\r\n    static Info merge(const Info& left_info, const\
    \ Info& right_info, int l, int r) { return Info(); };\r\n};\r\n\r\n#define lson\
    \ l, m, rt << 1\r\n#define rson m + 1, r, rt << 1 | 1\r\ntemplate <typename Info>\r\
    \nstruct SegmentTree {\r\n    SegmentTree(int n) : n(n), merge(Info::merge), info(4\
    \ << __lg(n)) {}\r\n    SegmentTree(vector<Info> init) : SegmentTree(init.size())\
    \ {\r\n        function<void(int, int, int)> build = [&](int l, int r, int rt)\
    \ {\r\n            if (l == r) {\r\n                info[rt] = init[l];\r\n  \
    \              return;\r\n            }\r\n            int m = l + r >> 1;\r\n\
    \            build(lson);\r\n            build(rson);\r\n            push_up(rt,\
    \ l, r);\r\n        };\r\n        build(0, n - 1, 1);\r\n    }\r\n\r\n    Info\
    \ rangeQuery(int l, int r) {\r\n        return rangeQuery(l, r, 0, n - 1, 1);\r\
    \n    }\r\n\r\n    // \u5355\u70B9\u66F4\u65B0, \u4F1A\u5C06\u4E0B\u6807\u4E3A\
    \ L \u7684\u70B9\u4E0E v \u8FDB\u884C merge \u64CD\u4F5C\r\n    void update(int\
    \ L, const Info& v) {\r\n        return update(L, v, 0, n - 1, 1);\r\n    }\r\n\
    \r\n    // \u5355\u70B9\u8D4B\u503C, \u4F1A\u5C06\u4E0B\u6807\u4E3A L \u7684\u70B9\
    \u76F4\u63A5\u8D4B\u503C\u4E3A v\r\n    void assign(int L, const Info& v) {\r\n\
    \        return assign(L, v, 0, n - 1, 1);\r\n    }\r\n\r\n   private:\r\n   \
    \ const int n;\r\n    vector<Info> info;\r\n    const function<Info(const Info&,\
    \ const Info&, int, int)> merge;\r\n\r\n    void push_up(int rt, int l, int r)\
    \ {\r\n        info[rt] = merge(info[rt << 1], info[rt << 1 | 1], l, r);\r\n \
    \   }\r\n\r\n    Info rangeQuery(int L, int R, int l, int r, int rt) {\r\n   \
    \     if (L <= l && r <= R) {\r\n            return info[rt];\r\n        }\r\n\
    \        int m = l + r >> 1;\r\n        if (L <= m && R > m) {\r\n           \
    \ return merge(rangeQuery(L, R, lson), rangeQuery(L, R, rson), l, r);\r\n    \
    \    } else if (L <= m) {\r\n            return rangeQuery(L, R, lson);\r\n  \
    \      } else {\r\n            return rangeQuery(L, R, rson);\r\n        }\r\n\
    \    }\r\n\r\n    void update(int L, const Info& v, int l, int r, int rt) {\r\n\
    \        if (l == r) {\r\n            info[rt] = merge(info[rt], v, l, r);\r\n\
    \            return;\r\n        }\r\n        int m = l + r >> 1;\r\n        if\
    \ (L <= m) {\r\n            update(L, v, lson);\r\n        } else {\r\n      \
    \      update(L, v, rson);\r\n        }\r\n        push_up(rt, l, r);\r\n    }\r\
    \n\r\n    void assign(int L, const Info& v, int l, int r, int rt) {\r\n      \
    \  if (l == r) {\r\n            info[rt] = v;\r\n            return;\r\n     \
    \   }\r\n        int m = l + r >> 1;\r\n        if (L <= m) {\r\n            assign(L,\
    \ v, lson);\r\n        } else {\r\n            assign(L, v, rson);\r\n       \
    \ }\r\n        push_up(rt, l, r);\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2022-10-10 22:48:16+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/segment_tree.test.cpp
documentation_of: src/data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segment_tree.hpp
- /library/src/data_structure/segment_tree.hpp.html
title: "\u7EBF\u6BB5\u6811"
---
# 线段树

## 概要
线段树是一种用于维护区间信息的数据结构。它的基本操作是维护区间信息，查询区间信息，修改区间信息。时间复杂度均为 $O(\log n)$ 。
该模板主要分为 2 个部分。

### `Info`
`Info` 是一个结构体，用于存储区间信息。使用时需要实现 `operation+` 方法, 用于合并两个节点的信息.

### `SegmentTree`
`SegmentTree` 是一个线段树的实现，主要有以下几个方法:
- `SegmentTree(int n)` : 构造函数，传入数组的长度。区间默认为 `[0, n)` 。
- `SegmentTree(vector<Info> init)` : 构造函数，传入一个数组。区间默认为 `[0, init.size())` 。
- `Info rangeQuery(int l, int r)`: 查询区间 `[l, r]` 的信息。
- `void update(int L, Info v)` : 将区间 `[L, L]` 的信息更新为 `v`。


## 常见问题

## 题集
