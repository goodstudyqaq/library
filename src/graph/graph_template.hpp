#pragma once
#include <bits/stdc++.h>
using namespace std;

/*
@brief 带权并查集
@docs docs/weighted_dsu.md
*/

template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;
    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

    // Edge e = Edge(); int to = e;
    operator int() const { return to; }
};

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;  // 边数

    Graph() = default;
    explicit Graph(int n) : g(n), es(0) {}

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_undirected_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);  // 无向边的编号相同
    }

    void read(int m, int offset = -1, bool directed = false, bool weighted = false) {
        for (int i = 0; i < m; i++) {
            int u, v;
            // 需要关闭同步 IO
            cin >> u >> v;
            // 默认从 0 开始编号
            u += offset;
            v += offset;

            T w = 1;
            if (weighted) {
                cin >> w;
            }

            if (directed) {
                add_directed_edge(u, v, w);
            } else {
                add_undirected_edge(u, v, w);
            }
        }
    }

    inline vector<Edge<T>> &operator[](const int &u) {
        return g[u];
    }

    inline const vector<Edge<T>> &operator[](const int &u) const {
        return g[u];
    }
};

template <typename T = int>
using Edges = vector<Edge<T>>;