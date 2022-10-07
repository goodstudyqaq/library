---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/geometry.md
    document_title: Geometry
    links: []
  bundledCode: "#line 1 \"src/math/geometry.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n/*\r\n@brief Geometry\r\n@docs docs/geometry.md\r\n*/\r\n\r\
    \ntemplate <typename T = int>\r\nstruct Point {\r\n    T x, y;\r\n    Point()\
    \ : x(), y() {}\r\n    Point(T x, T y) : x(x), y(y) {}\r\n\r\n    Point operator+(const\
    \ Point &p) const { return Point(x + p.x, y + p.y); }\r\n    Point operator-(const\
    \ Point &p) const { return Point(x - p.x, y - p.y); }\r\n    Point operator*(const\
    \ T &k) const { return Point(x * k, y * k); }\r\n    // \u70B9\u79EF, a * b =\
    \ |a| * |b| * cos(a, b), \u70B9\u4E58\u7684\u51E0\u4F55\u610F\u4E49\u662F\u53EF\
    \u4EE5\u7528\u6765\u8868\u5F81\u6216\u8BA1\u7B97\u4E24\u4E2A\u5411\u91CF\u4E4B\
    \u95F4\u7684\u5939\u89D2\uFF0C\u4EE5\u53CA\u5728b\u5411\u91CF\u5728a\u5411\u91CF\
    \u65B9\u5411\u4E0A\u7684\u6295\u5F71\r\n    T operator*(const Point &p) const\
    \ { return x * p.x + y * p.y; }\r\n\r\n    // \u53C9\u79EF, a x b = |a| * |b|\
    \ * sin(a, b), \u5728\u4E8C\u7EF4\u7A7A\u95F4\u4E2D\uFF0C\u53C9\u79EF\u7684\u51E0\
    \u4F55\u610F\u4E49\u662F\u53EF\u4EE5\u7528\u6765\u8BA1\u7B97\u4E24\u4E2A\u5411\
    \u91CF\u7684\u9762\u79EF\uFF0C\u4EE5\u53CA\u5224\u65AD\u4E24\u4E2A\u5411\u91CF\
    \u7684\u65B9\u5411\r\n    T operator^(const Point &p) const { return x * p.y -\
    \ y * p.x; }\r\n    T abs2() const { return x * x + y * y; }\r\n\r\n    bool operator<(const\
    \ Point &p) const { return x != p.x ? x < p.x : y < p.y; }\r\n};\r\n\r\ntemplate\
    \ <typename T = int>\r\nstruct Graham {\r\n    bool cmp(const Point<T> &a, const\
    \ Point<T> &b) const {\r\n        T x = a ^ b;\r\n        return x == 0 ? a.length()\
    \ < b.length() : x > 0;\r\n    }\r\n\r\n    vector<Point<T>> graham(vector<Point<T>>\
    \ &ps) {\r\n        sort(ps.begin(), ps.end());\r\n        ps.erase(unique(ps.begin(),\
    \ ps.end()), ps.end());\r\n        int n = ps.size();\r\n        if (n <= 1) return\
    \ ps;\r\n        vector<Point<T>> qs(n);\r\n\r\n        int k = 0;\r\n       \
    \ for (int i = 0; i < n; i++) {\r\n            while (k > 1 && (qs[k - 1] - qs[k\
    \ - 2]) ^ (ps[i] - qs[k - 1]) <= 0)\r\n                k--;\r\n            qs[k++]\
    \ = ps[i];\r\n        }\r\n\r\n        return qs;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Geometry\r\
    \n@docs docs/geometry.md\r\n*/\r\n\r\ntemplate <typename T = int>\r\nstruct Point\
    \ {\r\n    T x, y;\r\n    Point() : x(), y() {}\r\n    Point(T x, T y) : x(x),\
    \ y(y) {}\r\n\r\n    Point operator+(const Point &p) const { return Point(x +\
    \ p.x, y + p.y); }\r\n    Point operator-(const Point &p) const { return Point(x\
    \ - p.x, y - p.y); }\r\n    Point operator*(const T &k) const { return Point(x\
    \ * k, y * k); }\r\n    // \u70B9\u79EF, a * b = |a| * |b| * cos(a, b), \u70B9\
    \u4E58\u7684\u51E0\u4F55\u610F\u4E49\u662F\u53EF\u4EE5\u7528\u6765\u8868\u5F81\
    \u6216\u8BA1\u7B97\u4E24\u4E2A\u5411\u91CF\u4E4B\u95F4\u7684\u5939\u89D2\uFF0C\
    \u4EE5\u53CA\u5728b\u5411\u91CF\u5728a\u5411\u91CF\u65B9\u5411\u4E0A\u7684\u6295\
    \u5F71\r\n    T operator*(const Point &p) const { return x * p.x + y * p.y; }\r\
    \n\r\n    // \u53C9\u79EF, a x b = |a| * |b| * sin(a, b), \u5728\u4E8C\u7EF4\u7A7A\
    \u95F4\u4E2D\uFF0C\u53C9\u79EF\u7684\u51E0\u4F55\u610F\u4E49\u662F\u53EF\u4EE5\
    \u7528\u6765\u8BA1\u7B97\u4E24\u4E2A\u5411\u91CF\u7684\u9762\u79EF\uFF0C\u4EE5\
    \u53CA\u5224\u65AD\u4E24\u4E2A\u5411\u91CF\u7684\u65B9\u5411\r\n    T operator^(const\
    \ Point &p) const { return x * p.y - y * p.x; }\r\n    T abs2() const { return\
    \ x * x + y * y; }\r\n\r\n    bool operator<(const Point &p) const { return x\
    \ != p.x ? x < p.x : y < p.y; }\r\n};\r\n\r\ntemplate <typename T = int>\r\nstruct\
    \ Graham {\r\n    bool cmp(const Point<T> &a, const Point<T> &b) const {\r\n \
    \       T x = a ^ b;\r\n        return x == 0 ? a.length() < b.length() : x >\
    \ 0;\r\n    }\r\n\r\n    vector<Point<T>> graham(vector<Point<T>> &ps) {\r\n \
    \       sort(ps.begin(), ps.end());\r\n        ps.erase(unique(ps.begin(), ps.end()),\
    \ ps.end());\r\n        int n = ps.size();\r\n        if (n <= 1) return ps;\r\
    \n        vector<Point<T>> qs(n);\r\n\r\n        int k = 0;\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            while (k > 1 && (qs[k - 1] - qs[k - 2])\
    \ ^ (ps[i] - qs[k - 1]) <= 0)\r\n                k--;\r\n            qs[k++] =\
    \ ps[i];\r\n        }\r\n\r\n        return qs;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/geometry.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/geometry.hpp
