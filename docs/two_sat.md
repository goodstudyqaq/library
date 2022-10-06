# TwoSat
## 概要
TwoSat 是一个用于解决 2-SAT 问题的算法。它的时间复杂度为 O(n+m)。
### `TwoSat` 
`TwoSat` 类是一个用于解决 2-SAT 问题的类。它继承自 `Graph` 类。主要有以下函数：
- `TwoSat(int n)`：构造函数，参数为变量的个数。
- `void addClause(int u, bool f, int v, bool g)`: (u, f) 和 (v, g) 有矛盾。
- `bool satisfiable()`: 判断是否有解。
- `vector<bool> answer()`: 返回解。


## 常见问题

## 题集