#include <bits/stdc++.h>

#include "src/graph/graph_template.hpp"
using namespace std;
/*
@brief 最短路
@docs docs/shortest_path.md
*/

/*
套路题：二进制判不同色最短路 or 次短路。https://atcoder.jp/contests/abc245/tasks/abc245_g
次短路做法：再加一个距离数组 dis2, 具体看：https://atcoder.jp/contests/abc245/submissions/32661509
*/

// 一般形式的 dijkstra
template <typename T = int>
struct Dijkstra : Graph<T> {
    // 下标从 1 到 n

    vector<T> normal_dijkstra(int s) {
        // O(n ^ 2)
        const T inf = numeric_limits<T>::max();
        int n = g.size();
        vector<bool> vis(n, 0);
        vector<T> d(n, inf);

        d[s] = 0;
        for (int i = 0; i < n; i++) {
            int x, m = inf;
            for (int y = 1; y <= n; y++) {
                if (!vis[y] && d[y] <= m) {
                    m = d[x = y];
                }
            }
            vis[x] = 1;
            for (auto e : g[x]) {
                int y = e.to;
                if (d[y] > d[x] + e.w) {
                    d[y] = d[x] + e.w;
                }
            }
        }
        return d;
    }

    vector<T> dijkstra(int s) {
        // O(m * log n)
        const T inf = numeric_limits<T>::max();
        int n = g.size();
        vector<T> d(n, inf);
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;
        vector<bool> vis(n, 0);

        d[s] = 0;
        Q.push({0, s});
        while (!Q.empty()) {
            auto [dis, x] = Q.top();
            Q.pop();
            if (vis[x]) continue;
            vis[x] = 1;

            for (auto e : g[x]) {
                int y = e.to;
                if (d[y] > d[x] + e.w) {
                    d[y] = d[x] + e.w;
                    Q.push({d[y], y});
                }
            }
        }
        return d;
    }
};
