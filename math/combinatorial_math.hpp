
template <typename T = int>
T get_plan1(int n, int m) {
    // n 个不同的包，m 个相同的球得到的方案数
    // 可以理解 n + m - 1 个位置，把 n - 1 个包放进去，包前面的空位就是它有的球的个数，最后剩余的就是最后一个包有的球的个数

    /*
    https://codeforces.com/contest/1929/problem/F
    转换一：m 个数，每个数的范围是[1, n]，求不同的方案数，两个数组排完序后不同才算不同。可以这样看待这个问题:
    [1, n] 相当于有 n 个不同的包，你要把这 m 个数，放到这 n 个包中，这 m 个数是等价的，放完后其实就相当于一个方案。
    */
    return C(n + m - 1, m);
}
