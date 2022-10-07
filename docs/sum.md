# Sum

## 概要
记录一些前缀和用法。
**前缀和其实可以以任意方向去递推。**
### `Sum`
`Sum` 是一个前缀和的模板，下标从 1 开始。 它有以下几个参数：
- `vector<T> sum1`：`sum1[i]` 表示 `a[1] + a[2] + ... + a[i]`。
- `vector<T> sum2`: `sum2[i]` 表示 `sum1[1] + sum1[2] + ... + sum1[i]`。

- `Sum(vector<T> &a)`: 构造一个 `Sum` 类，用于求解 `a` 的前缀和。
- `T get_special_sum1(int i, int r)`: 计算 $(i, r]$ 所有元素到 $ i + 1 $ 的区间和的和。
- `T get_special_sum2(int i, int l)`: 以 $ i $ 为起点， 计算 $ [l, i] 所有元素到 $ i $ 的区间和的和。

## 常见问题

## 题集
- 斜率前缀和：https://atcoder.jp/contests/abc260/tasks/abc260_g