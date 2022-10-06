---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/bits.md
    document_title: "\u4F4D\u8FD0\u7B97"
    links:
    - https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875
    - https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications
  bundledCode: "#line 1 \"src/math/bits.h\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n/*\n@brief \u4F4D\u8FD0\u7B97\n@docs docs/bits.md\n*/\n/*\u4E00\u4E9B\u8BB0\
    \u4E0D\u4F4F\u7684\u77E5\u8BC6\u70B9*/\n/*\n    1. lowbit\n    lowbit(x): x \u7684\
    \u6700\u4F4E\u4F4D 1 lowbit(100100) = 100\n    lowbit(x) = x & (~x + 1)\n    ~x\
    \ \u6309\u4F4D\u53D6\u53CD ~0 = -1, ~1 = -2, ~2 = -3...\n    \u663E\u7136 ~x +\
    \ 1 = -x\n    \u6240\u4EE5 lowbit(x) = x & -x\n\n    2. __builtin_parity(x) x\
    \ \u6709\u5076\u6570\u4E2A 1 \u8FD4\u56DE 0\uFF0C\u5947\u6570\u4E2A 1 \u8FD4\u56DE\
    \ 1\n    3. __builtin_popcount(x) \u8FD4\u56DE x \u7684 1 \u7684\u4E2A\u6570\n\
    \    3. __builtin_ctz(x) \u6B64\u51FD\u6570\u7528\u4E8E\u8BA1\u7B97\u7ED9\u5B9A\
    \u6574\u6570\u7684\u5C3E\u968F\u96F6\n    4. __builtin_clz(x) \u6B64\u51FD\u6570\
    \u7528\u4E8E\u8BA1\u7B97\u6574\u6570\u7684\u524D\u5BFC\u96F6\u3002\u6CE8\u610F\
    \uFF1Aclz = \u8BA1\u7B97\u524D\u5BFC\u96F6\n*/\nstruct Subset {\n    /*\n    \u679A\
    \u4E3E status \u7684\u5168\u90E8\u5B50\u96C6\n    */\n    int status;\n    Subset(int\
    \ status) : status(status) {}\n    struct Iterator {\n        int i;\n       \
    \ int status;\n        bool ok;\n        Iterator(int _i, int _s, bool ok = true)\
    \ : i(_i), status(_s), ok(ok) {}\n        int operator*() const {\n          \
    \  return i;\n        }\n        bool operator!=(const Iterator& a) const {\n\
    \            return i != a.i && ok != a.ok;\n        }\n        Iterator& operator++()\
    \ {\n            i = (i - 1) & status;\n            ok = (i != status);\n    \
    \        return *this;\n        }\n    };\n    Iterator begin() const {\n    \
    \    return Iterator(status, status, true);\n    }\n    Iterator end() const {\n\
    \        // \u4F5C\u4E3A\u7ED3\u675F\u6761\u4EF6\uFF0C\u5904\u7406\u5B8C 0 \u4E4B\
    \u540E\uFF0C\u4F1A\u6709 -1 & status = status\n        return Iterator(status,\
    \ status, false);\n    }\n};\n\nstruct NonEmptySubset {\n    /*\n    \u679A\u4E3E\
    \ status \u7684\u5168\u90E8\u975E\u7A7A\u5B50\u96C6\n    */\n    int status;\n\
    \    NonEmptySubset(int status) : status(status) {}\n    struct Iterator {\n \
    \       int i;\n        int status;\n        Iterator(int _i, int _s) : i(_i),\
    \ status(_s) {}\n        int operator*() const {\n            return i;\n    \
    \    }\n        bool operator!=(const Iterator& a) const {\n            return\
    \ i != a.i;\n        }\n        Iterator& operator++() {\n            i = (i -\
    \ 1) & status;\n            return *this;\n        }\n    };\n    Iterator begin()\
    \ const {\n        return Iterator(status, status);\n    }\n    Iterator end()\
    \ const {\n        return Iterator(0, status);\n    }\n};\n\nstruct ProperSubset\
    \ {\n    /*\n    \u679A\u4E3E status \u7684\u5168\u90E8\u771F\u5B50\u96C6\n  \
    \  */\n    int status;\n    ProperSubset(int status) : status(status) {}\n   \
    \ struct Iterator {\n        int i;\n        int status;\n        Iterator(int\
    \ _i, int _s) : i(_i), status(_s) {}\n        int operator*() const {\n      \
    \      return i;\n        }\n        bool operator!=(const Iterator& a) const\
    \ {\n            return i != a.i;\n        }\n        Iterator& operator++() {\n\
    \            i = (i - 1) & status;\n            return *this;\n        }\n   \
    \ };\n    Iterator begin() const {\n        return Iterator(status - 1, status);\n\
    \    }\n    Iterator end() const {\n        return Iterator(status, status);\n\
    \    }\n};\n\nstruct NonEmptyProperSubset {\n    /*\n    \u679A\u4E3E status \u7684\
    \u5168\u90E8\u975E\u7A7A\u771F\u5B50\u96C6\n    */\n    int status;\n    NonEmptyProperSubset(int\
    \ status) : status(status) {}\n    struct Iterator {\n        int i;\n       \
    \ int status;\n        Iterator(int _i, int _s) : i(_i), status(_s) {}\n     \
    \   int operator*() const {\n            return i;\n        }\n        bool operator!=(const\
    \ Iterator& a) const {\n            return i != a.i;\n        }\n        Iterator&\
    \ operator++() {\n            i = (i - 1) & status;\n            return *this;\n\
    \        }\n    };\n    Iterator begin() const {\n        return Iterator(status\
    \ - 1, status);\n    }\n    Iterator end() const {\n        return Iterator(0,\
    \ status);\n    }\n};\n\nstruct MultiSubset {\n    // \u6C42\u591A\u4E2A\u96C6\
    \u5408\u7684\u6240\u6709\u975E\u7A7A\u5B50\u96C6\u7684\u96C6\u5408\n    vector<bool>\
    \ multi_subset(vector<int>& status) {\n        int mx = *max_element(status.begin(),\
    \ status.end());\n        vector<bool> have(mx + 1);\n        function<void(int)>\
    \ f = [&](int v) {\n            if (have[v]) return;\n            have[v] = true;\n\
    \            for (int w = v; w > 0; w &= w - 1) {\n                // w \u6BCF\
    \u6B21\u51CF\u53BB\u6700\u540E\u4E00\u4E2A 1\n                // v = 1001010 =>\
    \ w = 1001010, 1001000, 1000000\n                f(v ^ (w & -w));\n          \
    \  }\n        };\n        for (auto v : status) {\n            f(v);\n       \
    \ }\n        return have;\n    }\n};\n\nstruct Superset {\n    // \u679A\u4E3E\
    \ status \u7684\u5168\u90E8\u8D85\u96C6\n    int status;\n    int n;\n    Superset(int\
    \ status, int n) : status(status), n(n) {}\n    struct Iterator {\n        int\
    \ i;\n        int status;\n        int n;\n        Iterator(int _i, int _s, int\
    \ _n) : i(_i), status(_s), n(_n) {}\n        int operator*() const {\n       \
    \     return i;\n        }\n        bool operator!=(const Iterator& a) const {\n\
    \            return i != a.i;\n        }\n        Iterator& operator++() {\n \
    \           i = (i + 1) | status;\n            return *this;\n        }\n    };\n\
    \    Iterator begin() const {\n        return Iterator(status, status, n);\n \
    \   }\n    Iterator end() const {\n        return Iterator(1 << n, status, n);\n\
    \    }\n};\n\nstruct SubsetK {\n    // Gosper\u2019s Hack\uFF1A\u679A\u4E3E\u5927\
    \u5C0F\u4E3A n \u7684\u96C6\u5408\u7684\u5927\u5C0F\u4E3A k \u7684\u5B50\u96C6\
    \uFF08\u6309\u5B57\u5178\u5E8F\uFF09\n    // https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications\n\
    \    // \u53C2\u8003\u300A\u6311\u6218\u7A0B\u5E8F\u8BBE\u8BA1\u7ADE\u8D5B\u300B\
    p.156-158 \u7684\u5B9E\u73B0\n    // \u628A\u9664\u6CD5\u6539\u6210\u53F3\u79FB\
    \ bits.TrailingZeros \u53EF\u4EE5\u5FEB\u597D\u51E0\u500D\n    // \u6BD4\u5982\
    \u5728 n \u4E2A\u6570\u4E2D\u6C42\u6EE1\u8DB3\u67D0\u79CD\u6027\u8D28\u7684\u6700\
    \u5927\u5B50\u96C6\uFF0C\u5219\u53EF\u4EE5\u4ECE n \u5F00\u59CB\u5012\u7740\u679A\
    \u4E3E\u5B50\u96C6\u5927\u5C0F\uFF0C\u76F4\u5230\u627E\u5230\u4E00\u4E2A\u7B26\
    \u5408\u6027\u8D28\u7684\u5B50\u96C6\n    // \u4F8B\u9898\uFF08TS1\uFF09https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875\n\
    \    int n;\n    int k;\n    SubsetK(int n, int k) : n(n), k(k) {}\n    struct\
    \ Iterator {\n        int i;\n        int n;\n        int k;\n        Iterator(int\
    \ _i, int _n, int _k) : i(_i), n(_n), k(_k) {}\n        int operator*() const\
    \ {\n            return i;\n        }\n        bool operator!=(const Iterator&\
    \ a) const {\n            return i != a.i;\n        }\n        Iterator& operator++()\
    \ {\n            int lb = i & -i;\n            int x = i + lb;\n            i\
    \ = x + ((x ^ i) >> (__builtin_ctz(lb) + 2));\n        }\n    };\n    Iterator\
    \ begin() const {\n        return Iterator((1 << k) - 1, n, k);\n    }\n    Iterator\
    \ end() const {\n        return Iterator(1 << n, n, k);\n    }\n};\n\nstruct AllOne\
    \ {\n    // \u679A\u4E3E\u5404\u4E2A 1 \u4F4D\u7684\u4F4D\u7F6E\n    // \u6BCF\
    \u6B21\u7EDF\u8BA1\u5C3E 0 \u7684\u4E2A\u6570\uFF0C\u7136\u540E\u79FB\u9664\u6700\
    \u53F3\u4FA7\u7684 1\n    int status;\n    AllOne(int status) : status(status)\
    \ {}\n    struct Iterator {\n        int i;\n        int status;\n        Iterator(int\
    \ _i, int _s) : i(_i), status(_s) {}\n        int operator*() const {\n      \
    \      return i;\n        }\n        bool operator!=(const Iterator& a) const\
    \ {\n            return i != a.i;\n        }\n        Iterator& operator++() {\n\
    \            i &= (i - 1);\n            return *this;\n        }\n    };\n   \
    \ Iterator begin() const {\n        return Iterator(status, status);\n    }\n\
    \    Iterator end() const {\n        return Iterator(0, status);\n    }\n};\n"
  code: "\n\n#include <bits/stdc++.h>\nusing namespace std;\n/*\n@brief \u4F4D\u8FD0\
    \u7B97\n@docs docs/bits.md\n*/\n/*\u4E00\u4E9B\u8BB0\u4E0D\u4F4F\u7684\u77E5\u8BC6\
    \u70B9*/\n/*\n    1. lowbit\n    lowbit(x): x \u7684\u6700\u4F4E\u4F4D 1 lowbit(100100)\
    \ = 100\n    lowbit(x) = x & (~x + 1)\n    ~x \u6309\u4F4D\u53D6\u53CD ~0 = -1,\
    \ ~1 = -2, ~2 = -3...\n    \u663E\u7136 ~x + 1 = -x\n    \u6240\u4EE5 lowbit(x)\
    \ = x & -x\n\n    2. __builtin_parity(x) x \u6709\u5076\u6570\u4E2A 1 \u8FD4\u56DE\
    \ 0\uFF0C\u5947\u6570\u4E2A 1 \u8FD4\u56DE 1\n    3. __builtin_popcount(x) \u8FD4\
    \u56DE x \u7684 1 \u7684\u4E2A\u6570\n    3. __builtin_ctz(x) \u6B64\u51FD\u6570\
    \u7528\u4E8E\u8BA1\u7B97\u7ED9\u5B9A\u6574\u6570\u7684\u5C3E\u968F\u96F6\n   \
    \ 4. __builtin_clz(x) \u6B64\u51FD\u6570\u7528\u4E8E\u8BA1\u7B97\u6574\u6570\u7684\
    \u524D\u5BFC\u96F6\u3002\u6CE8\u610F\uFF1Aclz = \u8BA1\u7B97\u524D\u5BFC\u96F6\
    \n*/\nstruct Subset {\n    /*\n    \u679A\u4E3E status \u7684\u5168\u90E8\u5B50\
    \u96C6\n    */\n    int status;\n    Subset(int status) : status(status) {}\n\
    \    struct Iterator {\n        int i;\n        int status;\n        bool ok;\n\
    \        Iterator(int _i, int _s, bool ok = true) : i(_i), status(_s), ok(ok)\
    \ {}\n        int operator*() const {\n            return i;\n        }\n    \
    \    bool operator!=(const Iterator& a) const {\n            return i != a.i &&\
    \ ok != a.ok;\n        }\n        Iterator& operator++() {\n            i = (i\
    \ - 1) & status;\n            ok = (i != status);\n            return *this;\n\
    \        }\n    };\n    Iterator begin() const {\n        return Iterator(status,\
    \ status, true);\n    }\n    Iterator end() const {\n        // \u4F5C\u4E3A\u7ED3\
    \u675F\u6761\u4EF6\uFF0C\u5904\u7406\u5B8C 0 \u4E4B\u540E\uFF0C\u4F1A\u6709 -1\
    \ & status = status\n        return Iterator(status, status, false);\n    }\n\
    };\n\nstruct NonEmptySubset {\n    /*\n    \u679A\u4E3E status \u7684\u5168\u90E8\
    \u975E\u7A7A\u5B50\u96C6\n    */\n    int status;\n    NonEmptySubset(int status)\
    \ : status(status) {}\n    struct Iterator {\n        int i;\n        int status;\n\
    \        Iterator(int _i, int _s) : i(_i), status(_s) {}\n        int operator*()\
    \ const {\n            return i;\n        }\n        bool operator!=(const Iterator&\
    \ a) const {\n            return i != a.i;\n        }\n        Iterator& operator++()\
    \ {\n            i = (i - 1) & status;\n            return *this;\n        }\n\
    \    };\n    Iterator begin() const {\n        return Iterator(status, status);\n\
    \    }\n    Iterator end() const {\n        return Iterator(0, status);\n    }\n\
    };\n\nstruct ProperSubset {\n    /*\n    \u679A\u4E3E status \u7684\u5168\u90E8\
    \u771F\u5B50\u96C6\n    */\n    int status;\n    ProperSubset(int status) : status(status)\
    \ {}\n    struct Iterator {\n        int i;\n        int status;\n        Iterator(int\
    \ _i, int _s) : i(_i), status(_s) {}\n        int operator*() const {\n      \
    \      return i;\n        }\n        bool operator!=(const Iterator& a) const\
    \ {\n            return i != a.i;\n        }\n        Iterator& operator++() {\n\
    \            i = (i - 1) & status;\n            return *this;\n        }\n   \
    \ };\n    Iterator begin() const {\n        return Iterator(status - 1, status);\n\
    \    }\n    Iterator end() const {\n        return Iterator(status, status);\n\
    \    }\n};\n\nstruct NonEmptyProperSubset {\n    /*\n    \u679A\u4E3E status \u7684\
    \u5168\u90E8\u975E\u7A7A\u771F\u5B50\u96C6\n    */\n    int status;\n    NonEmptyProperSubset(int\
    \ status) : status(status) {}\n    struct Iterator {\n        int i;\n       \
    \ int status;\n        Iterator(int _i, int _s) : i(_i), status(_s) {}\n     \
    \   int operator*() const {\n            return i;\n        }\n        bool operator!=(const\
    \ Iterator& a) const {\n            return i != a.i;\n        }\n        Iterator&\
    \ operator++() {\n            i = (i - 1) & status;\n            return *this;\n\
    \        }\n    };\n    Iterator begin() const {\n        return Iterator(status\
    \ - 1, status);\n    }\n    Iterator end() const {\n        return Iterator(0,\
    \ status);\n    }\n};\n\nstruct MultiSubset {\n    // \u6C42\u591A\u4E2A\u96C6\
    \u5408\u7684\u6240\u6709\u975E\u7A7A\u5B50\u96C6\u7684\u96C6\u5408\n    vector<bool>\
    \ multi_subset(vector<int>& status) {\n        int mx = *max_element(status.begin(),\
    \ status.end());\n        vector<bool> have(mx + 1);\n        function<void(int)>\
    \ f = [&](int v) {\n            if (have[v]) return;\n            have[v] = true;\n\
    \            for (int w = v; w > 0; w &= w - 1) {\n                // w \u6BCF\
    \u6B21\u51CF\u53BB\u6700\u540E\u4E00\u4E2A 1\n                // v = 1001010 =>\
    \ w = 1001010, 1001000, 1000000\n                f(v ^ (w & -w));\n          \
    \  }\n        };\n        for (auto v : status) {\n            f(v);\n       \
    \ }\n        return have;\n    }\n};\n\nstruct Superset {\n    // \u679A\u4E3E\
    \ status \u7684\u5168\u90E8\u8D85\u96C6\n    int status;\n    int n;\n    Superset(int\
    \ status, int n) : status(status), n(n) {}\n    struct Iterator {\n        int\
    \ i;\n        int status;\n        int n;\n        Iterator(int _i, int _s, int\
    \ _n) : i(_i), status(_s), n(_n) {}\n        int operator*() const {\n       \
    \     return i;\n        }\n        bool operator!=(const Iterator& a) const {\n\
    \            return i != a.i;\n        }\n        Iterator& operator++() {\n \
    \           i = (i + 1) | status;\n            return *this;\n        }\n    };\n\
    \    Iterator begin() const {\n        return Iterator(status, status, n);\n \
    \   }\n    Iterator end() const {\n        return Iterator(1 << n, status, n);\n\
    \    }\n};\n\nstruct SubsetK {\n    // Gosper\u2019s Hack\uFF1A\u679A\u4E3E\u5927\
    \u5C0F\u4E3A n \u7684\u96C6\u5408\u7684\u5927\u5C0F\u4E3A k \u7684\u5B50\u96C6\
    \uFF08\u6309\u5B57\u5178\u5E8F\uFF09\n    // https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications\n\
    \    // \u53C2\u8003\u300A\u6311\u6218\u7A0B\u5E8F\u8BBE\u8BA1\u7ADE\u8D5B\u300B\
    p.156-158 \u7684\u5B9E\u73B0\n    // \u628A\u9664\u6CD5\u6539\u6210\u53F3\u79FB\
    \ bits.TrailingZeros \u53EF\u4EE5\u5FEB\u597D\u51E0\u500D\n    // \u6BD4\u5982\
    \u5728 n \u4E2A\u6570\u4E2D\u6C42\u6EE1\u8DB3\u67D0\u79CD\u6027\u8D28\u7684\u6700\
    \u5927\u5B50\u96C6\uFF0C\u5219\u53EF\u4EE5\u4ECE n \u5F00\u59CB\u5012\u7740\u679A\
    \u4E3E\u5B50\u96C6\u5927\u5C0F\uFF0C\u76F4\u5230\u627E\u5230\u4E00\u4E2A\u7B26\
    \u5408\u6027\u8D28\u7684\u5B50\u96C6\n    // \u4F8B\u9898\uFF08TS1\uFF09https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875\n\
    \    int n;\n    int k;\n    SubsetK(int n, int k) : n(n), k(k) {}\n    struct\
    \ Iterator {\n        int i;\n        int n;\n        int k;\n        Iterator(int\
    \ _i, int _n, int _k) : i(_i), n(_n), k(_k) {}\n        int operator*() const\
    \ {\n            return i;\n        }\n        bool operator!=(const Iterator&\
    \ a) const {\n            return i != a.i;\n        }\n        Iterator& operator++()\
    \ {\n            int lb = i & -i;\n            int x = i + lb;\n            i\
    \ = x + ((x ^ i) >> (__builtin_ctz(lb) + 2));\n        }\n    };\n    Iterator\
    \ begin() const {\n        return Iterator((1 << k) - 1, n, k);\n    }\n    Iterator\
    \ end() const {\n        return Iterator(1 << n, n, k);\n    }\n};\n\nstruct AllOne\
    \ {\n    // \u679A\u4E3E\u5404\u4E2A 1 \u4F4D\u7684\u4F4D\u7F6E\n    // \u6BCF\
    \u6B21\u7EDF\u8BA1\u5C3E 0 \u7684\u4E2A\u6570\uFF0C\u7136\u540E\u79FB\u9664\u6700\
    \u53F3\u4FA7\u7684 1\n    int status;\n    AllOne(int status) : status(status)\
    \ {}\n    struct Iterator {\n        int i;\n        int status;\n        Iterator(int\
    \ _i, int _s) : i(_i), status(_s) {}\n        int operator*() const {\n      \
    \      return i;\n        }\n        bool operator!=(const Iterator& a) const\
    \ {\n            return i != a.i;\n        }\n        Iterator& operator++() {\n\
    \            i &= (i - 1);\n            return *this;\n        }\n    };\n   \
    \ Iterator begin() const {\n        return Iterator(status, status);\n    }\n\
    \    Iterator end() const {\n        return Iterator(0, status);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/bits.h
  requiredBy: []
  timestamp: '2022-10-06 23:48:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/bits.h
