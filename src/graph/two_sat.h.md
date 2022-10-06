---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/two_sat.md
    document_title: two-sat
    links: []
  bundledCode: "#line 1 \"src/graph/two_sat.h\"\n#include <bits/stdc++.h>\r\n/*\r\n\
    @brief two-sat\r\n@docs docs/two_sat.md\r\n*/\r\nstruct TwoSat {\r\n    // [0,\
    \ 2 * n]\r\n    int n;\r\n    std::vector<std::vector<int>> e;\r\n    std::vector<bool>\
    \ ans;\r\n    TwoSat(int n) : n(n), e(2 * n), ans(n) {}\r\n    void addClause(int\
    \ u, bool f, int v, bool g) {\r\n        // (u, f) \u548C (v, g) \u6709\u77DB\u76FE\
    \r\n        e[2 * u + !f].push_back(2 * v + g);\r\n        e[2 * v + !g].push_back(2\
    \ * u + f);\r\n    }\r\n    bool satisfiable() {\r\n        std::vector<int> id(2\
    \ * n, -1), dfn(2 * n, -1), low(2 * n, -1);\r\n        std::vector<int> stk;\r\
    \n        int now = 0, cnt = 0;\r\n        std::function<void(int)> tarjan = [&](int\
    \ u) {\r\n            stk.push_back(u);\r\n            dfn[u] = low[u] = now++;\r\
    \n            for (auto v : e[u]) {\r\n                if (dfn[v] == -1) {\r\n\
    \                    tarjan(v);\r\n                    low[u] = std::min(low[u],\
    \ low[v]);\r\n                } else if (id[v] == -1) {\r\n                  \
    \  low[u] = std::min(low[u], dfn[v]);\r\n                }\r\n            }\r\n\
    \            if (dfn[u] == low[u]) {\r\n                int v;\r\n           \
    \     do {\r\n                    v = stk.back();\r\n                    stk.pop_back();\r\
    \n                    id[v] = cnt;\r\n                } while (v != u);\r\n  \
    \              ++cnt;\r\n            }\r\n        };\r\n        for (int i = 0;\
    \ i < 2 * n; ++i)\r\n            if (dfn[i] == -1) tarjan(i);\r\n\r\n        /*\r\
    \n            \u65B9\u6848\u53EF\u4EE5\u901A\u8FC7\u53D8\u91CF\u5728\u56FE\u4E2D\
    \u7684\u62D3\u6251\u5E8F\u786E\u5B9A\u8BE5\u53D8\u91CF\u7684\u503C\uFF0C\u5982\
    \u679C\u53D8\u91CF !x \u7684\u62D3\u6251\u5E8F\u5728 x \u4E4B\u540E\uFF0C\u90A3\
    \u4E48 x \u4E3A\u771F.\r\n            \u5E94\u7528\u5230 tarjan \u5F53\u4E2D\uFF0C\
    \u5373 x \u7684 SCC \u7F16\u53F7\u5728 !x \u4E4B\u524D\uFF0C\u53D6 x \u4E3A\u771F\
    \u3002\u56E0\u4E3A tarjan \u7528\u5230\u4E86\u6808\uFF0C\u6240\u4EE5 tarjan \u6C42\
    \u51FA\u7684 SCC \u7F16\u53F7\u76F8\u5F53\u4E8E\u53CD\u62D3\u6251\u5E8F\u3002\r\
    \n        */\r\n\r\n        for (int i = 0; i < n; ++i) {\r\n            if (id[2\
    \ * i] == id[2 * i + 1]) return false;\r\n            ans[i] = id[2 * i] < id[2\
    \ * i + 1];\r\n        }\r\n        return true;\r\n    }\r\n    std::vector<bool>\
    \ answer() { return ans; }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\n/*\r\n@brief two-sat\r\n@docs docs/two_sat.md\r\
    \n*/\r\nstruct TwoSat {\r\n    // [0, 2 * n]\r\n    int n;\r\n    std::vector<std::vector<int>>\
    \ e;\r\n    std::vector<bool> ans;\r\n    TwoSat(int n) : n(n), e(2 * n), ans(n)\
    \ {}\r\n    void addClause(int u, bool f, int v, bool g) {\r\n        // (u, f)\
    \ \u548C (v, g) \u6709\u77DB\u76FE\r\n        e[2 * u + !f].push_back(2 * v +\
    \ g);\r\n        e[2 * v + !g].push_back(2 * u + f);\r\n    }\r\n    bool satisfiable()\
    \ {\r\n        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);\r\
    \n        std::vector<int> stk;\r\n        int now = 0, cnt = 0;\r\n        std::function<void(int)>\
    \ tarjan = [&](int u) {\r\n            stk.push_back(u);\r\n            dfn[u]\
    \ = low[u] = now++;\r\n            for (auto v : e[u]) {\r\n                if\
    \ (dfn[v] == -1) {\r\n                    tarjan(v);\r\n                    low[u]\
    \ = std::min(low[u], low[v]);\r\n                } else if (id[v] == -1) {\r\n\
    \                    low[u] = std::min(low[u], dfn[v]);\r\n                }\r\
    \n            }\r\n            if (dfn[u] == low[u]) {\r\n                int\
    \ v;\r\n                do {\r\n                    v = stk.back();\r\n      \
    \              stk.pop_back();\r\n                    id[v] = cnt;\r\n       \
    \         } while (v != u);\r\n                ++cnt;\r\n            }\r\n   \
    \     };\r\n        for (int i = 0; i < 2 * n; ++i)\r\n            if (dfn[i]\
    \ == -1) tarjan(i);\r\n\r\n        /*\r\n            \u65B9\u6848\u53EF\u4EE5\u901A\
    \u8FC7\u53D8\u91CF\u5728\u56FE\u4E2D\u7684\u62D3\u6251\u5E8F\u786E\u5B9A\u8BE5\
    \u53D8\u91CF\u7684\u503C\uFF0C\u5982\u679C\u53D8\u91CF !x \u7684\u62D3\u6251\u5E8F\
    \u5728 x \u4E4B\u540E\uFF0C\u90A3\u4E48 x \u4E3A\u771F.\r\n            \u5E94\u7528\
    \u5230 tarjan \u5F53\u4E2D\uFF0C\u5373 x \u7684 SCC \u7F16\u53F7\u5728 !x \u4E4B\
    \u524D\uFF0C\u53D6 x \u4E3A\u771F\u3002\u56E0\u4E3A tarjan \u7528\u5230\u4E86\u6808\
    \uFF0C\u6240\u4EE5 tarjan \u6C42\u51FA\u7684 SCC \u7F16\u53F7\u76F8\u5F53\u4E8E\
    \u53CD\u62D3\u6251\u5E8F\u3002\r\n        */\r\n\r\n        for (int i = 0; i\
    \ < n; ++i) {\r\n            if (id[2 * i] == id[2 * i + 1]) return false;\r\n\
    \            ans[i] = id[2 * i] < id[2 * i + 1];\r\n        }\r\n        return\
    \ true;\r\n    }\r\n    std::vector<bool> answer() { return ans; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/two_sat.h
  requiredBy: []
  timestamp: '2022-10-06 15:28:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/two_sat.h
layout: document
redirect_from:
- /library/src/graph/two_sat.h
- /library/src/graph/two_sat.h.html
title: two-sat
---
