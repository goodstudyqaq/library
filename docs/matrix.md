# 矩阵

## 概要
Matrix 是一个二维数组，它的每个元素都是一个数字。Matrix 有两个属性：行数和列数。Matrix 的行数和列数都是整数，且行数和列数都是大于等于 1 的整数。Matrix 的行数和列数都是固定的，不可变的。
### `Matrix`
`Matrix` 是一个矩阵的模板，它的用法如下：
```cpp
Matrix<int> matrix(2, 3);
matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[0][2] = 3;
matrix[1][0] = 4;
matrix[1][1] = 5;
matrix[1][2] = 6;
```
它有以下成员函数：
- `Matrix(int n, int m, const T& value = T())`：构造一个 `n` 行 `m` 列的矩阵，每个元素都是 `value`。
- `Matrix(int n, const T& value = T())`：构造一个 `n` 行 `n` 列的矩阵，每个元素都是 `value`。
- `Matrix(const vector<vector<T>>& values)`：构造一个矩阵，它的元素是 `values`。
- `static Matrix I(int n)`：构造一个 `n` 行 `n` 列的单位矩阵。
- `vector<T>& operator[](int i)`：返回第 `i` 行。
- `Matrix operator+(const Matrix& other) const`：返回两个矩阵的和。
- `Matrix operator-(const Matrix& other) const`：返回两个矩阵的差。
- `Matrix operator*(const Matrix& other) const`：返回两个矩阵的乘积。
- `Matrix operator^(long long k) const`：返回矩阵的 `k` 次幂。
- `static to_string(const Matrix& matrix)`：返回矩阵的字符串表示, 用于调试.

### `Det`
`Det` 是一个矩阵行列式的模板，它的用法如下：
```cpp
Matrix<int> matrix(2, 2);
matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[1][0] = 3;
matrix[1][1] = 4;
Det<int> det(matrix);
det.get(); // 1 * 4 - 2 * 3 = -2

```



## 常见问题

## 题集
