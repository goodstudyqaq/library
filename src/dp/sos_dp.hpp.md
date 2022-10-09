---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/sos_dp.md
    document_title: SOSdp
    links:
    - https://codeforces.com/blog/entry/45223
  bundledCode: "#line 1 \"src/dp/sos_dp.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n/*\r\n@brief SOSdp\r\n@docs docs/sos_dp.md\r\n*/\r\ntemplate <typename\
    \ T>\r\nstruct SOSDP {\r\n    // https://codeforces.com/blog/entry/45223\r\n \
    \   /*\r\n        F[mask] = \\sum_{i \\in mask} A[i]\r\n        Time: O(N2^N)\r\
    \n    */\r\n    vector<vector<T>> iterative_version(vector<T>& A) {\r\n      \
    \  int N = A.size();\r\n        vector<vector<T>> dp(1 << N, vector<T>(N + 1));\r\
    \n        vector<T> F(1 << N);\r\n        for (int mask = 0; mask < (1 << N);\
    \ ++mask) {\r\n            dp[mask][0] = A[mask];  // handle base case separately\
    \ (leaf states)\r\n            for (int i = 0; i < N; ++i) {\r\n             \
    \   if (mask & (1 << i)) {\r\n                    dp[mask][i + 1] = dp[mask][i]\
    \ + dp[mask ^ (1 << i)][i];\r\n                } else {\r\n                  \
    \  dp[mask][i + 1] = dp[mask][i];\r\n                }\r\n            }\r\n  \
    \          F[mask] = dp[mask][N];\r\n        }\r\n        return dp;\r\n    }\r\
    \n\r\n    vector<vector<T>> easy_version(vector<T>& A) {\r\n        vector<T>\
    \ F(1 << N);\r\n        // memory optimized, super easy to code.\r\n        for\
    \ (int i = 0; i < (1 << N); ++i) {\r\n            F[i] = A[i];\r\n        }\r\n\
    \        for (int i = 0; i < N; ++i) {\r\n            for (int mask = 0; mask\
    \ < (1 << N); ++mask) {\r\n                if (mask & (1 << i)) {\r\n        \
    \            F[mask] += F[mask ^ (1 << i)];\r\n                }\r\n         \
    \   }\r\n        }\r\n        return F;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief SOSdp\r\n\
    @docs docs/sos_dp.md\r\n*/\r\ntemplate <typename T>\r\nstruct SOSDP {\r\n    //\
    \ https://codeforces.com/blog/entry/45223\r\n    /*\r\n        F[mask] = \\sum_{i\
    \ \\in mask} A[i]\r\n        Time: O(N2^N)\r\n    */\r\n    vector<vector<T>>\
    \ iterative_version(vector<T>& A) {\r\n        int N = A.size();\r\n        vector<vector<T>>\
    \ dp(1 << N, vector<T>(N + 1));\r\n        vector<T> F(1 << N);\r\n        for\
    \ (int mask = 0; mask < (1 << N); ++mask) {\r\n            dp[mask][0] = A[mask];\
    \  // handle base case separately (leaf states)\r\n            for (int i = 0;\
    \ i < N; ++i) {\r\n                if (mask & (1 << i)) {\r\n                \
    \    dp[mask][i + 1] = dp[mask][i] + dp[mask ^ (1 << i)][i];\r\n             \
    \   } else {\r\n                    dp[mask][i + 1] = dp[mask][i];\r\n       \
    \         }\r\n            }\r\n            F[mask] = dp[mask][N];\r\n       \
    \ }\r\n        return dp;\r\n    }\r\n\r\n    vector<vector<T>> easy_version(vector<T>&\
    \ A) {\r\n        vector<T> F(1 << N);\r\n        // memory optimized, super easy\
    \ to code.\r\n        for (int i = 0; i < (1 << N); ++i) {\r\n            F[i]\
    \ = A[i];\r\n        }\r\n        for (int i = 0; i < N; ++i) {\r\n          \
    \  for (int mask = 0; mask < (1 << N); ++mask) {\r\n                if (mask &\
    \ (1 << i)) {\r\n                    F[mask] += F[mask ^ (1 << i)];\r\n      \
    \          }\r\n            }\r\n        }\r\n        return F;\r\n    }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/sos_dp.hpp
  requiredBy: []
  timestamp: '2022-10-09 21:28:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/sos_dp.hpp
layout: document
redirect_from:
- /library/src/dp/sos_dp.hpp
- /library/src/dp/sos_dp.hpp.html
title: SOSdp
---
# SPFA(最小费用最大流)

## 概要


## 常见问题

## 题集
