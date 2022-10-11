# 概要
带懒惰标签的线段树, 时间复杂度均为 $O(\log n)$ 。主要由以下几个部分组成:
## `Tag`
`Tag` 为懒惰标签, 用于记录当前节点的信息, 例如 `add` 操作, `min` 操作, `max` 操作等等。使用时需要实现 `apply` 方法, 用于将标签 `v` 的值下放到当前节点上。


## `Info`
`Info` 为当前节点的信息, 例如 `sum` 操作, `min` 操作, `max` 操作等等。使用时需要实现 `merge` 方法, 用于合并两个节点的信息; 以及 `apply` 方法, 用于将懒惰标签 `v` 的值下放到当前节点上。


## `LazySegmentTree`
算法的模板类, 需要传入两个类，`Info` 与 `Tag`，用于维护线段树。主要有以下几个方法:
- `LazySegmentTree(int n)` : 构造一个长度为 `n` 的线段树
- `LazySegmentTree(vector<Info> &init)` : 构造一个长度为 `init.size()` 的线段树, 并将 `init` 中的值赋值给线段树。区间范围为 `[0, init.size())`
- `void update(int L, const Info &v)`: 将 `L` 位置的值更新为 `v`
- `void rangeUpdate(int L, int R, const Tag &v)` : 将 `[L, R]` 区间的值更新为 `v`
- `Info rangeQuery(int L, int R)` : 查询 `[L, R]` 区间的值
- `int find_first(int ll, int rr, const function<bool(const Info &)> &f)` : 在 `[ll, rr]` 区间内找到第一个满足 `f` 的位置, 如果不存在则返回 `-1`
- `int find_last(int ll, int rr, const function<bool(const Info &)> &f)` : 在 `[ll, rr]` 区间内找到最后一个满足 `f` 的位置, 如果不存在则返回 `-1`

# 常见问题

# 题集
- https://atcoder.jp/contests/abc256/tasks/abc256_h
- https://atcoder.jp/contests/abc248/tasks/abc248_h

