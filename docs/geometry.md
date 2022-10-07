# 计算几何

## 概要
记录一下常见的计算几何模板
### `Point`
`Point` 是一个模板类，包含两个 `T` 类型的成员 `x` 和 `y`，表示一个二维平面上的点，也可以表示一个向量。主要有以下操作：
- `Point(T x, T y)`：创建一个点 `(x, y)` 。
- `Point operator+(const Point &rhs) const`：返回两个点的和。
- `Point operator-(const Point &rhs) const`：返回两个点的差。
- `Point operator*(T k) const`：返回点乘以一个数的结果。
- `T operator^(const Point &rhs) const`：返回两个点的叉积。
- `T operator*(const Point &rhs) const`：返回两个点的点积。
- `T abs2() const`：返回点的模的平方。
- `bool operator<(const Point &rhs) const`：按照 `x` 坐标从小到大排序，如果 `x` 坐标相同，则按照 `y` 坐标从小到大排序。

### `Graham`
`Graham` 是一个模板类，包含一个 `Point` 类型的模板参数 `T`，表示点的类型。主要有以下操作：
- `vector<Point<T>> graham(vector<Point<T>> points)`：返回凸包上的点，点按照逆时针排序。

## 常见问题

## 题集