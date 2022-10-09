---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/digit_dp.md
    document_title: "\u6570\u4F4Ddp"
    links:
    - https://leetcode.cn/problems/numbers-with-repeated-digits/submissions/
  bundledCode: "#line 1 \"src/dp/digit_dp.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/*\r\n@brief \u6570\u4F4Ddp\r\n@docs docs/digit_dp.md\r\
    \ntodo: \u5F85\u6574\u7406\r\n*/\r\n// https://leetcode.cn/problems/numbers-with-repeated-digits/submissions/\r\
    \nint dp[11][1025][2];\r\nclass Solution {\r\n   public:\r\n    int n;\r\n   \
    \ vector<int> v;\r\n    int dfs(int d, int status, bool flag, bool limit, bool\
    \ lead) {\r\n        if (d == n) {\r\n            return flag;\r\n        }\r\n\
    \        if (!limit && dp[d][status][flag] != -1) return dp[d][status][flag];\r\
    \n        int res = 0;\r\n        int LIMIT = limit ? v[d] : 9;\r\n\r\n      \
    \  for (int i = 0; i <= LIMIT; i++) {\r\n            if (lead && i == 0) {\r\n\
    \                res += dfs(d + 1, status, false, false, true);\r\n          \
    \  } else {\r\n                res += dfs(d + 1, status | (1 << i), flag || ((status\
    \ >> i) & 1), limit && (i == LIMIT), false);\r\n            }\r\n        }\r\n\
    \        if (!limit) dp[d][status][flag] = res;\r\n        // debug(d, status,\
    \ flag, limit, lead, res);\r\n        return res;\r\n    }\r\n\r\n    int work(int\
    \ val) {\r\n        v.clear();\r\n        while (val) {\r\n            v.push_back(val\
    \ % 10);\r\n            val /= 10;\r\n        }\r\n        reverse(v.begin(),\
    \ v.end());\r\n\r\n        n = v.size();\r\n        return dfs(0, 0, false, true,\
    \ true);\r\n    }\r\n    int numDupDigitsAtMostN(int n) {\r\n        memset(dp,\
    \ -1, sizeof(dp));\r\n        return work(n);\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief \u6570\
    \u4F4Ddp\r\n@docs docs/digit_dp.md\r\ntodo: \u5F85\u6574\u7406\r\n*/\r\n// https://leetcode.cn/problems/numbers-with-repeated-digits/submissions/\r\
    \nint dp[11][1025][2];\r\nclass Solution {\r\n   public:\r\n    int n;\r\n   \
    \ vector<int> v;\r\n    int dfs(int d, int status, bool flag, bool limit, bool\
    \ lead) {\r\n        if (d == n) {\r\n            return flag;\r\n        }\r\n\
    \        if (!limit && dp[d][status][flag] != -1) return dp[d][status][flag];\r\
    \n        int res = 0;\r\n        int LIMIT = limit ? v[d] : 9;\r\n\r\n      \
    \  for (int i = 0; i <= LIMIT; i++) {\r\n            if (lead && i == 0) {\r\n\
    \                res += dfs(d + 1, status, false, false, true);\r\n          \
    \  } else {\r\n                res += dfs(d + 1, status | (1 << i), flag || ((status\
    \ >> i) & 1), limit && (i == LIMIT), false);\r\n            }\r\n        }\r\n\
    \        if (!limit) dp[d][status][flag] = res;\r\n        // debug(d, status,\
    \ flag, limit, lead, res);\r\n        return res;\r\n    }\r\n\r\n    int work(int\
    \ val) {\r\n        v.clear();\r\n        while (val) {\r\n            v.push_back(val\
    \ % 10);\r\n            val /= 10;\r\n        }\r\n        reverse(v.begin(),\
    \ v.end());\r\n\r\n        n = v.size();\r\n        return dfs(0, 0, false, true,\
    \ true);\r\n    }\r\n    int numDupDigitsAtMostN(int n) {\r\n        memset(dp,\
    \ -1, sizeof(dp));\r\n        return work(n);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/digit_dp.hpp
  requiredBy: []
  timestamp: '2022-10-09 21:28:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/digit_dp.hpp
layout: document
redirect_from:
- /library/src/dp/digit_dp.hpp
- /library/src/dp/digit_dp.hpp.html
title: "\u6570\u4F4Ddp"
---
