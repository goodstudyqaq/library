---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/lazy_segment_tree.md
    document_title: "Lazy \u7EBF\u6BB5\u6811"
    links:
    - https://atcoder.jp/contests/abc248/tasks/abc248_h
    - https://atcoder.jp/contests/abc256/tasks/abc256_h
  bundledCode: "#line 1 \"src/data_structure/lazySegmentTree.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief Lazy \u7EBF\u6BB5\u6811\r\n@docs docs/lazy_segment_tree.md\r\
    \n*/\r\n\r\n/*\r\nhttps://atcoder.jp/contests/abc256/tasks/abc256_h\r\nhttps://atcoder.jp/contests/abc248/tasks/abc248_h\r\
    \n*/\r\n#define lson l, m, rt << 1\r\n#define rson m + 1, r, rt << 1 | 1\r\ntemplate\
    \ <class Info, class Tag, class Merge = std::plus<Info>>\r\nstruct LazySegmentTree\
    \ {\r\n    LazySegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)),\
    \ tag(4 << std::__lg(n)) {}\r\n    LazySegmentTree(vector<Info> &init) : LazySegmentTree(init.size())\
    \ {\r\n        function<void(int, int, int)> build = [&](int l, int r, int rt)\
    \ {\r\n            if (l == r) {\r\n                info[rt] = init[l];\r\n  \
    \              return;\r\n            }\r\n            int m = l + r >> 1;\r\n\
    \            build(lson);\r\n            build(rson);\r\n            push_up(rt);\r\
    \n        };\r\n        build(0, n - 1, 1);\r\n    }\r\n\r\n    void update(int\
    \ L, const Info &v) {\r\n        update(L, v, 0, n - 1, 1);\r\n    }\r\n\r\n \
    \   void rangeUpdate(int L, int R, const Tag &v) {\r\n        return rangeUpdate(L,\
    \ R, v, 0, n - 1, 1);\r\n    }\r\n\r\n    Info rangeQuery(int L, int R) {\r\n\
    \        return rangeQuery(L, R, 0, n - 1, 1);\r\n    }\r\n\r\n    int find_first(int\
    \ ll, int rr, const function<bool(const Info &)> &f) {\r\n        return find_first(ll,\
    \ rr, f, 0, n - 1, 1);\r\n    }\r\n\r\n    int find_last(int ll, int rr, const\
    \ function<bool(const Info &)> &f) {\r\n        return find_last(ll, rr, f, 0,\
    \ n - 1, 1);\r\n    }\r\n\r\n   private:\r\n    const int n;\r\n    const Merge\
    \ merge;\r\n    vector<Info> info;\r\n    vector<Tag> tag;\r\n    void push_up(int\
    \ rt) {\r\n        info[rt] = merge(info[rt << 1], info[rt << 1 | 1]);\r\n   \
    \ }\r\n\r\n    void apply(int p, const Tag &v) {\r\n        info[p].apply(v);\r\
    \n        tag[p].apply(v);\r\n    }\r\n\r\n    void push_down(int rt) {\r\n  \
    \      apply(rt << 1, tag[rt]);\r\n        apply(rt << 1 | 1, tag[rt]);\r\n  \
    \      tag[rt] = Tag();\r\n    }\r\n\r\n    void update(int L, const Info &v,\
    \ int l, int r, int rt) {\r\n        if (l == r) {\r\n            info[rt] = v;\r\
    \n            return;\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(rt);\r\
    \n        if (L <= m) {\r\n            update(L, v, lson);\r\n        } else {\r\
    \n            update(L, v, rson);\r\n        }\r\n        push_up(rt);\r\n   \
    \ }\r\n\r\n    Info rangeQuery(int L, int R, int l, int r, int rt) {\r\n     \
    \   if (L <= l && r <= R) {\r\n            return info[rt];\r\n        }\r\n \
    \       int m = l + r >> 1;\r\n        push_down(rt);\r\n        if (L <= m &&\
    \ R > m) {\r\n            return merge(rangeQuery(L, R, lson), rangeQuery(L, R,\
    \ rson));\r\n        } else if (L <= m) {\r\n            return rangeQuery(L,\
    \ R, lson);\r\n        } else {\r\n            return rangeQuery(L, R, rson);\r\
    \n        }\r\n    }\r\n\r\n    void rangeUpdate(int L, int R, const Tag &v, int\
    \ l, int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n            apply(rt,\
    \ v);\r\n            return;\r\n        }\r\n        int m = l + r >> 1;\r\n \
    \       push_down(rt);\r\n        if (L <= m) {\r\n            rangeUpdate(L,\
    \ R, v, lson);\r\n        }\r\n        if (R > m) {\r\n            rangeUpdate(L,\
    \ R, v, rson);\r\n        }\r\n        push_up(rt);\r\n    }\r\n\r\n    int find_first_knowingly(const\
    \ function<bool(const Info &)> f, int l, int r, int rt) {\r\n        if (l ==\
    \ r) {\r\n            return l;\r\n        }\r\n        int m = l + r >> 1;\r\n\
    \        push_down(rt);\r\n        int res;\r\n        if (f(info[rt << 1])) {\r\
    \n            res = find_first_knowingly(f, lson);\r\n        } else {\r\n   \
    \         res = find_first_knowingly(f, rson);\r\n        }\r\n        push_up(rt);\r\
    \n        return res;\r\n    }\r\n\r\n    int find_first(int L, int R, const function<bool(const\
    \ Info &)> f, int l, int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n \
    \           if (!f(info[rt])) {\r\n                return -1;\r\n            }\r\
    \n            return find_first_knowingly(f, l, r, rt);\r\n        }\r\n     \
    \   int m = l + r >> 1;\r\n        push_down(rt);\r\n        int res = -1;\r\n\
    \        if (L <= m) {\r\n            res = find_first(L, R, f, lson);\r\n   \
    \     }\r\n        if (R > m && res == -1) {\r\n            res = find_first(L,\
    \ R, f, rson);\r\n        }\r\n        push_up(rt);\r\n        return res;\r\n\
    \    }\r\n\r\n    int find_last_knowingly(const function<bool(const Info &)> f,\
    \ int l, int r, int rt) {\r\n        if (l == r) {\r\n            return l;\r\n\
    \        }\r\n        int m = l + r >> 1;\r\n        push_down(rt);\r\n      \
    \  int res;\r\n        if (f(info[rt << 1 | 1])) {\r\n            res = find_last_knowingly(f,\
    \ rson);\r\n        } else {\r\n            res = find_last_knowingly(f, lson);\r\
    \n        }\r\n        push_up(rt);\r\n        return res;\r\n    }\r\n\r\n  \
    \  int find_last(int L, int R, const function<bool(const Info &)> f, int l, int\
    \ r, int rt) {\r\n        if (L <= l && r <= R) {\r\n            if (!f(info[rt]))\
    \ {\r\n                return -1;\r\n            }\r\n            return find_last_knowingly(f,\
    \ l, r, rt);\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(rt);\r\
    \n        int res = -1;\r\n        if (R > m) {\r\n            res = find_last(L,\
    \ R, f, rson);\r\n        }\r\n        if (L <= m && res == -1) {\r\n        \
    \    res = find_last(L, R, f, lson);\r\n        }\r\n        push_up(rt);\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\nconst int inf = 1e6;\r\nstruct Tag\
    \ {\r\n    int x;\r\n    Tag(int _x) : x(_x) {}\r\n    Tag() { x = 0; }\r\n  \
    \  void apply(const Tag &v) {\r\n        x += v.x;\r\n    }\r\n};\r\n\r\nstruct\
    \ Info {\r\n    int mi[4];\r\n    int cnt[4];\r\n    Info(int x) {\r\n       \
    \ mi[0] = x;\r\n        mi[1] = inf + 1, mi[2] = inf + 2, mi[3] = inf + 3;\r\n\
    \        cnt[0] = 1;\r\n        cnt[1] = cnt[2] = cnt[3] = 0;\r\n    }\r\n\r\n\
    \    Info() : mi{inf, inf + 1, inf + 2, inf + 3}, cnt{0, 0, 0, 0} {}\r\n\r\n \
    \   void apply(const Tag &v) {\r\n        for (int i = 0; i < 4; i++) {\r\n  \
    \          mi[i] += v.x;\r\n        }\r\n    }\r\n\r\n    friend Info operator+(const\
    \ Info &a, const Info &b) {\r\n        int x = 0, y = 0;\r\n        Info res;\r\
    \n        for (int i = 0; i < 4; i++) {\r\n            // debug(x, y, a.mi[x],\
    \ b.mi[y]);\r\n            if (a.mi[x] < b.mi[y]) {\r\n                res.mi[i]\
    \ = a.mi[x];\r\n                res.cnt[i] = a.cnt[x];\r\n                x++;\r\
    \n            } else if (a.mi[x] > b.mi[y]) {\r\n                res.mi[i] = b.mi[y];\r\
    \n                res.cnt[i] = b.cnt[y];\r\n                y++;\r\n         \
    \   } else {\r\n                res.mi[i] = a.mi[x];\r\n                res.cnt[i]\
    \ = a.cnt[x] + b.cnt[y];\r\n                x++, y++;\r\n            }\r\n   \
    \     }\r\n        return res;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Lazy \u7EBF\
    \u6BB5\u6811\r\n@docs docs/lazy_segment_tree.md\r\n*/\r\n\r\n/*\r\nhttps://atcoder.jp/contests/abc256/tasks/abc256_h\r\
    \nhttps://atcoder.jp/contests/abc248/tasks/abc248_h\r\n*/\r\n#define lson l, m,\
    \ rt << 1\r\n#define rson m + 1, r, rt << 1 | 1\r\ntemplate <class Info, class\
    \ Tag, class Merge = std::plus<Info>>\r\nstruct LazySegmentTree {\r\n    LazySegmentTree(int\
    \ n) : n(n), merge(Merge()), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}\r\
    \n    LazySegmentTree(vector<Info> &init) : LazySegmentTree(init.size()) {\r\n\
    \        function<void(int, int, int)> build = [&](int l, int r, int rt) {\r\n\
    \            if (l == r) {\r\n                info[rt] = init[l];\r\n        \
    \        return;\r\n            }\r\n            int m = l + r >> 1;\r\n     \
    \       build(lson);\r\n            build(rson);\r\n            push_up(rt);\r\
    \n        };\r\n        build(0, n - 1, 1);\r\n    }\r\n\r\n    void update(int\
    \ L, const Info &v) {\r\n        update(L, v, 0, n - 1, 1);\r\n    }\r\n\r\n \
    \   void rangeUpdate(int L, int R, const Tag &v) {\r\n        return rangeUpdate(L,\
    \ R, v, 0, n - 1, 1);\r\n    }\r\n\r\n    Info rangeQuery(int L, int R) {\r\n\
    \        return rangeQuery(L, R, 0, n - 1, 1);\r\n    }\r\n\r\n    int find_first(int\
    \ ll, int rr, const function<bool(const Info &)> &f) {\r\n        return find_first(ll,\
    \ rr, f, 0, n - 1, 1);\r\n    }\r\n\r\n    int find_last(int ll, int rr, const\
    \ function<bool(const Info &)> &f) {\r\n        return find_last(ll, rr, f, 0,\
    \ n - 1, 1);\r\n    }\r\n\r\n   private:\r\n    const int n;\r\n    const Merge\
    \ merge;\r\n    vector<Info> info;\r\n    vector<Tag> tag;\r\n    void push_up(int\
    \ rt) {\r\n        info[rt] = merge(info[rt << 1], info[rt << 1 | 1]);\r\n   \
    \ }\r\n\r\n    void apply(int p, const Tag &v) {\r\n        info[p].apply(v);\r\
    \n        tag[p].apply(v);\r\n    }\r\n\r\n    void push_down(int rt) {\r\n  \
    \      apply(rt << 1, tag[rt]);\r\n        apply(rt << 1 | 1, tag[rt]);\r\n  \
    \      tag[rt] = Tag();\r\n    }\r\n\r\n    void update(int L, const Info &v,\
    \ int l, int r, int rt) {\r\n        if (l == r) {\r\n            info[rt] = v;\r\
    \n            return;\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(rt);\r\
    \n        if (L <= m) {\r\n            update(L, v, lson);\r\n        } else {\r\
    \n            update(L, v, rson);\r\n        }\r\n        push_up(rt);\r\n   \
    \ }\r\n\r\n    Info rangeQuery(int L, int R, int l, int r, int rt) {\r\n     \
    \   if (L <= l && r <= R) {\r\n            return info[rt];\r\n        }\r\n \
    \       int m = l + r >> 1;\r\n        push_down(rt);\r\n        if (L <= m &&\
    \ R > m) {\r\n            return merge(rangeQuery(L, R, lson), rangeQuery(L, R,\
    \ rson));\r\n        } else if (L <= m) {\r\n            return rangeQuery(L,\
    \ R, lson);\r\n        } else {\r\n            return rangeQuery(L, R, rson);\r\
    \n        }\r\n    }\r\n\r\n    void rangeUpdate(int L, int R, const Tag &v, int\
    \ l, int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n            apply(rt,\
    \ v);\r\n            return;\r\n        }\r\n        int m = l + r >> 1;\r\n \
    \       push_down(rt);\r\n        if (L <= m) {\r\n            rangeUpdate(L,\
    \ R, v, lson);\r\n        }\r\n        if (R > m) {\r\n            rangeUpdate(L,\
    \ R, v, rson);\r\n        }\r\n        push_up(rt);\r\n    }\r\n\r\n    int find_first_knowingly(const\
    \ function<bool(const Info &)> f, int l, int r, int rt) {\r\n        if (l ==\
    \ r) {\r\n            return l;\r\n        }\r\n        int m = l + r >> 1;\r\n\
    \        push_down(rt);\r\n        int res;\r\n        if (f(info[rt << 1])) {\r\
    \n            res = find_first_knowingly(f, lson);\r\n        } else {\r\n   \
    \         res = find_first_knowingly(f, rson);\r\n        }\r\n        push_up(rt);\r\
    \n        return res;\r\n    }\r\n\r\n    int find_first(int L, int R, const function<bool(const\
    \ Info &)> f, int l, int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n \
    \           if (!f(info[rt])) {\r\n                return -1;\r\n            }\r\
    \n            return find_first_knowingly(f, l, r, rt);\r\n        }\r\n     \
    \   int m = l + r >> 1;\r\n        push_down(rt);\r\n        int res = -1;\r\n\
    \        if (L <= m) {\r\n            res = find_first(L, R, f, lson);\r\n   \
    \     }\r\n        if (R > m && res == -1) {\r\n            res = find_first(L,\
    \ R, f, rson);\r\n        }\r\n        push_up(rt);\r\n        return res;\r\n\
    \    }\r\n\r\n    int find_last_knowingly(const function<bool(const Info &)> f,\
    \ int l, int r, int rt) {\r\n        if (l == r) {\r\n            return l;\r\n\
    \        }\r\n        int m = l + r >> 1;\r\n        push_down(rt);\r\n      \
    \  int res;\r\n        if (f(info[rt << 1 | 1])) {\r\n            res = find_last_knowingly(f,\
    \ rson);\r\n        } else {\r\n            res = find_last_knowingly(f, lson);\r\
    \n        }\r\n        push_up(rt);\r\n        return res;\r\n    }\r\n\r\n  \
    \  int find_last(int L, int R, const function<bool(const Info &)> f, int l, int\
    \ r, int rt) {\r\n        if (L <= l && r <= R) {\r\n            if (!f(info[rt]))\
    \ {\r\n                return -1;\r\n            }\r\n            return find_last_knowingly(f,\
    \ l, r, rt);\r\n        }\r\n        int m = l + r >> 1;\r\n        push_down(rt);\r\
    \n        int res = -1;\r\n        if (R > m) {\r\n            res = find_last(L,\
    \ R, f, rson);\r\n        }\r\n        if (L <= m && res == -1) {\r\n        \
    \    res = find_last(L, R, f, lson);\r\n        }\r\n        push_up(rt);\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\nconst int inf = 1e6;\r\nstruct Tag\
    \ {\r\n    int x;\r\n    Tag(int _x) : x(_x) {}\r\n    Tag() { x = 0; }\r\n  \
    \  void apply(const Tag &v) {\r\n        x += v.x;\r\n    }\r\n};\r\n\r\nstruct\
    \ Info {\r\n    int mi[4];\r\n    int cnt[4];\r\n    Info(int x) {\r\n       \
    \ mi[0] = x;\r\n        mi[1] = inf + 1, mi[2] = inf + 2, mi[3] = inf + 3;\r\n\
    \        cnt[0] = 1;\r\n        cnt[1] = cnt[2] = cnt[3] = 0;\r\n    }\r\n\r\n\
    \    Info() : mi{inf, inf + 1, inf + 2, inf + 3}, cnt{0, 0, 0, 0} {}\r\n\r\n \
    \   void apply(const Tag &v) {\r\n        for (int i = 0; i < 4; i++) {\r\n  \
    \          mi[i] += v.x;\r\n        }\r\n    }\r\n\r\n    friend Info operator+(const\
    \ Info &a, const Info &b) {\r\n        int x = 0, y = 0;\r\n        Info res;\r\
    \n        for (int i = 0; i < 4; i++) {\r\n            // debug(x, y, a.mi[x],\
    \ b.mi[y]);\r\n            if (a.mi[x] < b.mi[y]) {\r\n                res.mi[i]\
    \ = a.mi[x];\r\n                res.cnt[i] = a.cnt[x];\r\n                x++;\r\
    \n            } else if (a.mi[x] > b.mi[y]) {\r\n                res.mi[i] = b.mi[y];\r\
    \n                res.cnt[i] = b.cnt[y];\r\n                y++;\r\n         \
    \   } else {\r\n                res.mi[i] = a.mi[x];\r\n                res.cnt[i]\
    \ = a.cnt[x] + b.cnt[y];\r\n                x++, y++;\r\n            }\r\n   \
    \     }\r\n        return res;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/lazySegmentTree.hpp
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/lazySegmentTree.hpp
layout: document
redirect_from:
- /library/src/data_structure/lazySegmentTree.hpp
- /library/src/data_structure/lazySegmentTree.hpp.html
title: "Lazy \u7EBF\u6BB5\u6811"
---
