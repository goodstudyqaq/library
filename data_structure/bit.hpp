#include <bits/stdc++.h>
using namespace std;
/*
@brief 树状数组
docs: https://goodstudyqaq.notion.site/fcd1b861b033403299c45a8fab32e5a3?pvs=4
*/

// 树状数组二分: http://oj.daimayuan.top/course/15/problem/636
//
template <typename T>
struct BIT {
#define lowbit(x) x & -x
    const int n;
    vector<T> a;
    // [1, n]
    BIT(int n) : n(n), a(n + 1) {}
    void add(int x, T v) {
        while (x <= n) {
            a[x] += v;
            x += lowbit(x);
        }
    }

    // [1, x]
    T query(int x) {
        T res = 0;
        while (x) {
            res += a[x];
            x -= lowbit(x);
        }
        return res;
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    int search(T val) {  // 找到最后一个 res，使得 [1, res] 的前缀和 <= val
        int level = largest_bit(n);
        int res = 0;
        for (int i = level; i >= 0; i--) {
            if (res + (1 << i) <= n && val >= a[res + (1 << i)]) {  // 注意 val >= a[res + (1 << i)], 如果求的是 < val，那么相应也要去掉 = 号
                res += (1 << i);
                val -= a[res];
            }
        }
        return res;
    }
};