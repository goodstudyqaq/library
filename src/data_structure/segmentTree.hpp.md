---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/segment_tree.md
    document_title: "\u7EBF\u6BB5\u6811"
    links: []
  bundledCode: "#line 1 \"src/data_structure/segmentTree.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief \u7EBF\u6BB5\u6811\r\n@docs docs/segment_tree.md\r\
    \n*/\r\n\r\n#define lson l, m, rt << 1\r\n#define rson m + 1, r, rt << 1 | 1\r\
    \ntemplate <class Info, class Merge = std::plus<Info>>\r\nstruct SegmentTree {\r\
    \n    SegmentTree(int n) : n(n), merge(Merge()), info(4 << __lg(n)) {}\r\n   \
    \ SegmentTree(vector<Info> init) : SegmentTree(init.size()) {\r\n        function<void(int,\
    \ int, int)> build = [&](int l, int r, int rt) {\r\n            if (l == r) {\r\
    \n                info[rt] = init[l];\r\n                return;\r\n         \
    \   }\r\n            int m = l + r >> 1;\r\n            build(lson);\r\n     \
    \       build(rson);\r\n            push_up(rt);\r\n        };\r\n        build(0,\
    \ n - 1, 1);\r\n    }\r\n\r\n    Info rangeQuery(int l, int r) {\r\n        return\
    \ rangeQuery(l, r, 0, n - 1, 1);\r\n    }\r\n\r\n    void update(int L, Info v)\
    \ {\r\n        return update(L, v, 0, n - 1, 1);\r\n    }\r\n\r\n   private:\r\
    \n    const int n;\r\n    const Merge merge;\r\n    vector<Info> info;\r\n   \
    \ void push_up(int rt) {\r\n        info[rt] = merge(info[rt << 1], info[rt <<\
    \ 1 | 1]);\r\n    }\r\n\r\n    Info rangeQuery(int L, int R, int l, int r, int\
    \ rt) {\r\n        if (L <= l && r <= R) {\r\n            return info[rt];\r\n\
    \        }\r\n        int m = l + r >> 1;\r\n        if (L <= m && R > m) {\r\n\
    \            return merge(rangeQuery(L, R, lson), rangeQuery(L, R, rson));\r\n\
    \        } else if (L <= m) {\r\n            return rangeQuery(L, R, lson);\r\n\
    \        } else {\r\n            return rangeQuery(L, R, rson);\r\n        }\r\
    \n    }\r\n\r\n    void update(int L, Info& v, int l, int r, int rt) {\r\n   \
    \     if (l == r) {\r\n            info[rt] = merge(info[rt], v);\r\n        \
    \    return;\r\n        }\r\n        int m = l + r >> 1;\r\n        if (L <= m)\
    \ {\r\n            update(L, v, lson);\r\n        } else {\r\n            update(L,\
    \ v, rson);\r\n        }\r\n        push_up(rt);\r\n    }\r\n};\r\n\r\nconst int\
    \ inf = (1 << 30) - 1;\r\nstruct Info {\r\n    int v[31];\r\n    Info(int x =\
    \ inf) {\r\n        v[0] = x;\r\n        for (int i = 1; i < 31; i++) {\r\n  \
    \          v[i] = inf;\r\n        }\r\n    }\r\n};\r\n\r\nInfo operator+(const\
    \ Info& a, const Info& b) {\r\n    Info c;\r\n    int i = 0, j = 0;\r\n    while\
    \ (i + j < 31) {\r\n        if (a.v[i] < b.v[j]) {\r\n            c.v[i + j] =\
    \ a.v[i];\r\n            i++;\r\n        } else {\r\n            c.v[i + j] =\
    \ b.v[j];\r\n            j++;\r\n        }\r\n    }\r\n    return c;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u7EBF\u6BB5\
    \u6811\r\n@docs docs/segment_tree.md\r\n*/\r\n\r\n#define lson l, m, rt << 1\r\
    \n#define rson m + 1, r, rt << 1 | 1\r\ntemplate <class Info, class Merge = std::plus<Info>>\r\
    \nstruct SegmentTree {\r\n    SegmentTree(int n) : n(n), merge(Merge()), info(4\
    \ << __lg(n)) {}\r\n    SegmentTree(vector<Info> init) : SegmentTree(init.size())\
    \ {\r\n        function<void(int, int, int)> build = [&](int l, int r, int rt)\
    \ {\r\n            if (l == r) {\r\n                info[rt] = init[l];\r\n  \
    \              return;\r\n            }\r\n            int m = l + r >> 1;\r\n\
    \            build(lson);\r\n            build(rson);\r\n            push_up(rt);\r\
    \n        };\r\n        build(0, n - 1, 1);\r\n    }\r\n\r\n    Info rangeQuery(int\
    \ l, int r) {\r\n        return rangeQuery(l, r, 0, n - 1, 1);\r\n    }\r\n\r\n\
    \    void update(int L, Info v) {\r\n        return update(L, v, 0, n - 1, 1);\r\
    \n    }\r\n\r\n   private:\r\n    const int n;\r\n    const Merge merge;\r\n \
    \   vector<Info> info;\r\n    void push_up(int rt) {\r\n        info[rt] = merge(info[rt\
    \ << 1], info[rt << 1 | 1]);\r\n    }\r\n\r\n    Info rangeQuery(int L, int R,\
    \ int l, int r, int rt) {\r\n        if (L <= l && r <= R) {\r\n            return\
    \ info[rt];\r\n        }\r\n        int m = l + r >> 1;\r\n        if (L <= m\
    \ && R > m) {\r\n            return merge(rangeQuery(L, R, lson), rangeQuery(L,\
    \ R, rson));\r\n        } else if (L <= m) {\r\n            return rangeQuery(L,\
    \ R, lson);\r\n        } else {\r\n            return rangeQuery(L, R, rson);\r\
    \n        }\r\n    }\r\n\r\n    void update(int L, Info& v, int l, int r, int\
    \ rt) {\r\n        if (l == r) {\r\n            info[rt] = merge(info[rt], v);\r\
    \n            return;\r\n        }\r\n        int m = l + r >> 1;\r\n        if\
    \ (L <= m) {\r\n            update(L, v, lson);\r\n        } else {\r\n      \
    \      update(L, v, rson);\r\n        }\r\n        push_up(rt);\r\n    }\r\n};\r\
    \n\r\nconst int inf = (1 << 30) - 1;\r\nstruct Info {\r\n    int v[31];\r\n  \
    \  Info(int x = inf) {\r\n        v[0] = x;\r\n        for (int i = 1; i < 31;\
    \ i++) {\r\n            v[i] = inf;\r\n        }\r\n    }\r\n};\r\n\r\nInfo operator+(const\
    \ Info& a, const Info& b) {\r\n    Info c;\r\n    int i = 0, j = 0;\r\n    while\
    \ (i + j < 31) {\r\n        if (a.v[i] < b.v[j]) {\r\n            c.v[i + j] =\
    \ a.v[i];\r\n            i++;\r\n        } else {\r\n            c.v[i + j] =\
    \ b.v[j];\r\n            j++;\r\n        }\r\n    }\r\n    return c;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segmentTree.hpp
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segmentTree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segmentTree.hpp
- /library/src/data_structure/segmentTree.hpp.html
title: "\u7EBF\u6BB5\u6811"
---
