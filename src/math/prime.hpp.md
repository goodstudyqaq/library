---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/prime.md
    document_title: "\u7D20\u6570\u7B5B"
    links: []
  bundledCode: "#line 1 \"src/math/prime.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n/*\r\n@brief \u7D20\u6570\u7B5B\r\n@docs docs/prime.md\r\n\
    */\r\n\r\nstruct Prime {\r\n    vector<int> primes;\r\n    vector<int> min_factor;\r\
    \n    vector<int> euler_phi;\r\n    vector<int> mobius;\r\n    // O(n)\r\n   \
    \ Prime(int n) {\r\n        min_factor.resize(n + 1);\r\n        euler_phi.resize(n\
    \ + 1);\r\n        mobius.resize(n + 1);\r\n        for (int i = 2; i <= n; i++)\
    \ {\r\n            if (min_factor[i] == 0) {\r\n                min_factor[i]\
    \ = i;\r\n                primes.push_back(i);\r\n                euler_phi[i]\
    \ = i - 1;\r\n                mobius[i] = -1;\r\n            }\r\n           \
    \ for (int j = 0; j < primes.size() && primes[j] <= min_factor[i] && i * primes[j]\
    \ <= n; j++) {\r\n                min_factor[i * primes[j]] = primes[j];\r\n \
    \               if (min_factor[i] == primes[j]) {\r\n                    euler_phi[i\
    \ * primes[j]] = euler_phi[i] * primes[j];\r\n                    mobius[i * primes[j]]\
    \ = 0;\r\n                } else {\r\n                    euler_phi[i * primes[j]]\
    \ = euler_phi[i] * (primes[j] - 1);\r\n                    mobius[i * primes[j]]\
    \ = -mobius[i];\r\n                }\r\n            }\r\n        }\r\n    }\r\n\
    };\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief \u7D20\u6570\
    \u7B5B\r\n@docs docs/prime.md\r\n*/\r\n\r\nstruct Prime {\r\n    vector<int> primes;\r\
    \n    vector<int> min_factor;\r\n    vector<int> euler_phi;\r\n    vector<int>\
    \ mobius;\r\n    // O(n)\r\n    Prime(int n) {\r\n        min_factor.resize(n\
    \ + 1);\r\n        euler_phi.resize(n + 1);\r\n        mobius.resize(n + 1);\r\
    \n        for (int i = 2; i <= n; i++) {\r\n            if (min_factor[i] == 0)\
    \ {\r\n                min_factor[i] = i;\r\n                primes.push_back(i);\r\
    \n                euler_phi[i] = i - 1;\r\n                mobius[i] = -1;\r\n\
    \            }\r\n            for (int j = 0; j < primes.size() && primes[j] <=\
    \ min_factor[i] && i * primes[j] <= n; j++) {\r\n                min_factor[i\
    \ * primes[j]] = primes[j];\r\n                if (min_factor[i] == primes[j])\
    \ {\r\n                    euler_phi[i * primes[j]] = euler_phi[i] * primes[j];\r\
    \n                    mobius[i * primes[j]] = 0;\r\n                } else {\r\
    \n                    euler_phi[i * primes[j]] = euler_phi[i] * (primes[j] - 1);\r\
    \n                    mobius[i * primes[j]] = -mobius[i];\r\n                }\r\
    \n            }\r\n        }\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime.hpp
layout: document
redirect_from:
- /library/src/math/prime.hpp
- /library/src/math/prime.hpp.html
title: "\u7D20\u6570\u7B5B"
---
# 素数筛

## 概要
### `Prime`
`Prime` 是一个用于求素数的类，它的构造函数接受一个 `int` 类型的参数 `n`，表示求出小于等于 `n` 的所有素数。它有 4 个成员变量：
- `vector<int>primes`：存储所有素数的 `vector`。
- `vector<int>min_factor`：`min_factor[i]` 表示 `i` 的最小质因子。
- `vector<int> euler_phi`：`euler_phi[i]` 表示 `i` 的欧拉函数值。
- `vector<int>mobius`：`mobius[i]` 表示 `i` 的莫比乌斯函数值。



## 常见问题

## 题集
