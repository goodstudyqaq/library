#include <bits/stdc++.h>
using namespace std;
/*
@brief Geometry
@docs docs/geometry.md
*/

template <typename T = int>
struct Point {
    T x, y;
    Point() : x(), y() {}
    Point(T x, T y) : x(x), y(y) {}

    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(const T &k) const { return Point(x * k, y * k); }
    // 点积, a * b = |a| * |b| * cos(a, b), 点乘的几何意义是可以用来表征或计算两个向量之间的夹角，以及在b向量在a向量方向上的投影
    T operator*(const Point &p) const { return x * p.x + y * p.y; }

    // 叉积, a x b = |a| * |b| * sin(a, b), 在二维空间中，叉积的几何意义是可以用来计算两个向量的面积，以及判断两个向量的方向
    T operator^(const Point &p) const { return x * p.y - y * p.x; }
    T abs2() const { return x * x + y * y; }

    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
};

template <typename T = int>
struct Graham {
    static bool cmp(const Point<T> &a, const Point<T> &b) {
        T x = a ^ b;
        return x == 0 ? a.abs2() < b.abs2() : x > 0;
    }

    vector<Point<T>> graham(vector<Point<T>> ps, bool equal = false) {
        int n = ps.size();
        if (n <= 1) return ps;
        sort(ps.begin(), ps.end());
        auto p0 = ps[0];
        for (int i = 0; i < n; i++) {
            ps[i] = ps[i] - p0;
        }
        sort(ps.begin(), ps.end(), cmp);
        if (equal) {
            int sz = n - 1;
            while (sz >= 0 && ((ps[n - 1] - ps[0]) ^ (ps[sz] - ps[0])) == 0) sz--;
            for (int l = sz + 1, r = n - 1; l < r; l++, r--) {
                swap(ps[l], ps[r]);
            }
        }
        vector<Point<T>> qs(n);
        int k = 0;
        for (int i = 0; i < n; i++) {
            while (k > 1) {
                T tmp = (qs[k - 1] - qs[k - 2]) ^ (ps[i] - qs[k - 1]);
                if (tmp < 0 || (!equal && tmp == 0)) k--;
                else break;
            }
            qs[k++] = ps[i];
        }
        qs.resize(k);

        for (int i = 0; i < k; i++) {
            qs[i] = qs[i] + p0;
        }
        return qs;
    }
};
