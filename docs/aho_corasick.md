# AC 自动机

## 概要
AC 自动机，全称为 Aho-Corasick 自动机，是一种多模式匹配算法，用于在一段文本中查找多个模式串的出现位置。它的时间复杂度为 $O(n)$，其中 $n$ 为文本的长度。
该模板主要分为 3 个部分。
### `TrieNode`
详细的说明可以参考 [Trie](./trie.md)。
### `Trie`
详细的说明可以参考 [Trie](./trie.md)。

### `AhoCorasick`
`AhoCorasick` 为 AC 自动机的主体，继承自 `Trie` 类。主要有以下几个方法:
- `void build()` : 构造 AC 自动机


## 常见问题

## 题集
https://codeforces.com/contest/1739/submission/174501979