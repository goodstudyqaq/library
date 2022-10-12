https://codeforces.com/blog/entry/45223

# 概要
SOS DP(Sum over Subsets) 主要用于计算子集和问题, 即 
$$F[\text { mask }]=\sum_{i \subseteq \text { mask }} A[i]$$

复杂度为 $O(N2^N)$, 该模板提供两种写法，思路都是一样的，只是实现方式不同。`iterative_version` 为算法的基本实现。而 `easy_version` 对空间进行了优化，实现也更加简洁。 

# 常见问题

# 题集
