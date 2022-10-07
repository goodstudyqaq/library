#include <bits/stdc++.h>
using namespace std;

/*
@brief Theory
@docs docs/math_theory.md
*/

struct IntegerChunk {
    int n;
    IntegerChunk(int n) : n(n) {}

    struct Iterator {
        int i;
        int n;
        int l, r, val;
        // n / [l, r] = val
        //正着
        // a / val 能求到一个上限 r， a / r = val 即最大的 r 使得 a / r = val
        Iterator(int _i, int _n) : i(_i),
                                   n(_n) {
            l = i;
            val = n / l;
            r = n / val;
        }
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            return *this = Iterator(r + 1, n);
        }
    };
    Iterator begin() const {
        return Iterator(1, n);
    }
    Iterator end() const {
        return Iterator(n, n);
    }
};

struct ReverseIntegerChunk {
    int n;
    ReverseIntegerChunk(int n) : n(n) {}

    struct Iterator {
        int i;
        int n;
        int l, r, val;
        /*
        反着枚举
        大概的逻辑： a / i 能够得到当前的 val，而 val 也能理解成一个是得到 i 的最大的 r，即 val 是满足 a / val = i 的最大的值，那么 val + 1 是下一层的左端点，
        再进行一个 / 就能得到下一层的值，即也是能得到下一层的值的右端点。
        有点绕，估计面对这个问题的时候这个逻辑也是看不懂的。还是看下面的注释吧。
        */
        Iterator(int _i, int _n) : i(_i), n(_n) {
            r = i;
            val = n / r;
            l = n / (val + 1) + 1;
        }
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            return *this = Iterator(l - 1, n);
        }
    };
    Iterator begin() const {
        return Iterator(n, n);
    }
    Iterator end() const {
        return Iterator(1, n);
    }
};
