#  位运算

## 概要
记录一些位运算的技巧
### `Subset`
`Subset` 类实现枚举 `status` 的全部子集，用法可参考下面代码:
```cpp
#include "src/math/bits.h"
int main() {
    Subset subset(10); // 1010
    for (auto it = subset.begin(); it != subset.end(); ++it) {
        cout << *it << endl;
    }
    // 输出: 10 8 2 0
}
```

### `NonEmptySubset`
`NonEmptySubset` 类实现枚举 `status` 的全部非空子集，用法与 `Subset` 类似。

### `ProperSubset`
`ProperSubset` 类实现枚举 `status` 的全部真子集，用法与 `Subset` 类似。

### `NonEmptyProperSubset`
`NonEmptyProperSubset` 类实现枚举 `status` 的全部非空真子集，用法与 `Subset` 类似。

### `MultiSubset`
`MultiSubset` 类实现求多个集合的所有非空子集的集合
- `vector<bool> multi_subset(vector<int>& status)`: 返回 `status` 的所有非空子集的集合

### `Superset`
`Superset` 类实现枚举 `status` 的全部超集，用法与 `Subset` 类似。

### `SubsetK`
`SubsetK` 类实现枚举 `status` 的全部大小为 `k` 的子集，用法与 `Subset` 类似。

### `AllOne`
`AllOne` 类实现枚举 `status` 的全部 `1` 的位置，用法与 `Subset` 类似。



## 常见问题

## 题集