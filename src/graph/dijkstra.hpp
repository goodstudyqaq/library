#include <bits/stdc++.h>

#include "src/graph/graph_template.hpp"
using namespace std;
/*
@brief Dijkstra
@docs docs/shortest_path.md
*/

/*
套路题：二进制判不同色最短路 or 次短路。https://atcoder.jp/contests/abc245/tasks/abc245_g
次短路做法：再加一个距离数组 dis2, 具体看：https://atcoder.jp/contests/abc245/submissions/32661509
*/

// 一般形式的 dijkstra
// https://codeforces.com/contest/1741/problem/G
template <typename Graph, typename T>
struct Dijkstra {
    Graph &g;
    T inf;

    vector<T> dist;
    vector<int> prev;
    vector<long long> num;

    Dijkstra(Graph &graph) : g(graph) {
        inf = numeric_limits<T>::max();
    }

    void init(int n) {
        dist.resize(n, inf);
        prev.resize(n, -1);
        num.resize(n, 0);

        for (int i = 0; i < n; i++) {
            dist[i] = inf;
            prev[i] = -1;
            num[i] = 0;
        }
    }

    // [0, n)
    void normal_dijkstra(int s) {
        // O(n ^ 2)
        int n = g.size();
        vector<bool> vis(n, 0);
        init(n);

        dist[s] = 0;
        num[s] = 1;

        for (int i = 0; i < n; i++) {
            int x;
            T m = inf;
            for (int y = 1; y <= n; y++) {
                if (!vis[y] && dist[y] <= m) {
                    m = dist[x = y];
                }
            }
            vis[x] = 1;
            for (auto e : g[x]) {
                int y = e.to;
                if (dist[y] > dist[x] + e.cost) {
                    dist[y] = dist[x] + e.cost;
                    prev[y] = x;
                    num[y] = num[x];
                } else if (dist[y] == dist[x] + e.cost) {
                    num[y] += num[x];
                }
            }
        }
    }

    void dijkstra(int s) {
        // O(m * log n)
        const T inf = numeric_limits<T>::max();
        int n = g.size();
        vector<bool> vis(n, 0);
        init(n);

        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;

        dist[s] = 0;
        num[s] = 1;
        Q.push({0, s});
        while (!Q.empty()) {
            auto [dis, x] = Q.top();
            Q.pop();
            if (vis[x]) continue;
            vis[x] = 1;

            for (auto e : g[x]) {
                int y = e.to;
                if (dist[y] > dist[x] + e.cost) {
                    dist[y] = dist[x] + e.cost;
                    prev[y] = x;
                    num[y] = num[x];
                    Q.push({dist[y], y});
                } else {
                    num[y] += num[x];
                }
            }
        }
    }
};
