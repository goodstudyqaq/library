
# 概要
线段树是一种用于维护区间信息的数据结构。它的基本操作是维护区间信息，查询区间信息，修改区间信息。时间复杂度均为 $O(\log n)$ 。
该模板主要分为 2 个部分。

## `Info`
`Info` 是一个结构体，用于存储区间信息。使用时需要实现 `merge` 方法, 用于合并两个节点的信息.

## `SegmentTree`
`SegmentTree` 是一个线段树的实现，主要有以下几个方法:
- `SegmentTree(int n)` : 构造函数，传入数组的长度。区间默认为 `[0, n)` 。
- `SegmentTree(vector<Info> init)` : 构造函数，传入一个数组。区间默认为 `[0, init.size())` 。
- `Info rangeQuery(int l, int r)`: 查询区间 `[l, r]` 的信息。
- `void update(int L, const Info& v)` : 将区间 `[L, L]` 的信息更新为 `v`，即会与 `v` 进行 `merge` 操作。
- `void assign(int L, const Info& v)` : 将区间 `[L, L]` 的信息赋值为 `v`，即会直接赋值，不会进行 `merge` 操作。


# 常见问题

# 题集
