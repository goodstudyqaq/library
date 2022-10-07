---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/matrix.md
    document_title: Matrix
    links:
    - https://atcoder.jp/contests/abc253/tasks/abc253_h
  bundledCode: "#line 1 \"src/math/matrix.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief Matrix\r\n@docs docs/matrix.md\r\n*/\r\n\r\
    \ntypedef long long ll;\r\ntemplate <typename T = ll>\r\nstruct Matrix {\r\n \
    \   int n, m;\r\n    vector<vector<T>> mat;\r\n    Matrix(int n, int m, const\
    \ T& val = T()) : n(n), m(m), mat(n, vector<T>(m, val)) {}\r\n    Matrix(int n,\
    \ const T& val = T()) : n(n), m(n), mat(n, vector<T>(n, val)) {}\r\n    Matrix(const\
    \ vector<vector<T>>& mat) : n(mat.size()), m(mat[0].size()), mat(mat) {}\r\n\r\
    \n    static Matrix I(int n) {\r\n        Matrix res(n);\r\n        for (int i\
    \ = 0; i < n; i++) res[i][i] = 1;\r\n        return res;\r\n    }\r\n\r\n    vector<T>&\
    \ operator[](int i) { return mat[i]; }\r\n\r\n    Matrix operator+(const Matrix&\
    \ r) const {\r\n        assert(n == r.n && m == r.m);\r\n        Matrix res(n,\
    \ m);\r\n        for (int i = 0; i < n; i++)\r\n            for (int j = 0; j\
    \ < m; j++) res[i][j] = mat[i][j] + r[i][j];\r\n        return res;\r\n    }\r\
    \n\r\n    Matrix operator-(const Matrix& r) const {\r\n        assert(n == r.n\
    \ && m == r.m);\r\n        Matrix res(n, m);\r\n        for (int i = 0; i < n;\
    \ i++)\r\n            for (int j = 0; j < m; j++) res[i][j] = mat[i][j] - r[i][j];\r\
    \n        return res;\r\n    }\r\n\r\n    Matrix operator*(const Matrix& r) const\
    \ {\r\n        assert(m == r.n);\r\n        Matrix res(n, r.m);\r\n        for\
    \ (int i = 0; i < n; i++)\r\n            for (int j = 0; j < r.m; j++)\r\n   \
    \             for (int k = 0; k < m; k++) res[i][j] += mat[i][k] * r[k][j];\r\n\
    \        return res;\r\n    }\r\n\r\n    Matrix operator^(ll k) const {\r\n  \
    \      assert(n == m);\r\n        Matrix res = I(n), a = *this;\r\n        while\
    \ (k > 0) {\r\n            if (k & 1) res = res * a;\r\n            a = a * a;\r\
    \n            k >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n\r\n  \
    \  static to_string(const Matrix& mat) {\r\n        string res = \"\";\r\n   \
    \     for (int i = 0; i < mat.n; i++) {\r\n            for (int j = 0; j < mat.m;\
    \ j++) res += to_string(mat[i][j]) + \" \";\r\n            res += \"\\n\";\r\n\
    \        }\r\n        return res;\r\n    }\r\n};\r\ntemplate <typename T = ll>\r\
    \nstruct Det : Matrix<T> {\r\n    //\u884C\u5217\u5F0F\u8F97\u8F6C\u76F8\u9664\
    \u6CD5\r\n    /*\r\n    https://atcoder.jp/contests/abc253/tasks/abc253_h\r\n\
    \    \u77E9\u9635\u6811\u5B9A\u7406\uFF1A\u7EF4\u62A4\u4E00\u4E2A\u5EA6\u6570\u77E9\
    \u9635D \u548C\u4E00\u4E2A\u90BB\u63A5\u77E9\u9635A\uFF0CKirchhoff\u77E9\u9635\
    = D - A\uFF0C\u7136\u540E\u628A\u6700\u540E\u4E00\u884C\u548C\u6700\u540E\u4E00\
    \u5217\u5220\u6389\uFF0C\u7B97\u884C\u5217\u5F0F\uFF0C\u5C31\u662F\u6811\u7684\
    \u4E2A\u6570\u3002\r\n    */\r\n    T get() {\r\n        assert(this->n == this->m);\r\
    \n        T res = 1;\r\n        for (int i = 0; i < this->n; i++) {\r\n      \
    \      for (int j = i + 1; j < this->n; j++) {\r\n                while (this->mat[j][i]\
    \ != 0) {\r\n                    T t = this->mat[i][i] / this->mat[j][i];\r\n\
    \                    for (int k = i; k < this->n; k++) {\r\n                 \
    \       this->mat[i][k] -= this->mat[j][k] * t;\r\n                        swap(this->mat[i][k],\
    \ this->mat[j][k]);\r\n                    }\r\n                    res = -res;\r\
    \n                }\r\n            }\r\n            if (this->mat[i][i] == 0)\
    \ return 0;\r\n            res *= this->mat[i][i];\r\n        }\r\n        return\
    \ res;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief Matrix\r\
    \n@docs docs/matrix.md\r\n*/\r\n\r\ntypedef long long ll;\r\ntemplate <typename\
    \ T = ll>\r\nstruct Matrix {\r\n    int n, m;\r\n    vector<vector<T>> mat;\r\n\
    \    Matrix(int n, int m, const T& val = T()) : n(n), m(m), mat(n, vector<T>(m,\
    \ val)) {}\r\n    Matrix(int n, const T& val = T()) : n(n), m(n), mat(n, vector<T>(n,\
    \ val)) {}\r\n    Matrix(const vector<vector<T>>& mat) : n(mat.size()), m(mat[0].size()),\
    \ mat(mat) {}\r\n\r\n    static Matrix I(int n) {\r\n        Matrix res(n);\r\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\r\n        return res;\r\n\
    \    }\r\n\r\n    vector<T>& operator[](int i) { return mat[i]; }\r\n\r\n    Matrix\
    \ operator+(const Matrix& r) const {\r\n        assert(n == r.n && m == r.m);\r\
    \n        Matrix res(n, m);\r\n        for (int i = 0; i < n; i++)\r\n       \
    \     for (int j = 0; j < m; j++) res[i][j] = mat[i][j] + r[i][j];\r\n       \
    \ return res;\r\n    }\r\n\r\n    Matrix operator-(const Matrix& r) const {\r\n\
    \        assert(n == r.n && m == r.m);\r\n        Matrix res(n, m);\r\n      \
    \  for (int i = 0; i < n; i++)\r\n            for (int j = 0; j < m; j++) res[i][j]\
    \ = mat[i][j] - r[i][j];\r\n        return res;\r\n    }\r\n\r\n    Matrix operator*(const\
    \ Matrix& r) const {\r\n        assert(m == r.n);\r\n        Matrix res(n, r.m);\r\
    \n        for (int i = 0; i < n; i++)\r\n            for (int j = 0; j < r.m;\
    \ j++)\r\n                for (int k = 0; k < m; k++) res[i][j] += mat[i][k] *\
    \ r[k][j];\r\n        return res;\r\n    }\r\n\r\n    Matrix operator^(ll k) const\
    \ {\r\n        assert(n == m);\r\n        Matrix res = I(n), a = *this;\r\n  \
    \      while (k > 0) {\r\n            if (k & 1) res = res * a;\r\n          \
    \  a = a * a;\r\n            k >>= 1;\r\n        }\r\n        return res;\r\n\
    \    }\r\n\r\n    static to_string(const Matrix& mat) {\r\n        string res\
    \ = \"\";\r\n        for (int i = 0; i < mat.n; i++) {\r\n            for (int\
    \ j = 0; j < mat.m; j++) res += to_string(mat[i][j]) + \" \";\r\n            res\
    \ += \"\\n\";\r\n        }\r\n        return res;\r\n    }\r\n};\r\ntemplate <typename\
    \ T = ll>\r\nstruct Det : Matrix<T> {\r\n    //\u884C\u5217\u5F0F\u8F97\u8F6C\u76F8\
    \u9664\u6CD5\r\n    /*\r\n    https://atcoder.jp/contests/abc253/tasks/abc253_h\r\
    \n    \u77E9\u9635\u6811\u5B9A\u7406\uFF1A\u7EF4\u62A4\u4E00\u4E2A\u5EA6\u6570\
    \u77E9\u9635D \u548C\u4E00\u4E2A\u90BB\u63A5\u77E9\u9635A\uFF0CKirchhoff\u77E9\
    \u9635= D - A\uFF0C\u7136\u540E\u628A\u6700\u540E\u4E00\u884C\u548C\u6700\u540E\
    \u4E00\u5217\u5220\u6389\uFF0C\u7B97\u884C\u5217\u5F0F\uFF0C\u5C31\u662F\u6811\
    \u7684\u4E2A\u6570\u3002\r\n    */\r\n    T get() {\r\n        assert(this->n\
    \ == this->m);\r\n        T res = 1;\r\n        for (int i = 0; i < this->n; i++)\
    \ {\r\n            for (int j = i + 1; j < this->n; j++) {\r\n               \
    \ while (this->mat[j][i] != 0) {\r\n                    T t = this->mat[i][i]\
    \ / this->mat[j][i];\r\n                    for (int k = i; k < this->n; k++)\
    \ {\r\n                        this->mat[i][k] -= this->mat[j][k] * t;\r\n   \
    \                     swap(this->mat[i][k], this->mat[j][k]);\r\n            \
    \        }\r\n                    res = -res;\r\n                }\r\n       \
    \     }\r\n            if (this->mat[i][i] == 0) return 0;\r\n            res\
    \ *= this->mat[i][i];\r\n        }\r\n        return res;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix.hpp
