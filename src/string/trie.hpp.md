---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/aho_corasick.hpp
    title: "AC \u81EA\u52A8\u673A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aho_corasick.test.cpp
    title: test/data_structure/aho_corasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/trie.md
    document_title: Trie
    links: []
  bundledCode: "#line 1 \"src/string/trie.hpp\"\n#include <bits/stdc++.h>\r\n\r\n\
    using namespace std;\r\n\r\n/*\r\n@brief Trie\r\n@docs docs/trie.md\r\n*/\r\n\r\
    \nstruct TrieNode {\r\n    vector<int> nxt;\r\n    TrieNode(int char_size) {\r\
    \n        nxt.resize(char_size, -1);\r\n    }\r\n    // \u4E00\u4E9B hook \u51FD\
    \u6570\uFF0C\u7528\u4E8E Trie \u7B97\u6CD5\u4EE5\u53CA ac \u81EA\u52A8\u673A,\
    \ \u53EF\u4EE5\u8986\u76D6\u8FD9\u4E9B\u51FD\u6570\u6765\u5B9E\u73B0\u4E00\u4E9B\
    \u529F\u80FD\r\n\r\n    /*\r\n     * \u5F53\u52A0\u5165\u5230\u5B57\u5178\u6811\
    \u540E\uFF0C\u5BF9\u6700\u7EC8\u7684\u8282\u70B9(\u5F53\u524D\u8282\u70B9)\u8FDB\
    \u884C\u4E00\u4E9B\u64CD\u4F5C\r\n     */\r\n    void update_when_finish_in_trie(){};\r\
    \n\r\n    /*\r\n     * \u5F53\u52A0\u5165\u5230\u5B57\u5178\u6811\u65F6\uFF0C\u6839\
    \u636E\u5F53\u524D\u8282\u70B9\u548C\u5B50\u8282\u70B9\u7684\u4FE1\u606F\uFF0C\
    \u5BF9\u5F53\u524D\u8282\u70B9\u8FDB\u884C\u4E00\u4E9B\u64CD\u4F5C\r\n     */\r\
    \n    void update_when_push_in_trie(TrieNode &child_node){};\r\n\r\n    /*\r\n\
    \     * \u5F53\u6784\u5EFA fail \u51FD\u6570\u65F6\uFF0C\u6839\u636E\u5F53\u524D\
    \u8282\u70B9\u548C fail \u8282\u70B9\u7684\u4FE1\u606F\uFF0C\u5BF9\u5F53\u524D\
    \u8282\u70B9\u8FDB\u884C\u4E00\u4E9B\u64CD\u4F5C\r\n     */\r\n    void update_when_build_fail(TrieNode\
    \ &fail_node){};\r\n};\r\n\r\ntemplate <typename T = TrieNode>\r\nstruct Trie\
    \ {\r\n   public:\r\n    vector<T> nodes;\r\n    int root;\r\n\r\n    int char_size;\r\
    \n    int margin;\r\n\r\n    Trie(int char_size, int margin) : root(0), char_size(char_size),\
    \ margin(margin) {\r\n        nodes.push_back(T(char_size));\r\n    }\r\n\r\n\
    \    void add(const string &s, int s_idx, int node_idx) {\r\n        /*\r\n  \
    \       * \u5C06\u5B57\u7B26\u4E32 s \u7684 s_idx \u4F4D\u7F6E\u5F00\u59CB\u7684\
    \u540E\u7F00\u52A0\u5165\u5230\u5B57\u5178\u6811\u4E2D. node_idx \u4E3A\u5F53\u524D\
    \u8282\u70B9\u7684\u4E0B\u6807\r\n         */\r\n        if (s_idx == s.size())\
    \ {\r\n            // \u5B8C\u6210\u52A0\u5165\r\n            nodes[node_idx].update_when_finish_in_trie();\r\
    \n        } else {\r\n            const int c = s[s_idx] - margin;\r\n       \
    \     if (nodes[node_idx].nxt[c] == -1) {\r\n                nodes[node_idx].nxt[c]\
    \ = nodes.size();\r\n                nodes.push_back(T(char_size));\r\n      \
    \      }\r\n            add(s, s_idx + 1, nodes[node_idx].nxt[c]);\r\n       \
    \     // \u6839\u636E\u5F53\u524D\u8282\u70B9\u7684\u5B50\u8282\u70B9\u66F4\u65B0\
    \u5F53\u524D\u8282\u70B9\r\n            nodes[node_idx].update_when_push_in_trie(nodes[nodes[node_idx].nxt[c]]);\r\
    \n        }\r\n    }\r\n\r\n    void add(const string &s) {\r\n        add(s,\
    \ 0, root);\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\n\r\nusing namespace std;\r\n\r\n/*\r\n@brief\
    \ Trie\r\n@docs docs/trie.md\r\n*/\r\n\r\nstruct TrieNode {\r\n    vector<int>\
    \ nxt;\r\n    TrieNode(int char_size) {\r\n        nxt.resize(char_size, -1);\r\
    \n    }\r\n    // \u4E00\u4E9B hook \u51FD\u6570\uFF0C\u7528\u4E8E Trie \u7B97\
    \u6CD5\u4EE5\u53CA ac \u81EA\u52A8\u673A, \u53EF\u4EE5\u8986\u76D6\u8FD9\u4E9B\
    \u51FD\u6570\u6765\u5B9E\u73B0\u4E00\u4E9B\u529F\u80FD\r\n\r\n    /*\r\n     *\
    \ \u5F53\u52A0\u5165\u5230\u5B57\u5178\u6811\u540E\uFF0C\u5BF9\u6700\u7EC8\u7684\
    \u8282\u70B9(\u5F53\u524D\u8282\u70B9)\u8FDB\u884C\u4E00\u4E9B\u64CD\u4F5C\r\n\
    \     */\r\n    void update_when_finish_in_trie(){};\r\n\r\n    /*\r\n     * \u5F53\
    \u52A0\u5165\u5230\u5B57\u5178\u6811\u65F6\uFF0C\u6839\u636E\u5F53\u524D\u8282\
    \u70B9\u548C\u5B50\u8282\u70B9\u7684\u4FE1\u606F\uFF0C\u5BF9\u5F53\u524D\u8282\
    \u70B9\u8FDB\u884C\u4E00\u4E9B\u64CD\u4F5C\r\n     */\r\n    void update_when_push_in_trie(TrieNode\
    \ &child_node){};\r\n\r\n    /*\r\n     * \u5F53\u6784\u5EFA fail \u51FD\u6570\
    \u65F6\uFF0C\u6839\u636E\u5F53\u524D\u8282\u70B9\u548C fail \u8282\u70B9\u7684\
    \u4FE1\u606F\uFF0C\u5BF9\u5F53\u524D\u8282\u70B9\u8FDB\u884C\u4E00\u4E9B\u64CD\
    \u4F5C\r\n     */\r\n    void update_when_build_fail(TrieNode &fail_node){};\r\
    \n};\r\n\r\ntemplate <typename T = TrieNode>\r\nstruct Trie {\r\n   public:\r\n\
    \    vector<T> nodes;\r\n    int root;\r\n\r\n    int char_size;\r\n    int margin;\r\
    \n\r\n    Trie(int char_size, int margin) : root(0), char_size(char_size), margin(margin)\
    \ {\r\n        nodes.push_back(T(char_size));\r\n    }\r\n\r\n    void add(const\
    \ string &s, int s_idx, int node_idx) {\r\n        /*\r\n         * \u5C06\u5B57\
    \u7B26\u4E32 s \u7684 s_idx \u4F4D\u7F6E\u5F00\u59CB\u7684\u540E\u7F00\u52A0\u5165\
    \u5230\u5B57\u5178\u6811\u4E2D. node_idx \u4E3A\u5F53\u524D\u8282\u70B9\u7684\u4E0B\
    \u6807\r\n         */\r\n        if (s_idx == s.size()) {\r\n            // \u5B8C\
    \u6210\u52A0\u5165\r\n            nodes[node_idx].update_when_finish_in_trie();\r\
    \n        } else {\r\n            const int c = s[s_idx] - margin;\r\n       \
    \     if (nodes[node_idx].nxt[c] == -1) {\r\n                nodes[node_idx].nxt[c]\
    \ = nodes.size();\r\n                nodes.push_back(T(char_size));\r\n      \
    \      }\r\n            add(s, s_idx + 1, nodes[node_idx].nxt[c]);\r\n       \
    \     // \u6839\u636E\u5F53\u524D\u8282\u70B9\u7684\u5B50\u8282\u70B9\u66F4\u65B0\
    \u5F53\u524D\u8282\u70B9\r\n            nodes[node_idx].update_when_push_in_trie(nodes[nodes[node_idx].nxt[c]]);\r\
    \n        }\r\n    }\r\n\r\n    void add(const string &s) {\r\n        add(s,\
    \ 0, root);\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy:
  - src/data_structure/aho_corasick.hpp
  timestamp: '2022-10-09 21:04:30+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aho_corasick.test.cpp
