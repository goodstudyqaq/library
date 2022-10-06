# 数论

## 概要
记录一些数论的知识点

### 分块
分块是一种常见的优化算法，它的基本思想是将一个序列分成若干个块，每个块的长度为 $O(\sqrt{n})$，然后对每个块进行预处理，这样就可以在 $O(1)$ 的时间内回答询问。
#### `IntegerChunk`
`IntegerChunk` 是一个分块的模板, 它返回一个正着分块的迭代器, 用法如下:
```cpp
IntegerChunk chunk(100);
for (auto it = chunk.begin(); it != chunk.end(); ++it) {
    cout << *it << endl;
}
```
#### `ReverseIntegerChunk`
`ReverseIntegerChunk` 是一个分块的模板, 它返回一个反着分块的迭代器, 用法与 `IntegerChunk` 相同.



## 常见问题

## 题集
h