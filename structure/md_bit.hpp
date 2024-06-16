// http://oj.daimayuan.top/course/15/problem/637 二维树状数组模板题
#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct MDBIT {
#define lowbit(x) x & -x
    const int n, m;
    md_vector<T, 2> a;
    // [1, n]
    MDBIT(int n, int m) : n(n), m(m) {
        a = md_vector<T, 2>({n + 1, m + 1});
    }
    void add(int x, int y, T v) {
        for (int p = x; p <= n; p += lowbit(p)) {
            for (int q = y; q <= m; q += lowbit(q)) {
                a[p][q] += v;
            }
        }
    }

    // [1, x]
    T query(int x, int y) {
        T res = 0;

        for (int p = x; p > 0; p -= lowbit(p)) {
            for (int q = y; q > 0; q -= lowbit(q)) {
                res += a[p][q];
            }
        }
        return res;
    }
};