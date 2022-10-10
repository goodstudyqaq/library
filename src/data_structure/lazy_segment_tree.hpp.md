---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/lazy_segment_tree.test.cpp
    title: test/data_structure/lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lazy_segment_tree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 1 \"src/data_structure/lazy_segment_tree.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief Lazy Segment Tree\r\n@docs docs/lazy_segment_tree.md\r\
    \n*/\r\n\r\n/*\r\n */\r\nstruct Tag {\r\n    // \u9ED8\u8BA4\u503C\r\n    Tag()\
    \ {}\r\n    // apply \u4E4B\u524D\u9700\u8981\u5224\u65AD v \u662F\u5426\u4E3A\
    \u9ED8\u8BA4\u503C\r\n    void apply(const Tag &v, int l, int r) {}\r\n};\r\n\r\
    \nstruct Info {\r\n    // \u9ED8\u8BA4\u503C\r\n    Info() {}\r\n\r\n    // apply\
    \ \u4E4B\u524D\u9700\u8981\u5224\u65AD v \u662F\u5426\u4E3A\u9ED8\u8BA4\u503C\r\
    \n    void apply(const Tag &v, int l, int r) {}\r\n\r\n    static Info merge(const\
    \ Info &left_info, const Info &right_info, int l, int r) { return Info(); }\r\n\
    };\r\n\r\n#define lson l, m, rt << 1\r\n#define rson m + 1, r, rt << 1 | 1\r\n\
    template <typename Info, typename Tag>\r\nstruct LazySegmentTree {\r\n    LazySegmentTree(int\
    \ n) : n(n), merge(Info::merge), info(4 << std::__lg(n)), tag(4 << std::__lg(n))\
    \ {}\r\n    LazySegmentTree(vector<Info> &init) : LazySegmentTree(init.size())\
    \ {\r\n        function<void(int, int, int)> build = [&](int l, int r, int rt)\
    \ {\r\n            if (l == r) {\r\n                info[rt] = init[l];\r\n  \
    \              return;\r\n            }\r\n            int m = l + r >> 1;\r\n\
    \            build(lson);\r\n            build(rson);\r\n            push_up(rt,\
    \ l, r);\r\n        };\r\n        build(0, n - 1, 1);\r\n    }\r\n\r\n    void\
    \ update(int L, const Info &v) {\r\n        update(L, v, 0, n - 1, 1);\r\n   \
    \ }\r\n\r\n    void rangeUpdate(int L, int R, const Tag &v) {\r\n        return\
    \ rangeUpdate(L, R, v, 0, n - 1, 1);\r\n    }\r\n\r\n    Info rangeQuery(int L,\
    \ int R) {\r\n        return rangeQuery(L, R, 0, n - 1, 1);\r\n    }\r\n\r\n \
    \   int find_first(int ll, int rr, const function<bool(const Info &)> &f) {\r\n\
    \        return find_first(ll, rr, f, 0, n - 1, 1);\r\n    }\r\n\r\n    int find_last(int\
    \ ll, int rr, const function<bool(const Info &)> &f) {\r\n        return find_last(ll,\
    \ rr, f, 0, n - 1, 1);\r\n    }\r\n\r\n   private:\r\n    const int n;\r\n   \
    \ vector<Info> info;\r\n    vector<Tag> tag;\r\n    const function<Info(const\
    \ Info &, const Info &, int, int)> merge;\r\n    void push_up(int l, int r, int\
    \ rt) {\r\n        info[rt] = merge(info[rt << 1], info[rt << 1 | 1], l, r);\r\
    \n    }\r\n\r\n    void apply(int p, const Tag &v, int l, int r) {\r\n       \
    \ info[p].apply(v, l, r);\r\n        tag[p].apply(v, l, r);\r\n    }\r\n\r\n \
    \   void push_down(int l, int r, int rt) {\r\n        int m = l + r >> 1;\r\n\
    \        apply(rt << 1, tag[rt], l, m);\r\n        apply(rt << 1 | 1, tag[rt],\
    \ m + 1, r);\r\n        tag[rt] = Tag();\r\n    }\r\n\r\n    void update(int L,\
    \ const Info &v, int l, int r, int rt) {\r\n        if (l == r) {\r\n        \
    \    info[rt] = v;\r\n            return;\r\n        }\r\n        int m = l +\
    \ r >> 1;\r\n        push_down(l, r, rt);\r\n        if (L <= m) {\r\n       \
    \     update(L, v, lson);\r\n        } else {\r\n            update(L, v, rson);\r\
    \n        }\r\n        push_up(l, r, rt);\r\n    }\r\n\r\n    Info rangeQuery(int\
    \ L, int R, int l, int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n   \
    \         return info[rt];\r\n        }\r\n        int m = l + r >> 1;\r\n   \
    \     push_down(l, r, rt);\r\n        if (L <= m && R > m) {\r\n            return\
    \ merge(rangeQuery(L, R, lson), rangeQuery(L, R, rson), l, r);\r\n        } else\
    \ if (L <= m) {\r\n            return rangeQuery(L, R, lson);\r\n        } else\
    \ {\r\n            return rangeQuery(L, R, rson);\r\n        }\r\n    }\r\n\r\n\
    \    void rangeUpdate(int L, int R, const Tag &v, int l, int r, int rt) {\r\n\
    \        if (L <= l && r <= R) {\r\n            apply(rt, v, l, r);\r\n      \
    \      return;\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(l,\
    \ r, rt);\r\n        if (L <= m) {\r\n            rangeUpdate(L, R, v, lson);\r\
    \n        }\r\n        if (R > m) {\r\n            rangeUpdate(L, R, v, rson);\r\
    \n        }\r\n        push_up(l, r, rt);\r\n    }\r\n\r\n    int find_first_knowingly(const\
    \ function<bool(const Info &)> f, int l, int r, int rt) {\r\n        if (l ==\
    \ r) {\r\n            return l;\r\n        }\r\n        int m = l + r >> 1;\r\n\
    \        push_down(l, r, rt);\r\n        int res;\r\n        if (f(info[rt <<\
    \ 1])) {\r\n            res = find_first_knowingly(f, lson);\r\n        } else\
    \ {\r\n            res = find_first_knowingly(f, rson);\r\n        }\r\n     \
    \   push_up(l, r, rt);\r\n        return res;\r\n    }\r\n\r\n    int find_first(int\
    \ L, int R, const function<bool(const Info &)> f, int l, int r, int rt) {\r\n\
    \        if (L <= l && r <= R) {\r\n            if (!f(info[rt])) {\r\n      \
    \          return -1;\r\n            }\r\n            return find_first_knowingly(f,\
    \ l, r, rt);\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(l,\
    \ r, rt);\r\n        int res = -1;\r\n        if (L <= m) {\r\n            res\
    \ = find_first(L, R, f, lson);\r\n        }\r\n        if (R > m && res == -1)\
    \ {\r\n            res = find_first(L, R, f, rson);\r\n        }\r\n        push_up(l,\
    \ r, rt);\r\n        return res;\r\n    }\r\n\r\n    int find_last_knowingly(const\
    \ function<bool(const Info &)> f, int l, int r, int rt) {\r\n        if (l ==\
    \ r) {\r\n            return l;\r\n        }\r\n        int m = l + r >> 1;\r\n\
    \        push_down(l, r, rt);\r\n        int res;\r\n        if (f(info[rt <<\
    \ 1 | 1])) {\r\n            res = find_last_knowingly(f, rson);\r\n        } else\
    \ {\r\n            res = find_last_knowingly(f, lson);\r\n        }\r\n      \
    \  push_up(l, r, rt);\r\n        return res;\r\n    }\r\n\r\n    int find_last(int\
    \ L, int R, const function<bool(const Info &)> f, int l, int r, int rt) {\r\n\
    \        if (L <= l && r <= R) {\r\n            if (!f(info[rt])) {\r\n      \
    \          return -1;\r\n            }\r\n            return find_last_knowingly(f,\
    \ l, r, rt);\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(l,\
    \ r, rt);\r\n        int res = -1;\r\n        if (R > m) {\r\n            res\
    \ = find_last(L, R, f, rson);\r\n        }\r\n        if (L <= m && res == -1)\
    \ {\r\n            res = find_last(L, R, f, lson);\r\n        }\r\n        push_up(l,\
    \ r, rt);\r\n        return res;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Lazy Segment\
    \ Tree\r\n@docs docs/lazy_segment_tree.md\r\n*/\r\n\r\n/*\r\n */\r\nstruct Tag\
    \ {\r\n    // \u9ED8\u8BA4\u503C\r\n    Tag() {}\r\n    // apply \u4E4B\u524D\u9700\
    \u8981\u5224\u65AD v \u662F\u5426\u4E3A\u9ED8\u8BA4\u503C\r\n    void apply(const\
    \ Tag &v, int l, int r) {}\r\n};\r\n\r\nstruct Info {\r\n    // \u9ED8\u8BA4\u503C\
    \r\n    Info() {}\r\n\r\n    // apply \u4E4B\u524D\u9700\u8981\u5224\u65AD v \u662F\
    \u5426\u4E3A\u9ED8\u8BA4\u503C\r\n    void apply(const Tag &v, int l, int r) {}\r\
    \n\r\n    static Info merge(const Info &left_info, const Info &right_info, int\
    \ l, int r) { return Info(); }\r\n};\r\n\r\n#define lson l, m, rt << 1\r\n#define\
    \ rson m + 1, r, rt << 1 | 1\r\ntemplate <typename Info, typename Tag>\r\nstruct\
    \ LazySegmentTree {\r\n    LazySegmentTree(int n) : n(n), merge(Info::merge),\
    \ info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}\r\n    LazySegmentTree(vector<Info>\
    \ &init) : LazySegmentTree(init.size()) {\r\n        function<void(int, int, int)>\
    \ build = [&](int l, int r, int rt) {\r\n            if (l == r) {\r\n       \
    \         info[rt] = init[l];\r\n                return;\r\n            }\r\n\
    \            int m = l + r >> 1;\r\n            build(lson);\r\n            build(rson);\r\
    \n            push_up(rt, l, r);\r\n        };\r\n        build(0, n - 1, 1);\r\
    \n    }\r\n\r\n    void update(int L, const Info &v) {\r\n        update(L, v,\
    \ 0, n - 1, 1);\r\n    }\r\n\r\n    void rangeUpdate(int L, int R, const Tag &v)\
    \ {\r\n        return rangeUpdate(L, R, v, 0, n - 1, 1);\r\n    }\r\n\r\n    Info\
    \ rangeQuery(int L, int R) {\r\n        return rangeQuery(L, R, 0, n - 1, 1);\r\
    \n    }\r\n\r\n    int find_first(int ll, int rr, const function<bool(const Info\
    \ &)> &f) {\r\n        return find_first(ll, rr, f, 0, n - 1, 1);\r\n    }\r\n\
    \r\n    int find_last(int ll, int rr, const function<bool(const Info &)> &f) {\r\
    \n        return find_last(ll, rr, f, 0, n - 1, 1);\r\n    }\r\n\r\n   private:\r\
    \n    const int n;\r\n    vector<Info> info;\r\n    vector<Tag> tag;\r\n    const\
    \ function<Info(const Info &, const Info &, int, int)> merge;\r\n    void push_up(int\
    \ l, int r, int rt) {\r\n        info[rt] = merge(info[rt << 1], info[rt << 1\
    \ | 1], l, r);\r\n    }\r\n\r\n    void apply(int p, const Tag &v, int l, int\
    \ r) {\r\n        info[p].apply(v, l, r);\r\n        tag[p].apply(v, l, r);\r\n\
    \    }\r\n\r\n    void push_down(int l, int r, int rt) {\r\n        int m = l\
    \ + r >> 1;\r\n        apply(rt << 1, tag[rt], l, m);\r\n        apply(rt << 1\
    \ | 1, tag[rt], m + 1, r);\r\n        tag[rt] = Tag();\r\n    }\r\n\r\n    void\
    \ update(int L, const Info &v, int l, int r, int rt) {\r\n        if (l == r)\
    \ {\r\n            info[rt] = v;\r\n            return;\r\n        }\r\n     \
    \   int m = l + r >> 1;\r\n        push_down(l, r, rt);\r\n        if (L <= m)\
    \ {\r\n            update(L, v, lson);\r\n        } else {\r\n            update(L,\
    \ v, rson);\r\n        }\r\n        push_up(l, r, rt);\r\n    }\r\n\r\n    Info\
    \ rangeQuery(int L, int R, int l, int r, int rt) {\r\n        if (L <= l && r\
    \ <= R) {\r\n            return info[rt];\r\n        }\r\n        int m = l +\
    \ r >> 1;\r\n        push_down(l, r, rt);\r\n        if (L <= m && R > m) {\r\n\
    \            return merge(rangeQuery(L, R, lson), rangeQuery(L, R, rson), l, r);\r\
    \n        } else if (L <= m) {\r\n            return rangeQuery(L, R, lson);\r\
    \n        } else {\r\n            return rangeQuery(L, R, rson);\r\n        }\r\
    \n    }\r\n\r\n    void rangeUpdate(int L, int R, const Tag &v, int l, int r,\
    \ int rt) {\r\n        if (L <= l && r <= R) {\r\n            apply(rt, v, l,\
    \ r);\r\n            return;\r\n        }\r\n        int m = l + r >> 1;\r\n \
    \       push_down(l, r, rt);\r\n        if (L <= m) {\r\n            rangeUpdate(L,\
    \ R, v, lson);\r\n        }\r\n        if (R > m) {\r\n            rangeUpdate(L,\
    \ R, v, rson);\r\n        }\r\n        push_up(l, r, rt);\r\n    }\r\n\r\n   \
    \ int find_first_knowingly(const function<bool(const Info &)> f, int l, int r,\
    \ int rt) {\r\n        if (l == r) {\r\n            return l;\r\n        }\r\n\
    \        int m = l + r >> 1;\r\n        push_down(l, r, rt);\r\n        int res;\r\
    \n        if (f(info[rt << 1])) {\r\n            res = find_first_knowingly(f,\
    \ lson);\r\n        } else {\r\n            res = find_first_knowingly(f, rson);\r\
    \n        }\r\n        push_up(l, r, rt);\r\n        return res;\r\n    }\r\n\r\
    \n    int find_first(int L, int R, const function<bool(const Info &)> f, int l,\
    \ int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n            if (!f(info[rt]))\
    \ {\r\n                return -1;\r\n            }\r\n            return find_first_knowingly(f,\
    \ l, r, rt);\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(l,\
    \ r, rt);\r\n        int res = -1;\r\n        if (L <= m) {\r\n            res\
    \ = find_first(L, R, f, lson);\r\n        }\r\n        if (R > m && res == -1)\
    \ {\r\n            res = find_first(L, R, f, rson);\r\n        }\r\n        push_up(l,\
    \ r, rt);\r\n        return res;\r\n    }\r\n\r\n    int find_last_knowingly(const\
    \ function<bool(const Info &)> f, int l, int r, int rt) {\r\n        if (l ==\
    \ r) {\r\n            return l;\r\n        }\r\n        int m = l + r >> 1;\r\n\
    \        push_down(l, r, rt);\r\n        int res;\r\n        if (f(info[rt <<\
    \ 1 | 1])) {\r\n            res = find_last_knowingly(f, rson);\r\n        } else\
    \ {\r\n            res = find_last_knowingly(f, lson);\r\n        }\r\n      \
    \  push_up(l, r, rt);\r\n        return res;\r\n    }\r\n\r\n    int find_last(int\
    \ L, int R, const function<bool(const Info &)> f, int l, int r, int rt) {\r\n\
    \        if (L <= l && r <= R) {\r\n            if (!f(info[rt])) {\r\n      \
    \          return -1;\r\n            }\r\n            return find_last_knowingly(f,\
    \ l, r, rt);\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(l,\
    \ r, rt);\r\n        int res = -1;\r\n        if (R > m) {\r\n            res\
    \ = find_last(L, R, f, rson);\r\n        }\r\n        if (L <= m && res == -1)\
    \ {\r\n            res = find_last(L, R, f, lson);\r\n        }\r\n        push_up(l,\
    \ r, rt);\r\n        return res;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-10-10 22:43:43+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/lazy_segment_tree.test.cpp
