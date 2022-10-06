# KMP

## 概要
KMP 是一个用于快速匹配字符串的算法。它的时间复杂度为 O(n+m)。
### `KMP`
`KMP` 类是 KMP 的核心类，它提供了一些方法来快速匹配字符串。
- `KMP(const string &s)` : 构造一个 `KMP` 类，用于匹配字符串 `s` 。
- `void kmp_pre()`: 预处理字符串 `s` ，计算出 `next` 数组。
- `void fast_kmp_pre()`: 更快的预处理字符串 `s` ，计算出 `next` 数组。
- `int count(string &s2)`: 返回字符串 `s2` 在字符串 `s` 中出现的次数。需要先调用 `kmp_pre()` 或 `fast_kmp_pre()` 。

## 常见问题

## 题集