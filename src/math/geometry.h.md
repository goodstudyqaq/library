---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/geometry.md
    document_title: Geometry
    links: []
  bundledCode: "#line 1 \"src/math/geometry.h\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n/*\r\n@brief Geometry\r\n@docs docs/geometry.md\r\n*/\r\n\r\
    \nnamespace Geometry {\r\nusing ll = long long;\r\nusing ld = long double;\r\n\
    struct Point {\r\n    ll x, y;\r\n    Point() : x(), y() {}\r\n    Point(ll _x,\
    \ ll _y) : x(_x), y(_y) {}\r\n\r\n    Point operator+(const Point &a) const {\r\
    \n        return Point(x + a.x, y + a.y);\r\n    }\r\n    Point operator-(const\
    \ Point &a) const {\r\n        return Point(x - a.x, y - a.y);\r\n    }\r\n  \
    \  ll operator*(const Point &a) const {\r\n        return x * a.y - y * a.x;\r\
    \n    }\r\n\r\n    double len() const {\r\n        return sqrtl((ld)x * x + (ld)y\
    \ * y);\r\n    }\r\n\r\n    bool operator<(const Point &a) const {\r\n       \
    \ if (x != a.x) return x < a.x;\r\n        return y < a.y;\r\n    }\r\n};\r\n\r\
    \nbool cmp(const Point &v, const Point &u) {\r\n    ll x = v * u;\r\n    if (x\
    \ != 0) return x > 0;\r\n    return v.len() < u.len();\r\n}\r\n\r\nvector<Point>\
    \ graham(vector<Point> &a) {\r\n    int n = a.size();\r\n    vector<Point> h(n);\r\
    \n\r\n    sort(a.begin(), a.end());\r\n    for (int i = 1; i < n; i++) {\r\n \
    \       a[i] = a[i] - a[0];\r\n    }\r\n    sort(a.begin(), a.end(), cmp);\r\n\
    \    int m = 0;\r\n    for (int i = 0; i < n; i++) {\r\n        while (m > 1 &&\
    \ (a[i] - h[m - 1]) * (a[i] - h[m - 2]) >= 0) m--;\r\n        h[m++] = a[i];\r\
    \n    }\r\n    h.resize(m);\r\n    return h;\r\n}\r\n\r\n}  // namespace Geometry\r\
    \n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief Geometry\r\
    \n@docs docs/geometry.md\r\n*/\r\n\r\nnamespace Geometry {\r\nusing ll = long\
    \ long;\r\nusing ld = long double;\r\nstruct Point {\r\n    ll x, y;\r\n    Point()\
    \ : x(), y() {}\r\n    Point(ll _x, ll _y) : x(_x), y(_y) {}\r\n\r\n    Point\
    \ operator+(const Point &a) const {\r\n        return Point(x + a.x, y + a.y);\r\
    \n    }\r\n    Point operator-(const Point &a) const {\r\n        return Point(x\
    \ - a.x, y - a.y);\r\n    }\r\n    ll operator*(const Point &a) const {\r\n  \
    \      return x * a.y - y * a.x;\r\n    }\r\n\r\n    double len() const {\r\n\
    \        return sqrtl((ld)x * x + (ld)y * y);\r\n    }\r\n\r\n    bool operator<(const\
    \ Point &a) const {\r\n        if (x != a.x) return x < a.x;\r\n        return\
    \ y < a.y;\r\n    }\r\n};\r\n\r\nbool cmp(const Point &v, const Point &u) {\r\n\
    \    ll x = v * u;\r\n    if (x != 0) return x > 0;\r\n    return v.len() < u.len();\r\
    \n}\r\n\r\nvector<Point> graham(vector<Point> &a) {\r\n    int n = a.size();\r\
    \n    vector<Point> h(n);\r\n\r\n    sort(a.begin(), a.end());\r\n    for (int\
    \ i = 1; i < n; i++) {\r\n        a[i] = a[i] - a[0];\r\n    }\r\n    sort(a.begin(),\
    \ a.end(), cmp);\r\n    int m = 0;\r\n    for (int i = 0; i < n; i++) {\r\n  \
    \      while (m > 1 && (a[i] - h[m - 1]) * (a[i] - h[m - 2]) >= 0) m--;\r\n  \
    \      h[m++] = a[i];\r\n    }\r\n    h.resize(m);\r\n    return h;\r\n}\r\n\r\
    \n}  // namespace Geometry\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/geometry.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/geometry.h
layout: document
redirect_from:
- /library/src/math/geometry.h
- /library/src/math/geometry.h.html
title: Geometry
---