layout: document
redirect_from:
- /library/src/math/bits.h
- /library/src/math/bits.h.html
title: "\u4F4D\u8FD0\u7B97"
---
#  位运算

## 概要
记录一些位运算的技巧
### `Subset`
`Subset` 类实现枚举 `status` 的全部子集，用法可参考下面代码:
```cpp
#include "src/math/bits.h"
int main() {
    Subset subset(10); // 1010
    for (auto it = subset.begin(); it != subset.end(); ++it) {
        cout << *it << endl;
    }
    // 输出: 10 8 2 0
}
```

### `NonEmptySubset`
`NonEmptySubset` 类实现枚举 `status` 的全部非空子集，用法与 `Subset` 类似。

### `ProperSubset`
`ProperSubset` 类实现枚举 `status` 的全部真子集，用法与 `Subset` 类似。

### `NonEmptyProperSubset`
`NonEmptyProperSubset` 类实现枚举 `status` 的全部非空真子集，用法与 `Subset` 类似。

### `MultiSubset`
`MultiSubset` 类实现求多个集合的所有非空子集的集合
- `vector<bool> multi_subset(vector<int>& status)`: 返回 `status` 的所有非空子集的集合

### `Superset`
`Superset` 类实现枚举 `status` 的全部超集，用法与 `Subset` 类似。

### `SubsetK`
`SubsetK` 类实现枚举 `status` 的全部大小为 `k` 的子集，用法与 `Subset` 类似。

### `AllOne`
`AllOne` 类实现枚举 `status` 的全部 `1` 的位置，用法与 `Subset` 类似。



## 常见问题

## 题集