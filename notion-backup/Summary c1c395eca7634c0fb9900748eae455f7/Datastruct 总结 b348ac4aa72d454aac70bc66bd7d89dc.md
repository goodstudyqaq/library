# Datastruct 总结

1. 前缀和
    
    斜率前缀和，可以维护当前的斜率，然后计算当前的点的值可以拿斜率 * 与上次点的位置差。
    
    [https://codeforces.com/contest/1711/problem/D](https://codeforces.com/contest/1711/problem/D)
    

1. 线段树
    
    线段树维护按异或值交换位置后的最大连续子串和
    
    [https://codeforces.com/contest/1716/problem/E](https://codeforces.com/contest/1716/problem/E)
    
2. 带权并查集
    
    带权并查集来判断当前选择是否可行，操作可以贪心去以此去选，然后并查集来判断当前选择的操作是否和之前的有矛盾
    
    [https://codeforces.com/contest/1713/problem/E](https://codeforces.com/contest/1713/problem/E)
    
3. 堆
    
    用最小/大堆找到第 k 大序列和
    
    [https://leetcode.cn/contest/weekly-contest-307/problems/find-the-k-sum-of-an-array/](https://leetcode.cn/contest/weekly-contest-307/problems/find-the-k-sum-of-an-array/)
    
4. 单调栈
    
    统计数量，计算跟区间最大值最小值有关的区间个数
    
    [https://codeforces.com/contest/1730/problem/E](https://codeforces.com/contest/1730/problem/E)
    
    [E. Maximums and Minimums](https://www.notion.so/E-Maximums-and-Minimums-42ca8d24b855493987c88b66606285d2)