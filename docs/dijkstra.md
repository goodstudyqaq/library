# 概要
Dijkstra 算法是一种用于计算有向图中单源最短路径的算法。堆优化的时间复杂度为 $O(m\log n)$，其中 $m$ 为边数，$n$ 为点数。普通写法的时间复杂度为 $O(mn)$。

## `Dijkstra`
`Dijkstra` 类为 Dijkstra 算法的主体，它继承自 `Graph` 类。主要有以下几个方法:
- `vector<T> dijkstra(int s)` : 从点 $s$ 开始计算所有点到 $s$ 的最短距离, 该函数使用堆优化，时间复杂度为 $O(m\log n)$。
- `vector<T> normal_dijkstra(int s)`: 从点 $s$ 开始计算所有点到 $s$ 的最短距离, 该函数为普通写法，时间复杂度为 $O(mn)$。

# 常见问题

# 题集