documentation_of: src/data_structure/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/lazy_segment_tree.hpp
- /library/src/data_structure/lazy_segment_tree.hpp.html
title: Lazy Segment Tree
---
# Lazy Segment Tree

## 概要
带懒惰标签的线段树, 时间复杂度均为 $O(\log n)$ 。主要由以下几个部分组成:
### `Tag`
`Tag` 为懒惰标签, 用于记录当前节点的信息, 例如 `add` 操作, `min` 操作, `max` 操作等等。使用时需要实现 `apply` 方法, 用于将标签 `v` 的值下放到当前节点上。


### `Info`
`Info` 为当前节点的信息, 例如 `sum` 操作, `min` 操作, `max` 操作等等。使用时需要实现 `operation+` 方法, 用于合并两个节点的信息; 以及 `apply` 方法, 用于将懒惰标签 `v` 的值下放到当前节点上。


### `LazySegmentTree`
算法的主体, 用于维护线段树。依赖 `Tag` 和 `Info` 两个类。主要有以下几个方法:
- `LazySegmentTree(int n)` : 构造一个长度为 `n` 的线段树
- `LazySegmentTree(vector<Info> &init)` : 构造一个长度为 `init.size()` 的线段树, 并将 `init` 中的值赋值给线段树。区间范围为 `[0, init.size())`
- `void update(int L, const Info &v)`: 将 `L` 位置的值更新为 `v`
- `void rangeUpdate(int L, int R, const Tag &v)` : 将 `[L, R]` 区间的值更新为 `v`
- `Info rangeQuery(int L, int R)` : 查询 `[L, R]` 区间的值
- `int find_first(int ll, int rr, const function<bool(const Info &)> &f)` : 在 `[ll, rr]` 区间内找到第一个满足 `f` 的位置, 如果不存在则返回 `-1`
- `int find_last(int ll, int rr, const function<bool(const Info &)> &f)` : 在 `[ll, rr]` 区间内找到最后一个满足 `f` 的位置, 如果不存在则返回 `-1`

## 常见问题

## 题集
- https://atcoder.jp/contests/abc256/tasks/abc256_h
- https://atcoder.jp/contests/abc248/tasks/abc248_h

