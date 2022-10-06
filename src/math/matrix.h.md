---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/matrix.md
    document_title: Matrix
    links:
    - https://atcoder.jp/contests/abc253/tasks/abc253_h
  bundledCode: "#line 1 \"src/math/matrix.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n/*\r\n@brief Matrix\r\n@docs docs/matrix.md\r\n*/\r\n\r\nconst int\
    \ mod = 1e9 + 7;\r\nconst int maxn = 105;\r\ntypedef long long ll;\r\nstruct Matrix\
    \ {\r\n    int n, m;\r\n    vector<vector<long long>> mat;\r\n    Matrix() {}\r\
    \n    Matrix(int _n) {\r\n        n = _n;\r\n        m = _n;\r\n        mat.resize(n,\
    \ vector<long long>(n, 0));\r\n    }\r\n\r\n    Matrix(int _n, int _m) {\r\n \
    \       n = _n;\r\n        m = _m;\r\n        mat.resize(n, vector<long long>(m,\
    \ 0));\r\n    }\r\n\r\n    Matrix operator*(const Matrix& b) const {\r\n     \
    \   assert(m == b.n);\r\n        Matrix res = Matrix(n, b.m);\r\n        for (int\
    \ i = 0; i < n; i++)\r\n            for (int j = 0; j < b.m; j++)\r\n        \
    \        for (int k = 0; k < m; k++) {\r\n                    long long tmp =\
    \ (mat[i][k] * b.mat[k][j]) % mod;\r\n                    (res.mat[i][j] += tmp)\
    \ %= mod;\r\n                }\r\n        return res;\r\n    }\r\n\r\n    Matrix\
    \ operator^(long long num) {\r\n        assert(n == m);\r\n        Matrix res\
    \ = Matrix(n);\r\n        for (int i = 0; i < n; i++) {\r\n            res.mat[i][i]\
    \ = 1;\r\n        }\r\n        Matrix tmp = *this;\r\n        while (num) {\r\n\
    \            if (num % 2) res = res * tmp;\r\n            num /= 2;\r\n      \
    \      tmp = tmp * tmp;\r\n        }\r\n        return res;\r\n    }\r\n\r\n \
    \   //\u884C\u5217\u5F0F\u8F97\u8F6C\u76F8\u9664\u6CD5\r\n    /*\r\n    https://atcoder.jp/contests/abc253/tasks/abc253_h\r\
    \n    \u77E9\u9635\u6811\u5B9A\u7406\uFF1A\u7EF4\u62A4\u4E00\u4E2A\u5EA6\u6570\
    \u77E9\u9635D \u548C\u4E00\u4E2A\u90BB\u63A5\u77E9\u9635A\uFF0CKirchhoff\u77E9\
    \u9635= D - A\uFF0C\u7136\u540E\u628A\u6700\u540E\u4E00\u884C\u548C\u6700\u540E\
    \u4E00\u5217\u5220\u6389\uFF0C\u7B97\u884C\u5217\u5F0F\uFF0C\u5C31\u662F\u6811\
    \u7684\u4E2A\u6570\u3002\r\n    */\r\n    ll det(ll mod) {\r\n        ll ret =\
    \ 1;\r\n        for (int i = 0; i < n; i++) {\r\n            if (mat[i][i] < 0)\
    \ {\r\n                ret = -ret;\r\n                for (int k = i; k < n; k++)\
    \ mat[i][k] = -mat[i][k];\r\n            }\r\n            for (int j = i + 1;\
    \ j < n; j++) {\r\n                for (int k = i; k < n; k++) mat[i][k] %= mod,\
    \ mat[j][k] %= mod;\r\n                while (mat[j][i]) {\r\n               \
    \     if (mat[j][i] < 0) {\r\n                        ret = -ret;\r\n        \
    \                for (int k = i; k < n; k++) mat[j][k] = -mat[j][k];\r\n     \
    \               }\r\n                    ll t = mat[i][i] / mat[j][i];\r\n   \
    \                 for (int k = i; k < n; k++) mat[i][k] = (mat[i][k] - t * mat[j][k])\
    \ % mod;\r\n                    for (int k = i; k < n; k++) swap(mat[i][k], mat[j][k]);\r\
    \n                    ret = -ret;\r\n                }\r\n            }\r\n  \
    \          if (mat[i][i] == 0) return 0;\r\n            ret = ret * mat[i][i]\
    \ % mod;\r\n        }\r\n        return (ret + mod) % mod;\r\n    }\r\n};\r\n\r\
    \nstring to_string(Matrix& m) {\r\n    string res = \"\\n\";\r\n    for (int i\
    \ = 0; i < m.n; i++) {\r\n        for (int j = 0; j < m.n; j++) {\r\n        \
    \    res += to_string(m.mat[i][j]) + \" \";\r\n        }\r\n        if (i != m.n\
    \ - 1)\r\n            res += \"\\n\";\r\n    }\r\n    return res;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief Matrix\r\
    \n@docs docs/matrix.md\r\n*/\r\n\r\nconst int mod = 1e9 + 7;\r\nconst int maxn\
    \ = 105;\r\ntypedef long long ll;\r\nstruct Matrix {\r\n    int n, m;\r\n    vector<vector<long\
    \ long>> mat;\r\n    Matrix() {}\r\n    Matrix(int _n) {\r\n        n = _n;\r\n\
    \        m = _n;\r\n        mat.resize(n, vector<long long>(n, 0));\r\n    }\r\
    \n\r\n    Matrix(int _n, int _m) {\r\n        n = _n;\r\n        m = _m;\r\n \
    \       mat.resize(n, vector<long long>(m, 0));\r\n    }\r\n\r\n    Matrix operator*(const\
    \ Matrix& b) const {\r\n        assert(m == b.n);\r\n        Matrix res = Matrix(n,\
    \ b.m);\r\n        for (int i = 0; i < n; i++)\r\n            for (int j = 0;\
    \ j < b.m; j++)\r\n                for (int k = 0; k < m; k++) {\r\n         \
    \           long long tmp = (mat[i][k] * b.mat[k][j]) % mod;\r\n             \
    \       (res.mat[i][j] += tmp) %= mod;\r\n                }\r\n        return\
    \ res;\r\n    }\r\n\r\n    Matrix operator^(long long num) {\r\n        assert(n\
    \ == m);\r\n        Matrix res = Matrix(n);\r\n        for (int i = 0; i < n;\
    \ i++) {\r\n            res.mat[i][i] = 1;\r\n        }\r\n        Matrix tmp\
    \ = *this;\r\n        while (num) {\r\n            if (num % 2) res = res * tmp;\r\
    \n            num /= 2;\r\n            tmp = tmp * tmp;\r\n        }\r\n     \
    \   return res;\r\n    }\r\n\r\n    //\u884C\u5217\u5F0F\u8F97\u8F6C\u76F8\u9664\
    \u6CD5\r\n    /*\r\n    https://atcoder.jp/contests/abc253/tasks/abc253_h\r\n\
    \    \u77E9\u9635\u6811\u5B9A\u7406\uFF1A\u7EF4\u62A4\u4E00\u4E2A\u5EA6\u6570\u77E9\
    \u9635D \u548C\u4E00\u4E2A\u90BB\u63A5\u77E9\u9635A\uFF0CKirchhoff\u77E9\u9635\
    = D - A\uFF0C\u7136\u540E\u628A\u6700\u540E\u4E00\u884C\u548C\u6700\u540E\u4E00\
    \u5217\u5220\u6389\uFF0C\u7B97\u884C\u5217\u5F0F\uFF0C\u5C31\u662F\u6811\u7684\
    \u4E2A\u6570\u3002\r\n    */\r\n    ll det(ll mod) {\r\n        ll ret = 1;\r\n\
    \        for (int i = 0; i < n; i++) {\r\n            if (mat[i][i] < 0) {\r\n\
    \                ret = -ret;\r\n                for (int k = i; k < n; k++) mat[i][k]\
    \ = -mat[i][k];\r\n            }\r\n            for (int j = i + 1; j < n; j++)\
    \ {\r\n                for (int k = i; k < n; k++) mat[i][k] %= mod, mat[j][k]\
    \ %= mod;\r\n                while (mat[j][i]) {\r\n                    if (mat[j][i]\
    \ < 0) {\r\n                        ret = -ret;\r\n                        for\
    \ (int k = i; k < n; k++) mat[j][k] = -mat[j][k];\r\n                    }\r\n\
    \                    ll t = mat[i][i] / mat[j][i];\r\n                    for\
    \ (int k = i; k < n; k++) mat[i][k] = (mat[i][k] - t * mat[j][k]) % mod;\r\n \
    \                   for (int k = i; k < n; k++) swap(mat[i][k], mat[j][k]);\r\n\
    \                    ret = -ret;\r\n                }\r\n            }\r\n   \
    \         if (mat[i][i] == 0) return 0;\r\n            ret = ret * mat[i][i] %\
    \ mod;\r\n        }\r\n        return (ret + mod) % mod;\r\n    }\r\n};\r\n\r\n\
    string to_string(Matrix& m) {\r\n    string res = \"\\n\";\r\n    for (int i =\
    \ 0; i < m.n; i++) {\r\n        for (int j = 0; j < m.n; j++) {\r\n          \
    \  res += to_string(m.mat[i][j]) + \" \";\r\n        }\r\n        if (i != m.n\
    \ - 1)\r\n            res += \"\\n\";\r\n    }\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix.h
layout: document
redirect_from:
- /library/src/math/matrix.h
- /library/src/math/matrix.h.html
title: Matrix
---
