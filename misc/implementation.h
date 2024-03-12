/*
1. 对数组的某个值进行操作，使整个数组变成某种状态。可以转化对为该数组的前缀和数组的一个区间操作。那么对多个值进行操作的话，相当于对前缀和数组多个区间进行操作。
    转换之后的好处：
        1. 假如你对一个序列进行操作，那么更新的话可能需要针对多个位置进行操作，但变成前缀和的话，可能可以变成区间操作？
        2. 针对把整个数组变成某个状态的题(全部变成 0), 区间操作可以更好的知道怎么操作更优。
            - https://codeforces.com/contest/1775/problem/E

*/