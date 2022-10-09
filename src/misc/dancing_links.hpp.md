---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/dancing_links.md
    document_title: Dancing Links
    links: []
  bundledCode: "#line 1 \"src/misc/dancing_links.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n/*\r\n@brief Dancing Links\r\n@docs docs/dancing_links.md\r\
    \n*/\r\nstruct DLX {\r\n   private:\r\n    int n, m, size;\r\n    vector<int>\
    \ U, D, R, L, Row, Col;\r\n    vector<int> H;  //\u884C\u5934\u7ED3\u70B9\r\n\
    \    vector<int> S;  //\u6BCF\u4E00\u5217\u6709\u591A\u5C11\u7ED3\u70B9\r\n  \
    \  void init(int _n, int _m) {\r\n        n = _n, m = _m;\r\n        ansd = inf;\r\
    \n        for (int i = 0; i <= m; i++) {\r\n            S[i] = 0;\r\n        \
    \    U[i] = D[i] = i;  //\u521D\u59CB\u72B6\u6001\u4E0B,\u4E0A\u4E0B\u81EA\u5DF1\
    \u6307\u5411\u81EA\u5DF1(\u4E5F\u5C31\u77E5\u9053\u4E86\u5934\u7ED3\u70B9\u7684\
    \u503C\u4E3Ai)\r\n            L[i] = i - 1;\r\n            R[i] = i + 1;\r\n \
    \       }\r\n        R[m] = 0, L[0] = m;  //\u73AF\u72B6,\u4E0B\u9762\u7684Link\u4E00\
    \u6837\u4E5F\u662F\u73AF,\u8FD9\u6837\uFF0C\u4E0D\u7BA1\u4ECE\u4E00\u884C\u4E2D\
    \u7684\u4EFB\u610F\u4E00\u4E2A\u7ED3\u70B9\u90FD\u53EF\u4EE5\u904D\u5386\u5B8C\
    \u8FD9\u4E00\u884C.\r\n        size = m;            //\u7F16\u53F7,\u6BCF\u5217\
    \u7684\u5934\u7ED3\u70B9\u7F16\u53F71-m\uFF0C\u6240\u4EE5size\u4ECEm+1\u5F00\u59CB\
    \r\n        for (int i = 1; i <= n; i++)\r\n            H[i] = -1;\r\n    }\r\n\
    \r\n    void exact_remove(int c)  //\u5220\u9664\u8282\u70B9c(\u5217c),\u5E76\u4E14\
    \u5220\u9664\u6240\u6709\u5728\u8FD9\u4E00\u5217\u7684\u8282\u70B9\u6240\u5728\
    \u7684\u884C\u4E2D\u7684\u6240\u6709\u7684\u8282\u70B9\u3002\u3002\r\n    {\r\n\
    \        L[R[c]] = L[c];\r\n        R[L[c]] = R[c];\r\n        for (int i = D[c];\
    \ i != c; i = D[i])\r\n            for (int j = R[i]; j != i; j = R[j]) {\r\n\
    \                U[D[j]] = U[j];\r\n                D[U[j]] = D[j];\r\n      \
    \          --S[Col[j]];\r\n            }\r\n    }\r\n\r\n    void repeat_remove(int\
    \ c)  //\u53EA\u5220\u9664\u5217\r\n    {\r\n        for (int i = D[c]; i != c;\
    \ i = D[i])\r\n            L[R[i]] = L[i], R[L[i]] = R[i];\r\n    }\r\n\r\n  \
    \  void exact_resume(int c)  //\u6062\u590D\u8282\u70B9c(\u5217c),\u4EE5\u53CA\
    \u6062\u590D\u6240\u6709\u5728\u8FD9\u4E00\u5217\u7684\u8282\u70B9\u6240\u5728\
    \u7684\u884C\u4E2D\u7684\u6240\u6709\u7684\u8282\u70B9\u3002\r\n    {\r\n    \
    \    for (int i = U[c]; i != c; i = U[i])\r\n            for (int j = L[i]; j\
    \ != i; j = L[j])\r\n                ++S[Col[U[D[j]] = D[U[j]] = j]];\r\n    \
    \    L[R[c]] = R[L[c]] = c;\r\n    }\r\n\r\n    void repeat_resume(int c) {\r\n\
    \        for (int i = U[c]; i != c; i = U[i])\r\n            L[R[i]] = R[L[i]]\
    \ = i;\r\n    }\r\n\r\n    int f()  //\u4F30\u4EF7\u51FD\u6570\r\n    {\r\n  \
    \      vector<bool> vv(m + 1);\r\n        int ret = 0, c, i, j;\r\n        for\
    \ (c = R[0]; c != 0; c = R[c]) vv[c] = 1;\r\n        for (c = R[0]; c != 0; c\
    \ = R[c])\r\n            if (vv[c]) {\r\n                ret++, vv[c] = 0;\r\n\
    \                for (i = D[c]; i != c; i = D[i])\r\n                    for (j\
    \ = R[i]; j != i; j = R[j])\r\n                        vv[Col[j]] = 0;\r\n   \
    \         }\r\n        return ret;\r\n    }\r\n\r\n   public:\r\n    const int\
    \ inf = numeric_limits<int>::max() / 2;\r\n    vector<int> ans;\r\n    int ansd;\r\
    \n    DLX(int _n, int _m) {\r\n        n = _n;\r\n        m = _m;\r\n        int\
    \ maxnnode = n * m + 1;\r\n        U.resize(maxnnode);\r\n        D.resize(maxnnode);\r\
    \n        L.resize(maxnnode);\r\n        R.resize(maxnnode);\r\n        Row.resize(maxnnode);\r\
    \n        Col.resize(maxnnode);\r\n        H.resize(n + 1);\r\n        S.resize(m\
    \ + 1);\r\n        ans.resize(n + 1);\r\n        init(n, m);\r\n    }\r\n    DLX()\
    \ {}\r\n\r\n    void link(int r, int c)  //\u7B2Cr\u884C,\u7B2Cc\u5217\r\n   \
    \ {\r\n        ++S[Col[++size] = c];  //\u7B2Csize\u4E2A\u7ED3\u70B9\u7684\u5217\
    \u4E3Ac,\u5F53\u524D\u5217\u7684\u8282\u70B9\u6570++\r\n        Row[size] = r;\
    \         //\u7B2Csize\u4E2A\u8282\u70B9\u884C\u4F4D\u7F6E\u4E3Ar\r\n        D[size]\
    \ = D[c];\r\n        U[D[c]] = size;\r\n        U[size] = c;\r\n        D[c] =\
    \ size;\r\n        if (H[r] < 0)\r\n            H[r] = L[size] = R[size] = size;\r\
    \n        else {\r\n            R[size] = R[H[r]];\r\n            L[R[H[r]]] =\
    \ size;\r\n            L[size] = H[r];\r\n            R[H[r]] = size;\r\n    \
    \    }\r\n    }\r\n\r\n    // \u548C\u666E\u901A\u641C\u7D22\u4E00\u6837\uFF0C\
    \u8FD9\u91CC\u8868\u793A\u641C\u7D22\u6210\u529F\uFF0C\u53EF\u4EE5\u5F97\u5230\
    \u65B9\u6848\uFF0C\u4E5F\u53EF\u4EE5\u5F97\u5230\u6240\u6709\u65B9\u6848\u7684\
    \u4E2A\u6570\u3002\r\n    // \u770B\u9898\u76EE\u8981\u6C42, \u8FD9\u91CC\u662F\
    \u53EA\u5F97\u5230 1 \u4E2A\u65B9\u6848\r\n    // \u7CBE\u786E\u8986\u76D6\uFF0C\
    \u6BCF\u4E00\u5217\u6709\u4E14\u4EC5\u6709 1 \u4E2A 1\r\n    bool exact_dance(int\
    \ d)  //\u6DF1\u5EA6\r\n    {\r\n        if (R[0] == 0) {\r\n            ansd\
    \ = d;\r\n            return true;\r\n        }\r\n        int c = R[0];\r\n \
    \       for (int i = R[0]; i != 0; i = R[i])\r\n            if (S[i] < S[c])\r\
    \n                c = i;\r\n        exact_remove(c);  //\u627E\u5230\u8282\u70B9\
    \u6570\u6700\u5C11\u7684\u5217\uFF0C\u5F53\u524D\u5143\u7D20\u4E0D\u662F\u539F\
    \u56FE\u4E0A0,1\u7684\u8282\u70B9,\u800C\u662F\u5217\u5934\u7ED3\u70B9\r\n   \
    \     for (int i = D[c]; i != c; i = D[i]) {\r\n            ans[d] = Row[i]; \
    \ //\u5217\u5934\u7ED3\u70B9\u4E0B\u9762\u7684\u4E00\u4E2A\u8282\u70B9\r\n   \
    \         for (int j = R[i]; j != i; j = R[j])\r\n                exact_remove(Col[j]);\r\
    \n            if (exact_dance(d + 1)) return true;\r\n\r\n            for (int\
    \ j = L[i]; j != i; j = L[j])\r\n                exact_resume(Col[j]);\r\n   \
    \     }\r\n        exact_resume(c);\r\n        return false;\r\n    }\r\n    //\
    \ \u91CD\u590D\u8986\u76D6\uFF0C\u9009\u6700\u5C11\u7684\u884C\uFF0C\u4F7F\u5F97\
    \u6BCF\u4E00\u5217\u81F3\u5C11\u6709 1 \u4E2A 1\r\n    void repeat_dance(int d)\
    \ {\r\n        if (d + f() >= ansd) return;\r\n        if (R[0] == 0) {\r\n  \
    \          if (d < ansd) ansd = d;\r\n            // real_ans = ans; // \u5B58\
    \u65B9\u6848\r\n            return;\r\n        }\r\n        int c = R[0], i, j;\r\
    \n        for (i = R[0]; i; i = R[i])\r\n            if (S[i] < S[c]) c = i;\r\
    \n        for (i = D[c]; i != c; i = D[i]) {\r\n            ans[d] = Row[i];\r\
    \n            repeat_remove(i);\r\n            for (j = R[i]; j != i; j = R[j])\
    \ repeat_remove(j);\r\n            repeat_dance(d + 1);\r\n            for (j\
    \ = L[i]; j != i; j = L[j]) repeat_resume(j);\r\n            repeat_resume(i);\r\
    \n        }\r\n    }\r\n};\r\n// \u4E0B\u6807\u4ECE 1 \u5F00\u59CB\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Dancing\
    \ Links\r\n@docs docs/dancing_links.md\r\n*/\r\nstruct DLX {\r\n   private:\r\n\
    \    int n, m, size;\r\n    vector<int> U, D, R, L, Row, Col;\r\n    vector<int>\
    \ H;  //\u884C\u5934\u7ED3\u70B9\r\n    vector<int> S;  //\u6BCF\u4E00\u5217\u6709\
    \u591A\u5C11\u7ED3\u70B9\r\n    void init(int _n, int _m) {\r\n        n = _n,\
    \ m = _m;\r\n        ansd = inf;\r\n        for (int i = 0; i <= m; i++) {\r\n\
    \            S[i] = 0;\r\n            U[i] = D[i] = i;  //\u521D\u59CB\u72B6\u6001\
    \u4E0B,\u4E0A\u4E0B\u81EA\u5DF1\u6307\u5411\u81EA\u5DF1(\u4E5F\u5C31\u77E5\u9053\
    \u4E86\u5934\u7ED3\u70B9\u7684\u503C\u4E3Ai)\r\n            L[i] = i - 1;\r\n\
    \            R[i] = i + 1;\r\n        }\r\n        R[m] = 0, L[0] = m;  //\u73AF\
    \u72B6,\u4E0B\u9762\u7684Link\u4E00\u6837\u4E5F\u662F\u73AF,\u8FD9\u6837\uFF0C\
    \u4E0D\u7BA1\u4ECE\u4E00\u884C\u4E2D\u7684\u4EFB\u610F\u4E00\u4E2A\u7ED3\u70B9\
    \u90FD\u53EF\u4EE5\u904D\u5386\u5B8C\u8FD9\u4E00\u884C.\r\n        size = m; \
    \           //\u7F16\u53F7,\u6BCF\u5217\u7684\u5934\u7ED3\u70B9\u7F16\u53F71-m\uFF0C\
    \u6240\u4EE5size\u4ECEm+1\u5F00\u59CB\r\n        for (int i = 1; i <= n; i++)\r\
    \n            H[i] = -1;\r\n    }\r\n\r\n    void exact_remove(int c)  //\u5220\
    \u9664\u8282\u70B9c(\u5217c),\u5E76\u4E14\u5220\u9664\u6240\u6709\u5728\u8FD9\u4E00\
    \u5217\u7684\u8282\u70B9\u6240\u5728\u7684\u884C\u4E2D\u7684\u6240\u6709\u7684\
    \u8282\u70B9\u3002\u3002\r\n    {\r\n        L[R[c]] = L[c];\r\n        R[L[c]]\
    \ = R[c];\r\n        for (int i = D[c]; i != c; i = D[i])\r\n            for (int\
    \ j = R[i]; j != i; j = R[j]) {\r\n                U[D[j]] = U[j];\r\n       \
    \         D[U[j]] = D[j];\r\n                --S[Col[j]];\r\n            }\r\n\
    \    }\r\n\r\n    void repeat_remove(int c)  //\u53EA\u5220\u9664\u5217\r\n  \
    \  {\r\n        for (int i = D[c]; i != c; i = D[i])\r\n            L[R[i]] =\
    \ L[i], R[L[i]] = R[i];\r\n    }\r\n\r\n    void exact_resume(int c)  //\u6062\
    \u590D\u8282\u70B9c(\u5217c),\u4EE5\u53CA\u6062\u590D\u6240\u6709\u5728\u8FD9\u4E00\
    \u5217\u7684\u8282\u70B9\u6240\u5728\u7684\u884C\u4E2D\u7684\u6240\u6709\u7684\
    \u8282\u70B9\u3002\r\n    {\r\n        for (int i = U[c]; i != c; i = U[i])\r\n\
    \            for (int j = L[i]; j != i; j = L[j])\r\n                ++S[Col[U[D[j]]\
    \ = D[U[j]] = j]];\r\n        L[R[c]] = R[L[c]] = c;\r\n    }\r\n\r\n    void\
    \ repeat_resume(int c) {\r\n        for (int i = U[c]; i != c; i = U[i])\r\n \
    \           L[R[i]] = R[L[i]] = i;\r\n    }\r\n\r\n    int f()  //\u4F30\u4EF7\
    \u51FD\u6570\r\n    {\r\n        vector<bool> vv(m + 1);\r\n        int ret =\
    \ 0, c, i, j;\r\n        for (c = R[0]; c != 0; c = R[c]) vv[c] = 1;\r\n     \
    \   for (c = R[0]; c != 0; c = R[c])\r\n            if (vv[c]) {\r\n         \
    \       ret++, vv[c] = 0;\r\n                for (i = D[c]; i != c; i = D[i])\r\
    \n                    for (j = R[i]; j != i; j = R[j])\r\n                   \
    \     vv[Col[j]] = 0;\r\n            }\r\n        return ret;\r\n    }\r\n\r\n\
    \   public:\r\n    const int inf = numeric_limits<int>::max() / 2;\r\n    vector<int>\
    \ ans;\r\n    int ansd;\r\n    DLX(int _n, int _m) {\r\n        n = _n;\r\n  \
    \      m = _m;\r\n        int maxnnode = n * m + 1;\r\n        U.resize(maxnnode);\r\
    \n        D.resize(maxnnode);\r\n        L.resize(maxnnode);\r\n        R.resize(maxnnode);\r\
    \n        Row.resize(maxnnode);\r\n        Col.resize(maxnnode);\r\n        H.resize(n\
    \ + 1);\r\n        S.resize(m + 1);\r\n        ans.resize(n + 1);\r\n        init(n,\
    \ m);\r\n    }\r\n    DLX() {}\r\n\r\n    void link(int r, int c)  //\u7B2Cr\u884C\
    ,\u7B2Cc\u5217\r\n    {\r\n        ++S[Col[++size] = c];  //\u7B2Csize\u4E2A\u7ED3\
    \u70B9\u7684\u5217\u4E3Ac,\u5F53\u524D\u5217\u7684\u8282\u70B9\u6570++\r\n   \
    \     Row[size] = r;         //\u7B2Csize\u4E2A\u8282\u70B9\u884C\u4F4D\u7F6E\u4E3A\
    r\r\n        D[size] = D[c];\r\n        U[D[c]] = size;\r\n        U[size] = c;\r\
    \n        D[c] = size;\r\n        if (H[r] < 0)\r\n            H[r] = L[size]\
    \ = R[size] = size;\r\n        else {\r\n            R[size] = R[H[r]];\r\n  \
    \          L[R[H[r]]] = size;\r\n            L[size] = H[r];\r\n            R[H[r]]\
    \ = size;\r\n        }\r\n    }\r\n\r\n    // \u548C\u666E\u901A\u641C\u7D22\u4E00\
    \u6837\uFF0C\u8FD9\u91CC\u8868\u793A\u641C\u7D22\u6210\u529F\uFF0C\u53EF\u4EE5\
    \u5F97\u5230\u65B9\u6848\uFF0C\u4E5F\u53EF\u4EE5\u5F97\u5230\u6240\u6709\u65B9\
    \u6848\u7684\u4E2A\u6570\u3002\r\n    // \u770B\u9898\u76EE\u8981\u6C42, \u8FD9\
    \u91CC\u662F\u53EA\u5F97\u5230 1 \u4E2A\u65B9\u6848\r\n    // \u7CBE\u786E\u8986\
    \u76D6\uFF0C\u6BCF\u4E00\u5217\u6709\u4E14\u4EC5\u6709 1 \u4E2A 1\r\n    bool\
    \ exact_dance(int d)  //\u6DF1\u5EA6\r\n    {\r\n        if (R[0] == 0) {\r\n\
    \            ansd = d;\r\n            return true;\r\n        }\r\n        int\
    \ c = R[0];\r\n        for (int i = R[0]; i != 0; i = R[i])\r\n            if\
    \ (S[i] < S[c])\r\n                c = i;\r\n        exact_remove(c);  //\u627E\
    \u5230\u8282\u70B9\u6570\u6700\u5C11\u7684\u5217\uFF0C\u5F53\u524D\u5143\u7D20\
    \u4E0D\u662F\u539F\u56FE\u4E0A0,1\u7684\u8282\u70B9,\u800C\u662F\u5217\u5934\u7ED3\
    \u70B9\r\n        for (int i = D[c]; i != c; i = D[i]) {\r\n            ans[d]\
    \ = Row[i];  //\u5217\u5934\u7ED3\u70B9\u4E0B\u9762\u7684\u4E00\u4E2A\u8282\u70B9\
    \r\n            for (int j = R[i]; j != i; j = R[j])\r\n                exact_remove(Col[j]);\r\
    \n            if (exact_dance(d + 1)) return true;\r\n\r\n            for (int\
    \ j = L[i]; j != i; j = L[j])\r\n                exact_resume(Col[j]);\r\n   \
    \     }\r\n        exact_resume(c);\r\n        return false;\r\n    }\r\n    //\
    \ \u91CD\u590D\u8986\u76D6\uFF0C\u9009\u6700\u5C11\u7684\u884C\uFF0C\u4F7F\u5F97\
    \u6BCF\u4E00\u5217\u81F3\u5C11\u6709 1 \u4E2A 1\r\n    void repeat_dance(int d)\
    \ {\r\n        if (d + f() >= ansd) return;\r\n        if (R[0] == 0) {\r\n  \
    \          if (d < ansd) ansd = d;\r\n            // real_ans = ans; // \u5B58\
    \u65B9\u6848\r\n            return;\r\n        }\r\n        int c = R[0], i, j;\r\
    \n        for (i = R[0]; i; i = R[i])\r\n            if (S[i] < S[c]) c = i;\r\
    \n        for (i = D[c]; i != c; i = D[i]) {\r\n            ans[d] = Row[i];\r\
    \n            repeat_remove(i);\r\n            for (j = R[i]; j != i; j = R[j])\
    \ repeat_remove(j);\r\n            repeat_dance(d + 1);\r\n            for (j\
    \ = L[i]; j != i; j = L[j]) repeat_resume(j);\r\n            repeat_resume(i);\r\
    \n        }\r\n    }\r\n};\r\n// \u4E0B\u6807\u4ECE 1 \u5F00\u59CB"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/dancing_links.hpp
  requiredBy: []
  timestamp: '2022-10-09 21:28:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/dancing_links.hpp
