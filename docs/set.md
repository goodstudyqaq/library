# Set

## 概要
记录 set 常见使用套路

### `CountIntervals`
维护一个区间集合，求出区间集合中包含的整数个数
- `void add(int left, int right)`: 向集合中添加一个区间 `[left, right]` 。
- `int count()`: 求出集合中包含的整数个数。
- `pii get_interval(int idx)`: 求出包含 `idx` 的区间。如果没有包含 `idx` 的区间，返回 `{-1, -1}` 。

## 常见问题

## 题集
- https://atcoder.jp/contests/abc254/tasks/abc254_g
- https://leetcode.com/problems/count-integers-in-intervals/
- https://atcoder.jp/contests/abc256/tasks/abc256_h