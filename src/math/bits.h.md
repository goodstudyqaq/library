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
    - https://ac.nowcoder.com/acm/contest/7607/B
    - https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875
    - https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications
  bundledCode: "#line 1 \"src/math/bits.h\"\n/*\n@brief \u4F4D\u8FD0\u7B97\n@docs\
    \ docs/bits.md\n*/\n/*\n    \u6709\u5173\u4F4D\u8FD0\u7B97\u7684\u4E00\u4E9B copypaste\n\
    */\n#include <bits/stdc++.h>\nusing namespace std;\nnamespace LoopCollection {\n\
    /*\u4E00\u4E9B\u8BB0\u4E0D\u4F4F\u7684\u77E5\u8BC6\u70B9*/\n/*\n    1. lowbit\n\
    \    lowbit(x): x \u7684\u6700\u4F4E\u4F4D 1 lowbit(100100) = 100\n    lowbit(x)\
    \ = x & (~x + 1)\n    ~x \u6309\u4F4D\u53D6\u53CD ~0 = -1, ~1 = -2, ~2 = -3...\n\
    \    \u663E\u7136 ~x + 1 = -x\n    \u6240\u4EE5 lowbit(x) = x & -x\n\n    2. __builtin_parity(x)\
    \ x \u6709\u5076\u6570\u4E2A 1 \u8FD4\u56DE 0\uFF0C\u5947\u6570\u4E2A 1 \u8FD4\
    \u56DE 1\n    3. __builtin_popcount(x) \u8FD4\u56DE x \u7684 1 \u7684\u4E2A\u6570\
    \n    3. __builtin_ctz(x) \u6B64\u51FD\u6570\u7528\u4E8E\u8BA1\u7B97\u7ED9\u5B9A\
    \u6574\u6570\u7684\u5C3E\u968F\u96F6\n    4. __builtin_clz(x) \u6B64\u51FD\u6570\
    \u7528\u4E8E\u8BA1\u7B97\u6574\u6570\u7684\u524D\u5BFC\u96F6\u3002\u6CE8\u610F\
    \uFF1Aclz = \u8BA1\u7B97\u524D\u5BFC\u96F6\n*/\n\nvoid loopSet(vector<int> a)\
    \ {\n    // \u904D\u5386 {0, 1, ..., n - 1} \u7684\u6240\u6709\u5B50\u96C6\n \
    \   int n = a.size();\n    int limit = 1 << n;\n    auto f = [&](int sub) {\n\
    \        for (int i = 0; i < n; i++) {\n            if ((sub >> i) & 1) {\n  \
    \              // do(a[i])...\n            }\n        }\n    };\n    for (int\
    \ i = 0; i < limit; i++) {\n        f(i);\n    }\n}\nvoid loopSubset(int n, int\
    \ status) {\n    // \u679A\u4E3E status \u7684\u5168\u90E8\u5B50\u96C6\n    //\
    \ \u4F5C\u4E3A\u7ED3\u675F\u6761\u4EF6\uFF0C\u5904\u7406\u5B8C 0 \u4E4B\u540E\uFF0C\
    \u4F1A\u6709 -1&set == set\n    for (int sub = status, ok = true; ok; ok = (sub\
    \ != status)) {\n        // do(sub)\n        sub = (sub - 1) & status;\n    }\n\
    \n    // \u975E\u7A7A\u5B50\u96C6\n    for (int sub = status; sub; sub = (sub\
    \ - 1) & status) {\n        // do(sub)\n    }\n\n    // \u771F\u5B50\u96C6\n \
    \   for (int sub = (status - 1) & status; sub != status; sub = (sub - 1) & status)\
    \ {\n        // do(sub)\n    }\n\n    // \u975E\u7A7A\u771F\u5B50\u96C6\n    for\
    \ (int sub = (status - 1) & status; sub; sub = (sub - 1) & status) {\n       \
    \ // do(sub)\n    }\n}\nvoid loopMultiSubset(vector<int>& a) {\n    // \u6C42\u591A\
    \u4E2A\u96C6\u5408(\u72B6\u538B)\u7684\u6240\u6709\u975E\u7A7A\u5B50\u96C6\u7EC4\
    \u6210\u7684\u96C6\u5408\n    // https://ac.nowcoder.com/acm/contest/7607/B\n\
    \    vector<bool> have(1e6 + 1, 0);\n    function<void(int v)> f = [&](int v)\
    \ {\n        if (have[v]) return;\n        have[v] = true;\n        for (int w\
    \ = v; w > 0; w &= w - 1) {\n            // w \u6BCF\u6B21\u4F1A\u5E72\u6389 v\
    \ \u7684\u6700\u4F4E\u4F4D\u7684 1\n            // v = 1001010 => w = 1001010,\
    \ 1001000, 1000000\n            f(v ^ (w & -w));\n        }\n    };\n}\n\nvoid\
    \ loopSuperset(int n, int status) {\n    // \u679A\u4E3E status \u7684\u5168\u90E8\
    \u8D85\u96C6(\u7236\u96C6) ss\n    for (int ss = status; ss < (1 << n); ss = (ss\
    \ + 1) | status) {\n        // do(ss)...\n    }\n}\n\n// Gosper\u2019s Hack\uFF1A\
    \u679A\u4E3E\u5927\u5C0F\u4E3A n \u7684\u96C6\u5408\u7684\u5927\u5C0F\u4E3A k\
    \ \u7684\u5B50\u96C6\uFF08\u6309\u5B57\u5178\u5E8F\uFF09\n// https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications\n\
    // \u53C2\u8003\u300A\u6311\u6218\u7A0B\u5E8F\u8BBE\u8BA1\u7ADE\u8D5B\u300Bp.156-158\
    \ \u7684\u5B9E\u73B0\n// \u628A\u9664\u6CD5\u6539\u6210\u53F3\u79FB bits.TrailingZeros\
    \ \u53EF\u4EE5\u5FEB\u597D\u51E0\u500D\n// \u6BD4\u5982\u5728 n \u4E2A\u6570\u4E2D\
    \u6C42\u6EE1\u8DB3\u67D0\u79CD\u6027\u8D28\u7684\u6700\u5927\u5B50\u96C6\uFF0C\
    \u5219\u53EF\u4EE5\u4ECE n \u5F00\u59CB\u5012\u7740\u679A\u4E3E\u5B50\u96C6\u5927\
    \u5C0F\uFF0C\u76F4\u5230\u627E\u5230\u4E00\u4E2A\u7B26\u5408\u6027\u8D28\u7684\
    \u5B50\u96C6\n// \u4F8B\u9898\uFF08TS1\uFF09https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875\n\
    void loopSubsetK(vector<int>& a, int k) {\n    int n = a.size();\n    int limit\
    \ = 1 << n;\n    for (int sub = (1 << k) - 1; sub < limit;) {\n        // do(a,\
    \ sub)...\n        int lb = sub & -sub;\n        int x = sub + lb;\n        /*\n\
    \                x \u6709\u4E24\u79CD\u60C5\u51B5\n                1. \u6700\u4F4E\
    \u4F4D 1 \u524D\u9762\u6CA1\u6709 1\uFF0C\u90A3\u4E48 x \u5C31\u662F\u6211\u4EEC\
    \u60F3\u8981\u627E\u7684\u4E0B\u4E00\u4F4D\u6570 (x ^ sub) / lb = 11, 11 >> 2\
    \ = 0\n                2. \u6700\u4F4E\u4F4D 1 \u524D\u9762\u6709 1, \u6BD4\u5982\
    \ 100111000, x = 101000000 (x ^ sub) / lb = 1111 \u6BD4\u8FD8\u9700\u8981\u7684\
    \u591A 2 \u4E2A\uFF0C\u6240\u4EE5\u8FD8\u662F\u5DE6\u79FB 2\n                \u672C\
    \u8D28\u5C31\u662F\u628A\u4E2D\u95F4\u7684 1 \u8865\u4E0A\u53BB\uFF0C\u5176\u5B9E\
    \u53EF\u4EE5\u5F52\u6210\u4E00\u7C7B\n            */\n        sub = x + ((x ^\
    \ sub) >> (__builtin_ctz(lb) + 2));\n    }\n}\n\nvoid loopAllOne(int status) {\n\
    \    // \u679A\u4E3E\u5404\u4E2A 1 \u4F4D\u7684\u4F4D\u7F6E\n    // \u6BCF\u6B21\
    \u7EDF\u8BA1\u5C3E 0 \u7684\u4E2A\u6570\uFF0C\u7136\u540E\u79FB\u9664\u6700\u53F3\
    \u4FA7\u7684 1\n    for (int i = status; i > 0; i &= (i - 1)) {\n        int p\
    \ = __builtin_ctz(i);\n        // do(p)...\n    }\n}\n}  // namespace LoopCollection\n\
    \n// step matrix: \u5BF9\u4E8E\u6BCF\u4E00\u884C\u6765\u8BF4\uFF0C\u7B2C\u4E00\
    \u4E2A\u975E 0 \u5217\u7684\u4E0B\u6807\u662F\u4E25\u683C\u9012\u589E\u7684\u3002\
    \ntemplate <class T, int W>\nint stepMatrix(vector<T>& c) {\n    int n = (int)c.size(),\
    \ rank = 0;\n    for (int d = W - 1; d >= 0; --d) {\n        int k = rank;\n \
    \       while (k < n and !(c[k] >> d & 1)) {\n            k += 1;\n        }\n\
    \        if (k < n) {\n            swap(c[k], c[rank]);\n            for (int\
    \ i = rank + 1; i < n; ++i) {\n                if (c[i] >> d & 1) {\n        \
    \            c[i] ^= c[rank];\n                }\n            }\n            rank\
    \ += 1;\n        }\n    }\n    return rank;\n}\n"
  code: "/*\n@brief \u4F4D\u8FD0\u7B97\n@docs docs/bits.md\n*/\n/*\n    \u6709\u5173\
    \u4F4D\u8FD0\u7B97\u7684\u4E00\u4E9B copypaste\n*/\n#include <bits/stdc++.h>\n\
    using namespace std;\nnamespace LoopCollection {\n/*\u4E00\u4E9B\u8BB0\u4E0D\u4F4F\
    \u7684\u77E5\u8BC6\u70B9*/\n/*\n    1. lowbit\n    lowbit(x): x \u7684\u6700\u4F4E\
    \u4F4D 1 lowbit(100100) = 100\n    lowbit(x) = x & (~x + 1)\n    ~x \u6309\u4F4D\
    \u53D6\u53CD ~0 = -1, ~1 = -2, ~2 = -3...\n    \u663E\u7136 ~x + 1 = -x\n    \u6240\
    \u4EE5 lowbit(x) = x & -x\n\n    2. __builtin_parity(x) x \u6709\u5076\u6570\u4E2A\
    \ 1 \u8FD4\u56DE 0\uFF0C\u5947\u6570\u4E2A 1 \u8FD4\u56DE 1\n    3. __builtin_popcount(x)\
    \ \u8FD4\u56DE x \u7684 1 \u7684\u4E2A\u6570\n    3. __builtin_ctz(x) \u6B64\u51FD\
    \u6570\u7528\u4E8E\u8BA1\u7B97\u7ED9\u5B9A\u6574\u6570\u7684\u5C3E\u968F\u96F6\
    \n    4. __builtin_clz(x) \u6B64\u51FD\u6570\u7528\u4E8E\u8BA1\u7B97\u6574\u6570\
    \u7684\u524D\u5BFC\u96F6\u3002\u6CE8\u610F\uFF1Aclz = \u8BA1\u7B97\u524D\u5BFC\
    \u96F6\n*/\n\nvoid loopSet(vector<int> a) {\n    // \u904D\u5386 {0, 1, ..., n\
    \ - 1} \u7684\u6240\u6709\u5B50\u96C6\n    int n = a.size();\n    int limit =\
    \ 1 << n;\n    auto f = [&](int sub) {\n        for (int i = 0; i < n; i++) {\n\
    \            if ((sub >> i) & 1) {\n                // do(a[i])...\n         \
    \   }\n        }\n    };\n    for (int i = 0; i < limit; i++) {\n        f(i);\n\
    \    }\n}\nvoid loopSubset(int n, int status) {\n    // \u679A\u4E3E status \u7684\
    \u5168\u90E8\u5B50\u96C6\n    // \u4F5C\u4E3A\u7ED3\u675F\u6761\u4EF6\uFF0C\u5904\
    \u7406\u5B8C 0 \u4E4B\u540E\uFF0C\u4F1A\u6709 -1&set == set\n    for (int sub\
    \ = status, ok = true; ok; ok = (sub != status)) {\n        // do(sub)\n     \
    \   sub = (sub - 1) & status;\n    }\n\n    // \u975E\u7A7A\u5B50\u96C6\n    for\
    \ (int sub = status; sub; sub = (sub - 1) & status) {\n        // do(sub)\n  \
    \  }\n\n    // \u771F\u5B50\u96C6\n    for (int sub = (status - 1) & status; sub\
    \ != status; sub = (sub - 1) & status) {\n        // do(sub)\n    }\n\n    //\
    \ \u975E\u7A7A\u771F\u5B50\u96C6\n    for (int sub = (status - 1) & status; sub;\
    \ sub = (sub - 1) & status) {\n        // do(sub)\n    }\n}\nvoid loopMultiSubset(vector<int>&\
    \ a) {\n    // \u6C42\u591A\u4E2A\u96C6\u5408(\u72B6\u538B)\u7684\u6240\u6709\u975E\
    \u7A7A\u5B50\u96C6\u7EC4\u6210\u7684\u96C6\u5408\n    // https://ac.nowcoder.com/acm/contest/7607/B\n\
    \    vector<bool> have(1e6 + 1, 0);\n    function<void(int v)> f = [&](int v)\
    \ {\n        if (have[v]) return;\n        have[v] = true;\n        for (int w\
    \ = v; w > 0; w &= w - 1) {\n            // w \u6BCF\u6B21\u4F1A\u5E72\u6389 v\
    \ \u7684\u6700\u4F4E\u4F4D\u7684 1\n            // v = 1001010 => w = 1001010,\
    \ 1001000, 1000000\n            f(v ^ (w & -w));\n        }\n    };\n}\n\nvoid\
    \ loopSuperset(int n, int status) {\n    // \u679A\u4E3E status \u7684\u5168\u90E8\
    \u8D85\u96C6(\u7236\u96C6) ss\n    for (int ss = status; ss < (1 << n); ss = (ss\
    \ + 1) | status) {\n        // do(ss)...\n    }\n}\n\n// Gosper\u2019s Hack\uFF1A\
    \u679A\u4E3E\u5927\u5C0F\u4E3A n \u7684\u96C6\u5408\u7684\u5927\u5C0F\u4E3A k\
    \ \u7684\u5B50\u96C6\uFF08\u6309\u5B57\u5178\u5E8F\uFF09\n// https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications\n\
    // \u53C2\u8003\u300A\u6311\u6218\u7A0B\u5E8F\u8BBE\u8BA1\u7ADE\u8D5B\u300Bp.156-158\
    \ \u7684\u5B9E\u73B0\n// \u628A\u9664\u6CD5\u6539\u6210\u53F3\u79FB bits.TrailingZeros\
    \ \u53EF\u4EE5\u5FEB\u597D\u51E0\u500D\n// \u6BD4\u5982\u5728 n \u4E2A\u6570\u4E2D\
    \u6C42\u6EE1\u8DB3\u67D0\u79CD\u6027\u8D28\u7684\u6700\u5927\u5B50\u96C6\uFF0C\
    \u5219\u53EF\u4EE5\u4ECE n \u5F00\u59CB\u5012\u7740\u679A\u4E3E\u5B50\u96C6\u5927\
    \u5C0F\uFF0C\u76F4\u5230\u627E\u5230\u4E00\u4E2A\u7B26\u5408\u6027\u8D28\u7684\
    \u5B50\u96C6\n// \u4F8B\u9898\uFF08TS1\uFF09https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875\n\
    void loopSubsetK(vector<int>& a, int k) {\n    int n = a.size();\n    int limit\
    \ = 1 << n;\n    for (int sub = (1 << k) - 1; sub < limit;) {\n        // do(a,\
    \ sub)...\n        int lb = sub & -sub;\n        int x = sub + lb;\n        /*\n\
    \                x \u6709\u4E24\u79CD\u60C5\u51B5\n                1. \u6700\u4F4E\
    \u4F4D 1 \u524D\u9762\u6CA1\u6709 1\uFF0C\u90A3\u4E48 x \u5C31\u662F\u6211\u4EEC\
    \u60F3\u8981\u627E\u7684\u4E0B\u4E00\u4F4D\u6570 (x ^ sub) / lb = 11, 11 >> 2\
    \ = 0\n                2. \u6700\u4F4E\u4F4D 1 \u524D\u9762\u6709 1, \u6BD4\u5982\
    \ 100111000, x = 101000000 (x ^ sub) / lb = 1111 \u6BD4\u8FD8\u9700\u8981\u7684\
    \u591A 2 \u4E2A\uFF0C\u6240\u4EE5\u8FD8\u662F\u5DE6\u79FB 2\n                \u672C\
    \u8D28\u5C31\u662F\u628A\u4E2D\u95F4\u7684 1 \u8865\u4E0A\u53BB\uFF0C\u5176\u5B9E\
    \u53EF\u4EE5\u5F52\u6210\u4E00\u7C7B\n            */\n        sub = x + ((x ^\
    \ sub) >> (__builtin_ctz(lb) + 2));\n    }\n}\n\nvoid loopAllOne(int status) {\n\
    \    // \u679A\u4E3E\u5404\u4E2A 1 \u4F4D\u7684\u4F4D\u7F6E\n    // \u6BCF\u6B21\
    \u7EDF\u8BA1\u5C3E 0 \u7684\u4E2A\u6570\uFF0C\u7136\u540E\u79FB\u9664\u6700\u53F3\
    \u4FA7\u7684 1\n    for (int i = status; i > 0; i &= (i - 1)) {\n        int p\
    \ = __builtin_ctz(i);\n        // do(p)...\n    }\n}\n}  // namespace LoopCollection\n\
    \n// step matrix: \u5BF9\u4E8E\u6BCF\u4E00\u884C\u6765\u8BF4\uFF0C\u7B2C\u4E00\
    \u4E2A\u975E 0 \u5217\u7684\u4E0B\u6807\u662F\u4E25\u683C\u9012\u589E\u7684\u3002\
    \ntemplate <class T, int W>\nint stepMatrix(vector<T>& c) {\n    int n = (int)c.size(),\
    \ rank = 0;\n    for (int d = W - 1; d >= 0; --d) {\n        int k = rank;\n \
    \       while (k < n and !(c[k] >> d & 1)) {\n            k += 1;\n        }\n\
    \        if (k < n) {\n            swap(c[k], c[rank]);\n            for (int\
    \ i = rank + 1; i < n; ++i) {\n                if (c[i] >> d & 1) {\n        \
    \            c[i] ^= c[rank];\n                }\n            }\n            rank\
    \ += 1;\n        }\n    }\n    return rank;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/bits.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/bits.h
layout: document
redirect_from:
- /library/src/math/bits.h
- /library/src/math/bits.h.html
title: "\u4F4D\u8FD0\u7B97"
---