layout: document
redirect_from:
- /library/src/misc/dancing_links.hpp
- /library/src/misc/dancing_links.hpp.html
title: Dancing Links
---
# Dancing Links

## 概要
Dancing Links 是一个用于解决精确覆盖问题和重复覆盖问题的算法。它的核心思想是将问题转化为矩阵，然后使用深度优先搜索的方法来解决问题。

### `DLX`
`DLX` 类是 Dancing Links 的核心类，它提供了一些方法来解决精确覆盖问题和重复覆盖问题。
- `DLX(int n, int m)` : 构造一个 $n \times m$ 的矩阵，初始值均为 $0$ 。区间范围为 $[0, n)$ 和 $[0, m)$ 。

- `void link(int r, int c)` : 将矩阵中第 $r$ 行第 $c$ 列的数置为 $1$ 。
- `bool exact_dance(int d)`: 用于解决精确覆盖问题。它返回一个布尔值，表示是否存在一个 $d$ 行的子矩阵，使得每一列都恰好有一个 $1$ 。初始 $d$ 的值为 $0$ 。
- `bool repeat_dance(int d)`: 用于解决重复覆盖问题。它返回一个布尔值，表示是否存在一个 $d$ 行的子矩阵，使得每一列都至少有一个 $1$ 。初始 $d$ 的值为 $0$ 。

## 常见问题

## 题集