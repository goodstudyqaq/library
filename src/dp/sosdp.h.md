---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/sos_dp.md
    document_title: SOSdp
    links:
    - https://codeforces.com/blog/entry/45223
  bundledCode: "#line 1 \"src/dp/sosdp.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n/*\r\n@brief SOSdp\r\n@docs docs/sos_dp.md\r\n*/\r\nnamespace SOSDP\
    \ {\r\n// https://codeforces.com/blog/entry/45223\r\n/*\r\n    F[mask] = \\sum_{i\
    \ \\in mask} A[i]\r\n    Time: O(N2^N)\r\n*/\r\n\r\nvoid iterative_version(int\
    \ N, vector<int>& A) {\r\n    // iterative version\r\n    vector<vector<int>>\
    \ dp(1 << N, vector<int>(N + 1));\r\n    vector<int> F(1 << N);\r\n    for (int\
    \ mask = 0; mask < (1 << N); ++mask) {\r\n        dp[mask][0] = A[mask];  // handle\
    \ base case separately (leaf states)\r\n        for (int i = 0; i < N; ++i) {\r\
    \n            if (mask & (1 << i)) {\r\n                dp[mask][i + 1] = dp[mask][i]\
    \ + dp[mask ^ (1 << i)][i];\r\n            } else {\r\n                dp[mask][i\
    \ + 1] = dp[mask][i];\r\n            }\r\n        }\r\n        F[mask] = dp[mask][N];\r\
    \n    }\r\n}\r\n\r\nvoid easy_version(int N, vector<int>& A) {\r\n    vector<int>\
    \ F(1 << N);\r\n    // memory optimized, super easy to code.\r\n    for (int i\
    \ = 0; i < (1 << N); ++i) {\r\n        F[i] = A[i];\r\n    }\r\n    for (int i\
    \ = 0; i < N; ++i) {\r\n        for (int mask = 0; mask < (1 << N); ++mask) {\r\
    \n            if (mask & (1 << i)) {\r\n                F[mask] += F[mask ^ (1\
    \ << i)];\r\n            }\r\n        }\r\n    }\r\n}\r\n\r\n}  // namespace SOSDP\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/*\r\n@brief SOSdp\r\n\
    @docs docs/sos_dp.md\r\n*/\r\nnamespace SOSDP {\r\n// https://codeforces.com/blog/entry/45223\r\
    \n/*\r\n    F[mask] = \\sum_{i \\in mask} A[i]\r\n    Time: O(N2^N)\r\n*/\r\n\r\
    \nvoid iterative_version(int N, vector<int>& A) {\r\n    // iterative version\r\
    \n    vector<vector<int>> dp(1 << N, vector<int>(N + 1));\r\n    vector<int> F(1\
    \ << N);\r\n    for (int mask = 0; mask < (1 << N); ++mask) {\r\n        dp[mask][0]\
    \ = A[mask];  // handle base case separately (leaf states)\r\n        for (int\
    \ i = 0; i < N; ++i) {\r\n            if (mask & (1 << i)) {\r\n             \
    \   dp[mask][i + 1] = dp[mask][i] + dp[mask ^ (1 << i)][i];\r\n            } else\
    \ {\r\n                dp[mask][i + 1] = dp[mask][i];\r\n            }\r\n   \
    \     }\r\n        F[mask] = dp[mask][N];\r\n    }\r\n}\r\n\r\nvoid easy_version(int\
    \ N, vector<int>& A) {\r\n    vector<int> F(1 << N);\r\n    // memory optimized,\
    \ super easy to code.\r\n    for (int i = 0; i < (1 << N); ++i) {\r\n        F[i]\
    \ = A[i];\r\n    }\r\n    for (int i = 0; i < N; ++i) {\r\n        for (int mask\
    \ = 0; mask < (1 << N); ++mask) {\r\n            if (mask & (1 << i)) {\r\n  \
    \              F[mask] += F[mask ^ (1 << i)];\r\n            }\r\n        }\r\n\
    \    }\r\n}\r\n\r\n}  // namespace SOSDP"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/sosdp.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/sosdp.h
layout: document
redirect_from:
- /library/src/dp/sosdp.h
- /library/src/dp/sosdp.h.html
title: SOSdp
---
