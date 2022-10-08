---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"copypaste/debug.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\ntemplate <typename A, typename B>\r\nstring to_string(pair<A, B> p);\r\
    \n\r\ntemplate <typename A, typename B, typename C>\r\nstring to_string(tuple<A,\
    \ B, C> p);\r\n\r\ntemplate <typename A, typename B, typename C, typename D>\r\
    \nstring to_string(tuple<A, B, C, D> p);\r\n\r\nstring to_string(const string&\
    \ s) {\r\n    return '\"' + s + '\"';\r\n}\r\n\r\nstring to_string(const char*\
    \ s) {\r\n    return to_string((string)s);\r\n}\r\n\r\nstring to_string(bool b)\
    \ {\r\n    return (b ? \"true\" : \"false\");\r\n}\r\n\r\nstring to_string(vector<bool>\
    \ v) {\r\n    bool first = true;\r\n    string res = \"{\";\r\n    for (int i\
    \ = 0; i < static_cast<int>(v.size()); i++) {\r\n        if (!first) {\r\n   \
    \         res += \", \";\r\n        }\r\n        first = false;\r\n        res\
    \ += to_string(v[i]);\r\n    }\r\n    res += \"}\";\r\n    return res;\r\n}\r\n\
    \r\ntemplate <size_t N>\r\nstring to_string(bitset<N> v) {\r\n    string res =\
    \ \"\";\r\n    for (size_t i = 0; i < N; i++) {\r\n        res += static_cast<char>('0'\
    \ + v[i]);\r\n    }\r\n    return res;\r\n}\r\n\r\ntemplate <typename A>\r\nstring\
    \ to_string(A v) {\r\n    bool first = true;\r\n    string res = \"{\";\r\n  \
    \  for (const auto& x : v) {\r\n        if (!first) {\r\n            res += \"\
    , \";\r\n        }\r\n        first = false;\r\n        res += to_string(x);\r\
    \n    }\r\n    res += \"}\";\r\n    return res;\r\n}\r\n\r\ntemplate <typename\
    \ A, typename B>\r\nstring to_string(pair<A, B> p) {\r\n    return \"(\" + to_string(p.first)\
    \ + \", \" + to_string(p.second) + \")\";\r\n}\r\n\r\ntemplate <typename A, typename\
    \ B, typename C>\r\nstring to_string(tuple<A, B, C> p) {\r\n    return \"(\" +\
    \ to_string(get<0>(p)) + \", \" + to_string(get<1>(p)) + \", \" + to_string(get<2>(p))\
    \ + \")\";\r\n}\r\n\r\ntemplate <typename A, typename B, typename C, typename\
    \ D>\r\nstring to_string(tuple<A, B, C, D> p) {\r\n    return \"(\" + to_string(get<0>(p))\
    \ + \", \" + to_string(get<1>(p)) + \", \" + to_string(get<2>(p)) + \", \" + to_string(get<3>(p))\
    \ + \")\";\r\n}\r\n\r\nvoid debug_out() {\r\n    cerr << endl;\r\n}\r\n\r\ntemplate\
    \ <typename Head, typename... Tail>\r\nvoid debug_out(Head H, Tail... T) {\r\n\
    \    cerr << \" \" << to_string(H);\r\n    debug_out(T...);\r\n}\r\n\r\n#define\
    \ debug(...) cerr << \"[\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\ntemplate <typename A,\
    \ typename B>\r\nstring to_string(pair<A, B> p);\r\n\r\ntemplate <typename A,\
    \ typename B, typename C>\r\nstring to_string(tuple<A, B, C> p);\r\n\r\ntemplate\
    \ <typename A, typename B, typename C, typename D>\r\nstring to_string(tuple<A,\
    \ B, C, D> p);\r\n\r\nstring to_string(const string& s) {\r\n    return '\"' +\
    \ s + '\"';\r\n}\r\n\r\nstring to_string(const char* s) {\r\n    return to_string((string)s);\r\
    \n}\r\n\r\nstring to_string(bool b) {\r\n    return (b ? \"true\" : \"false\"\
    );\r\n}\r\n\r\nstring to_string(vector<bool> v) {\r\n    bool first = true;\r\n\
    \    string res = \"{\";\r\n    for (int i = 0; i < static_cast<int>(v.size());\
    \ i++) {\r\n        if (!first) {\r\n            res += \", \";\r\n        }\r\
    \n        first = false;\r\n        res += to_string(v[i]);\r\n    }\r\n    res\
    \ += \"}\";\r\n    return res;\r\n}\r\n\r\ntemplate <size_t N>\r\nstring to_string(bitset<N>\
    \ v) {\r\n    string res = \"\";\r\n    for (size_t i = 0; i < N; i++) {\r\n \
    \       res += static_cast<char>('0' + v[i]);\r\n    }\r\n    return res;\r\n\
    }\r\n\r\ntemplate <typename A>\r\nstring to_string(A v) {\r\n    bool first =\
    \ true;\r\n    string res = \"{\";\r\n    for (const auto& x : v) {\r\n      \
    \  if (!first) {\r\n            res += \", \";\r\n        }\r\n        first =\
    \ false;\r\n        res += to_string(x);\r\n    }\r\n    res += \"}\";\r\n   \
    \ return res;\r\n}\r\n\r\ntemplate <typename A, typename B>\r\nstring to_string(pair<A,\
    \ B> p) {\r\n    return \"(\" + to_string(p.first) + \", \" + to_string(p.second)\
    \ + \")\";\r\n}\r\n\r\ntemplate <typename A, typename B, typename C>\r\nstring\
    \ to_string(tuple<A, B, C> p) {\r\n    return \"(\" + to_string(get<0>(p)) + \"\
    , \" + to_string(get<1>(p)) + \", \" + to_string(get<2>(p)) + \")\";\r\n}\r\n\r\
    \ntemplate <typename A, typename B, typename C, typename D>\r\nstring to_string(tuple<A,\
    \ B, C, D> p) {\r\n    return \"(\" + to_string(get<0>(p)) + \", \" + to_string(get<1>(p))\
    \ + \", \" + to_string(get<2>(p)) + \", \" + to_string(get<3>(p)) + \")\";\r\n\
    }\r\n\r\nvoid debug_out() {\r\n    cerr << endl;\r\n}\r\n\r\ntemplate <typename\
    \ Head, typename... Tail>\r\nvoid debug_out(Head H, Tail... T) {\r\n    cerr <<\
    \ \" \" << to_string(H);\r\n    debug_out(T...);\r\n}\r\n\r\n#define debug(...)\
    \ cerr << \"[\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)"
  dependsOn: []
  isVerificationFile: false
  path: copypaste/debug.h
  requiredBy: []
  timestamp: '2022-10-08 23:04:20+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: copypaste/debug.h
layout: document
redirect_from:
- /library/copypaste/debug.h
- /library/copypaste/debug.h.html
title: copypaste/debug.h
---
