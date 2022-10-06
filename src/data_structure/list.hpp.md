---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/list.md
    document_title: List
    links: []
  bundledCode: "#line 1 \"src/data_structure/list.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n/*\r\n@brief List\r\n@docs docs/list.md\r\n*/\r\n\
    \r\ntemplate <typename T>\r\nstruct Node {\r\n    int next, last;\r\n    T w;\r\
    \n    Node(T _w = T(), int _next = -1, int _last = -1) : w(_w), next(_next), last(_last)\
    \ {}\r\n};\r\n\r\ntemplate <typename T>\r\nstruct List {\r\n    vector<Node<T>>\
    \ nodes;\r\n    Node<T> ed;\r\n    int init() {\r\n        nodes.clear();\r\n\
    \        ed = Node<T>();\r\n        nodes.emplace_back(ed);\r\n        return\
    \ nodes.size() - 1;\r\n    }\r\n\r\n    void link(int a, int b) {\r\n        nodes[a].next\
    \ = b;\r\n        nodes[b].last = a;\r\n    }\r\n\r\n    int new_node(int idx,\
    \ T _w) {\r\n        Node<T> it = Node<T>(_w);\r\n        nodes.emplace_back(it);\r\
    \n        int sz = nodes.size() - 1;\r\n        int last = nodes[idx].last;\r\n\
    \        if (last != -1) {\r\n            link(last, sz);\r\n        }\r\n   \
    \     link(sz, idx);\r\n        return sz;\r\n    }\r\n\r\n    int erase_node(int\
    \ idx) {\r\n        int last = nodes[idx].last, next = nodes[idx].next;\r\n\r\n\
    \        if (last != -1) {\r\n            nodes[last].next = -1;\r\n        }\r\
    \n        if (next != -1) {\r\n            nodes[next].last = -1;\r\n        }\r\
    \n\r\n        if (last != -1 && next != -1) {\r\n            link(last, next);\r\
    \n        }\r\n        return last;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/*\r\n@brief List\r\
    \n@docs docs/list.md\r\n*/\r\n\r\ntemplate <typename T>\r\nstruct Node {\r\n \
    \   int next, last;\r\n    T w;\r\n    Node(T _w = T(), int _next = -1, int _last\
    \ = -1) : w(_w), next(_next), last(_last) {}\r\n};\r\n\r\ntemplate <typename T>\r\
    \nstruct List {\r\n    vector<Node<T>> nodes;\r\n    Node<T> ed;\r\n    int init()\
    \ {\r\n        nodes.clear();\r\n        ed = Node<T>();\r\n        nodes.emplace_back(ed);\r\
    \n        return nodes.size() - 1;\r\n    }\r\n\r\n    void link(int a, int b)\
    \ {\r\n        nodes[a].next = b;\r\n        nodes[b].last = a;\r\n    }\r\n\r\
    \n    int new_node(int idx, T _w) {\r\n        Node<T> it = Node<T>(_w);\r\n \
    \       nodes.emplace_back(it);\r\n        int sz = nodes.size() - 1;\r\n    \
    \    int last = nodes[idx].last;\r\n        if (last != -1) {\r\n            link(last,\
    \ sz);\r\n        }\r\n        link(sz, idx);\r\n        return sz;\r\n    }\r\
    \n\r\n    int erase_node(int idx) {\r\n        int last = nodes[idx].last, next\
    \ = nodes[idx].next;\r\n\r\n        if (last != -1) {\r\n            nodes[last].next\
    \ = -1;\r\n        }\r\n        if (next != -1) {\r\n            nodes[next].last\
    \ = -1;\r\n        }\r\n\r\n        if (last != -1 && next != -1) {\r\n      \
    \      link(last, next);\r\n        }\r\n        return last;\r\n    }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/list.hpp
  requiredBy: []
  timestamp: '2022-10-06 19:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/list.hpp
layout: document
redirect_from:
- /library/src/data_structure/list.hpp
- /library/src/data_structure/list.hpp.html
title: List
---
# List

## 概要
链表 List 是一种线性表，用一组任意的内存空间，依次存储线性表的数据元素。它由以下两部分组成：
### `Node`
`Node` 是链表中的一个节点，它包含了一个数据元素和一个指向下一个节点的指针。使用时可以往 `Node` 中存储任意类型的数据。
### `List`
`List` 是算法主体。主要有以下几个功能：
- `int init()` 初始化链表, 返回链表的头指针的下标
- `int new_node(int idx, T w)` 在链表的第 idx 个节点后插入一个新节点, 返回新节点的下标
- `int erase_node(int idx)` 删除链表的第 idx 个节点, 返回下一个节点的下标


## 常见问题

## 题集