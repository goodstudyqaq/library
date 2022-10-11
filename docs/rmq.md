# 概要
RMQ 为 Range Minimum Query 的缩写，用于查询区间内的最值问题。时间复杂度为 $O(n\log n)$。

## `RMQ`
`RMQ` 是一个该算法的模板类，主要有以下几个方法：
- `RMQ(const vector<T>& _values, function<bool(T, T)> f)`: 构造函数，传入一个数组和一个比较函数，用于比较两个值的大小。
- `void build(const vector<T>& _values, function<bool(T, T)> f)`: 重新构造 RMQ，传入一个数组和一个比较函数，用于比较两个值的大小。
- `int rmq_index(int a, int b)`: 查询区间 `[a, b]` 内的最值的下标。
- `T rmq_value(int a, int b)`: 查询区间 `[a, b]` 内的最值。
- `int nxt_idx(int idx)`: 查询下一个不同值的下标。


# 常见问题

# 题集