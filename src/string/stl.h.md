---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string_stl.md
    document_title: STL
    links: []
  bundledCode: "#line 1 \"src/string/stl.h\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n/*\r\n@brief STL\r\n@docs docs/string_stl.md\r\n*/\r\n\r\nnamespace\
    \ STL {\r\n/*\r\n\u8BB0\u5F55\u4E00\u4E9B\u5E38\u7528\u7684 STL \u51FD\u6570\r\
    \n*/\r\nvoid StringSTL() {\r\n    string s = \"123\";\r\n    int num = stoi(s);\
    \  // string to int \u8FD4\u56DE\u5B57\u7B26\u4E32\u524D\u7F00\u6574\u6570\uFF0C\
    \u53EF\u4EE5\u6709\u524D\u5BFC\u96F6\uFF0C\u524D\u7F00\u5FC5\u987B\u662F\u6570\
    \u5B57(\u7B2C\u4E00\u4E2A\u5B57\u7B26\u53EF\u4EE5\u662F \u2018-\u2019)\r\n   \
    \ s = \"247+38\";\r\n    int add = s.find('+', 0);  // \u4ECE pos \u5F00\u59CB\
    \u67E5\u627E\uFF0C\u8FD4\u56DE\u7B2C\u4E00\u4E2A\u5339\u914D\u7684\u4E0B\u6807\
    \r\n\r\n    double num = stod(s);  // string to double\r\n}\r\n\r\nvector<string>\
    \ split(string &s, string delimiter) {\r\n    size_t pos_start = 0, pos_end, delim_len\
    \ = delimiter.length();\r\n    string token;\r\n    vector<string> res;\r\n\r\n\
    \    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {\r\n  \
    \      token = s.substr(pos_start, pos_end - pos_start);\r\n        pos_start\
    \ = pos_end + delim_len;\r\n        res.push_back(token);\r\n    }\r\n\r\n   \
    \ res.push_back(s.substr(pos_start));\r\n    return res;\r\n}\r\n\r\nbool isFloat(string\
    \ &myString) {\r\n    std::istringstream iss(myString);\r\n    float f;\r\n  \
    \  iss >> noskipws >> f;  // noskipws considers leading whitespace invalid\r\n\
    \    // Check the entire string was consumed and if either failbit or badbit is\
    \ set\r\n    return iss.eof() && !iss.fail();\r\n}\r\n\r\n/*\r\n%02d 2\u4F4D\u6570\
    \u5B57\uFF0C\u4E0D\u6EE1\u8865 0\r\n*/\r\ntemplate <typename... Args>\r\nstd::string\
    \ string_format(const std::string &format, Args... args) {\r\n    int size_s =\
    \ std::snprintf(nullptr, 0, format.c_str(), args...) + 1;  // Extra space for\
    \ '\\0'\r\n    if (size_s <= 0) {\r\n        throw std::runtime_error(\"Error\
    \ during formatting.\");\r\n    }\r\n    auto size = static_cast<size_t>(size_s);\r\
    \n    std::unique_ptr<char[]> buf(new char[size]);\r\n    std::snprintf(buf.get(),\
    \ size, format.c_str(), args...);\r\n    return std::string(buf.get(), buf.get()\
    \ + size - 1);  // We don't want the '\\0' inside\r\n}\r\n\r\n}  // namespace\
    \ STL\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief STL\r\
    \n@docs docs/string_stl.md\r\n*/\r\n\r\nnamespace STL {\r\n/*\r\n\u8BB0\u5F55\u4E00\
    \u4E9B\u5E38\u7528\u7684 STL \u51FD\u6570\r\n*/\r\nvoid StringSTL() {\r\n    string\
    \ s = \"123\";\r\n    int num = stoi(s);  // string to int \u8FD4\u56DE\u5B57\u7B26\
    \u4E32\u524D\u7F00\u6574\u6570\uFF0C\u53EF\u4EE5\u6709\u524D\u5BFC\u96F6\uFF0C\
    \u524D\u7F00\u5FC5\u987B\u662F\u6570\u5B57(\u7B2C\u4E00\u4E2A\u5B57\u7B26\u53EF\
    \u4EE5\u662F \u2018-\u2019)\r\n    s = \"247+38\";\r\n    int add = s.find('+',\
    \ 0);  // \u4ECE pos \u5F00\u59CB\u67E5\u627E\uFF0C\u8FD4\u56DE\u7B2C\u4E00\u4E2A\
    \u5339\u914D\u7684\u4E0B\u6807\r\n\r\n    double num = stod(s);  // string to\
    \ double\r\n}\r\n\r\nvector<string> split(string &s, string delimiter) {\r\n \
    \   size_t pos_start = 0, pos_end, delim_len = delimiter.length();\r\n    string\
    \ token;\r\n    vector<string> res;\r\n\r\n    while ((pos_end = s.find(delimiter,\
    \ pos_start)) != string::npos) {\r\n        token = s.substr(pos_start, pos_end\
    \ - pos_start);\r\n        pos_start = pos_end + delim_len;\r\n        res.push_back(token);\r\
    \n    }\r\n\r\n    res.push_back(s.substr(pos_start));\r\n    return res;\r\n\
    }\r\n\r\nbool isFloat(string &myString) {\r\n    std::istringstream iss(myString);\r\
    \n    float f;\r\n    iss >> noskipws >> f;  // noskipws considers leading whitespace\
    \ invalid\r\n    // Check the entire string was consumed and if either failbit\
    \ or badbit is set\r\n    return iss.eof() && !iss.fail();\r\n}\r\n\r\n/*\r\n\
    %02d 2\u4F4D\u6570\u5B57\uFF0C\u4E0D\u6EE1\u8865 0\r\n*/\r\ntemplate <typename...\
    \ Args>\r\nstd::string string_format(const std::string &format, Args... args)\
    \ {\r\n    int size_s = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;\
    \  // Extra space for '\\0'\r\n    if (size_s <= 0) {\r\n        throw std::runtime_error(\"\
    Error during formatting.\");\r\n    }\r\n    auto size = static_cast<size_t>(size_s);\r\
    \n    std::unique_ptr<char[]> buf(new char[size]);\r\n    std::snprintf(buf.get(),\
    \ size, format.c_str(), args...);\r\n    return std::string(buf.get(), buf.get()\
    \ + size - 1);  // We don't want the '\\0' inside\r\n}\r\n\r\n}  // namespace\
    \ STL"
  dependsOn: []
  isVerificationFile: false
  path: src/string/stl.h
  requiredBy: []
  timestamp: '2022-10-06 23:48:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/stl.h
layout: document
redirect_from:
- /library/src/string/stl.h
- /library/src/string/stl.h.html
title: STL
---
# String's STL

## 概要
提供一些常用的字符串操作函数

- `vector<string> split(string &s, string delimiter)`: 将字符串 `s` 按照 `delimiter` 分割，返回分割后的字符串数组。
- `bool isFloat(string &s)`: 判断字符串 `s` 是否为浮点数。
- `std::string string_format(const std::string &format, Args... args)`: 格式化字符串，类似于 `printf` 函数。

## 常见问题

## 题集
h