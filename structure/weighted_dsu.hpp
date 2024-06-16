#include <bits/stdc++.h>
using namespace std;
/*
@brief 带权并查集
@docs docs/weighted_dsu.md
*/

// 带权并查集
template <typename T>
struct WeightedDSU {
    std::vector<int> f;
    vector<T> g;
    WeightedDSU(int n) : f(n), g(n) { std::iota(f.begin(), f.end(), 0); }
    std::pair<int, T> leader(int x) {
        if (f[x] == x) {
            return {x, g[x]};
        }
        auto [y, z] = leader(f[x]);
        f[x] = y;
        g[x] += z;
        return {f[x], g[x]};
    }
    // a->b=z
    bool merge(int a, int b, T z) {
        // a->x=u
        auto [x, u] = leader(a);
        // b->y=v
        auto [y, v] = leader(b);
        if (x == y) {
            // a->x
            return u - v == z;
        }
        f[x] = y;
        g[x] = v - u + z;
        return true;
    }
};