layout: document
redirect_from:
- /library/src/math/matrix.hpp
- /library/src/math/matrix.hpp.html
title: Matrix
---
# 矩阵

## 概要
Matrix 是一个二维数组，它的每个元素都是一个数字。Matrix 有两个属性：行数和列数。Matrix 的行数和列数都是整数，且行数和列数都是大于等于 1 的整数。Matrix 的行数和列数都是固定的，不可变的。
### `Matrix`
`Matrix` 是一个矩阵的模板，它的用法如下：
```cpp
Matrix<int> matrix(2, 3);
matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[0][2] = 3;
matrix[1][0] = 4;
matrix[1][1] = 5;
matrix[1][2] = 6;
```
它有以下成员函数：
- `Matrix(int n, int m, const T& value = T())`：构造一个 `n` 行 `m` 列的矩阵，每个元素都是 `value`。
- `Matrix(int n, const T& value = T())`：构造一个 `n` 行 `n` 列的矩阵，每个元素都是 `value`。
- `Matrix(const vector<vector<T>>& values)`：构造一个矩阵，它的元素是 `values`。
- `static Matrix I(int n)`：构造一个 `n` 行 `n` 列的单位矩阵。
- `vector<T>& operator[](int i)`：返回第 `i` 行。
- `Matrix operator+(const Matrix& other) const`：返回两个矩阵的和。
- `Matrix operator-(const Matrix& other) const`：返回两个矩阵的差。
- `Matrix operator*(const Matrix& other) const`：返回两个矩阵的乘积。
- `Matrix operator^(long long k) const`：返回矩阵的 `k` 次幂。
- `static to_string(const Matrix& matrix)`：返回矩阵的字符串表示, 用于调试.

### `Det`
`Det` 是一个矩阵行列式的模板，它的用法如下：
```cpp
Matrix<int> matrix(2, 2);
matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[1][0] = 3;
matrix[1][1] = 4;
Det<int> det(matrix);
det.get(); // 1 * 4 - 2 * 3 = -2

```



## 常见问题

## 题集
