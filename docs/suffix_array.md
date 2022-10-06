# Suffix Array

## 概要
Suffix Array 是一种用于快速查找字符串中所有后缀的数据结构。它的构造时间复杂度为 O(nlogn)，空间复杂度为 O(n)。它的应用有很多，比如在字符串匹配中，可以用于快速查找字符串中所有出现的子串。
### `SuffixArray`
`SuffixArray` 类是 Suffix Array 的核心类，它提供了一些方法来构造后缀数组。
- `SuffixArray(string &s)`: 构造一个 `SuffixArray` 类，用于构造字符串 `s` 的后缀数组。
- `int get_length(int idx1, int idx2)`: 返回字符串中下标为 `idx1` 和 `idx2` 的两个后缀的最长公共前缀的长度。

## 常见问题

## 题集