---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/hash_pair.md
    document_title: Hash Pair
    links:
    - http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html
  bundledCode: "#line 1 \"src/utils/hash_pair.hpp\"\n#include <functional>\r\n/*\r\
    \n@brief Hash Pair\r\n@docs docs/hash_pair.md\r\n*/\r\n// from boost (functional/hash):\r\
    \n// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template\r\
    \ntemplate <typename T>\r\ninline void hash_combine(std::size_t& seed, const T&\
    \ val) {\r\n    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed\
    \ >> 2);\r\n}\r\n// auxiliary generic functions to create a hash value using a\
    \ seed\r\ntemplate <typename T>\r\ninline void hash_val(std::size_t& seed, const\
    \ T& val) {\r\n    hash_combine(seed, val);\r\n}\r\ntemplate <typename T, typename...\
    \ Types>\r\ninline void hash_val(std::size_t& seed, const T& val, const Types&...\
    \ args) {\r\n    hash_combine(seed, val);\r\n    hash_val(seed, args...);\r\n\
    }\r\n\r\ntemplate <typename... Types>\r\ninline std::size_t hash_val(const Types&...\
    \ args) {\r\n    std::size_t seed = 0;\r\n    hash_val(seed, args...);\r\n   \
    \ return seed;\r\n}\r\n\r\nstruct pair_hash {\r\n    template <class T1, class\
    \ T2>\r\n    std::size_t operator()(const std::pair<T1, T2>& p) const {\r\n  \
    \      return hash_val(p.first, p.second);\r\n    }\r\n};\r\n\r\n/*\r\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\nusing ll = long long;\r\n\r\nint\
    \ main() {\r\n    unordered_map< pair< ll, ll >, ll, pair_hash > slopeCount;\r\
    \n    unordered_set< pair< ll, ll >, pair_hash > seen;\r\n    seen.insert({ 1,\
    \ 2 });\r\n    seen.insert({ 2, 3 });\r\n\r\n    for (auto it : seen) {\r\n  \
    \      cout << it.first << ' ' << it.second << endl;\r\n    }\r\n\r\n    return\
    \ 0;\r\n}\r\n*/\n"
  code: "#include <functional>\r\n/*\r\n@brief Hash Pair\r\n@docs docs/hash_pair.md\r\
    \n*/\r\n// from boost (functional/hash):\r\n// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html\
    \ template\r\ntemplate <typename T>\r\ninline void hash_combine(std::size_t& seed,\
    \ const T& val) {\r\n    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6)\
    \ + (seed >> 2);\r\n}\r\n// auxiliary generic functions to create a hash value\
    \ using a seed\r\ntemplate <typename T>\r\ninline void hash_val(std::size_t& seed,\
    \ const T& val) {\r\n    hash_combine(seed, val);\r\n}\r\ntemplate <typename T,\
    \ typename... Types>\r\ninline void hash_val(std::size_t& seed, const T& val,\
    \ const Types&... args) {\r\n    hash_combine(seed, val);\r\n    hash_val(seed,\
    \ args...);\r\n}\r\n\r\ntemplate <typename... Types>\r\ninline std::size_t hash_val(const\
    \ Types&... args) {\r\n    std::size_t seed = 0;\r\n    hash_val(seed, args...);\r\
    \n    return seed;\r\n}\r\n\r\nstruct pair_hash {\r\n    template <class T1, class\
    \ T2>\r\n    std::size_t operator()(const std::pair<T1, T2>& p) const {\r\n  \
    \      return hash_val(p.first, p.second);\r\n    }\r\n};\r\n\r\n/*\r\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\nusing ll = long long;\r\n\r\nint\
    \ main() {\r\n    unordered_map< pair< ll, ll >, ll, pair_hash > slopeCount;\r\
    \n    unordered_set< pair< ll, ll >, pair_hash > seen;\r\n    seen.insert({ 1,\
    \ 2 });\r\n    seen.insert({ 2, 3 });\r\n\r\n    for (auto it : seen) {\r\n  \
    \      cout << it.first << ' ' << it.second << endl;\r\n    }\r\n\r\n    return\
    \ 0;\r\n}\r\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/utils/hash_pair.hpp
  requiredBy: []
  timestamp: '2022-10-07 12:16:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utils/hash_pair.hpp
layout: document
redirect_from:
- /library/src/utils/hash_pair.hpp
- /library/src/utils/hash_pair.hpp.html
title: Hash Pair
---
# Hash pair

## 概要
主要是用于`std::unordered_map`的`hash`函数，用于计算`std::pair`的`hash`值。
```cpp
int main() {
    std::unordered_map<std::pair<int, int>, pair_hash> mp;
    mp[std::make_pair(1, 2)] = 3;
    std::cout << mp[std::make_pair(1, 2)] << std::endl;

    std::unordered_set<std::pair<int, int>, pair_hash> st;
    st.insert(std::make_pair(1, 2));
    std::cout << st.count(std::make_pair(1, 2)) << std::endl;

}
```


## 常见问题

## 题集