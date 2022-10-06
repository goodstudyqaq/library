# Manacher

## 概要
Manacher 算法是一个用于求解最长回文子串的算法，时间复杂度为 O(n)。
### `Manacher`
`Manacher` 类是 Manacher 算法的核心类，它提供了一些方法来求解最长回文子串。
- `Manacher(string &s)`: 构造一个 `Manacher` 类，用于求解字符串 `s` 的最长回文子串。
- `int query(int l, int r)`: 如果 $l = r$ ，则返回以 $l$ 为中心的最长回文子串的长度。如果 $l + 1 = r$ ，则返回以 $l$ 和 $r$ 为中心的最长回文子串的长度。

## 常见问题

## 题集