layout: document
redirect_from:
- /library/src/math/geometry.hpp
- /library/src/math/geometry.hpp.html
title: Geometry
---
# 计算几何

## 概要
记录一下常见的计算几何模板
### `Point`
`Point` 是一个模板类，包含两个 `T` 类型的成员 `x` 和 `y`，表示一个二维平面上的点，也可以表示一个向量。主要有以下操作：
- `Point(T x, T y)`：创建一个点 `(x, y)` 。
- `Point operator+(const Point &rhs) const`：返回两个点的和。
- `Point operator-(const Point &rhs) const`：返回两个点的差。
- `Point operator*(T k) const`：返回点乘以一个数的结果。
- `T operator^(const Point &rhs) const`：返回两个点的叉积。
- `T operator*(const Point &rhs) const`：返回两个点的点积。
- `T abs2() const`：返回点的模的平方。
- `bool operator<(const Point &rhs) const`：按照 `x` 坐标从小到大排序，如果 `x` 坐标相同，则按照 `y` 坐标从小到大排序。

### `Graham`
`Graham` 是一个模板类，包含一个 `Point` 类型的模板参数 `T`，表示点的类型。主要有以下操作：
- `vector<Point<T>> graham(vector<Point<T>> points)`：返回凸包上的点，点按照逆时针排序。

## 常见问题

## 题集