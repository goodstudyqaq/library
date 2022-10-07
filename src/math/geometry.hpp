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
    bool cmp(const Point<T> &a, const Point<T> &b) const {
        T x = a ^ b;
        return x == 0 ? a.length() < b.length() : x > 0;
    }

    vector<Point<T>> graham(vector<Point<T>> &ps) {
        sort(ps.begin(), ps.end());
        ps.erase(unique(ps.begin(), ps.end()), ps.end());
        int n = ps.size();
        if (n <= 1) return ps;
        vector<Point<T>> qs(n);

        int k = 0;
        for (int i = 0; i < n; i++) {
            while (k > 1 && (qs[k - 1] - qs[k - 2]) ^ (ps[i] - qs[k - 1]) <= 0)
                k--;
            qs[k++] = ps[i];
        }

        return qs;
    }
};