documentation_of: src/string/trie.hpp
layout: document
redirect_from:
- /library/src/string/trie.hpp
- /library/src/string/trie.hpp.html
title: Trie
---
# Trie

## 概要
字典树是一种树形结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。在该模板中，它分为两个部分。
### `TrieNode`
`TrieNode` 是字典树的节点，它包含了一个 `vector<int> nxt`，用于存储该节点的子节点。在使用时可以增加其他的属性，例如 `int cnt`，用于存储以该节点为结尾的单词的数量。它提供了 3 个 hook 函数。
- `void update_when_finish_in_trie()`: 当一个单词被插入到字典树中后，在该单词的最后一个字符的节点上调用该函数。
- `void update_when_push_in_trie(TrieNode &child_node)`: 当一个单词被插入到字典树的过程中，根据当前节点的子节点 `child_node` 来更新当前节点的属性。
- `void update_when_build_fail(TrieNode &fail_node)`: 当字典树被构造完成后，根据当前节点的失败指针 `fail_node` 来更新当前节点的属性。

### `Trie`
`Trie` 类是字典树的核心类，它提供了一些方法来构造字典树。
- `Trie(int char_size, int margin)`: 构造一个 `Trie` 类，用于存储字符集大小为 `char_size` 的字符串，`margin` 为字符集的起始字符。
- `void add(const string &s)`: 将字符串 `s` 插入到字典树中。

## 常见问题

## 题集