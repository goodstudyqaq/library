#pragma once
#include <bits/stdc++.h>
using namespace std;

/*
@brief Graph template
@docs docs/graph_template.md
*/

template <typename T>
struct Edge {
    int from, to;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = 1) : from(from), to(to), cost(cost) {}

    // Edge e = Edge(); int to = e;
    operator int() const { return to; }
};

// [0, n)
template <typename Edge>
struct Graph {
    vector<vector<Edge>> g;

    Graph() = default;
    explicit Graph(int n) : g(n) {}

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(const Edge &e) {
        g[e.from].push_back(e);
    }

    void add_undirected_edge(const Edge &e) {
        g[e.from].push_back(e);
        Edge rev = e;
        swap(rev.from, rev.to);
        g[rev.from].push_back(rev);
    }

    inline const vector<Edge> &operator[](const int &u) const {
        return g[u];
    }
};

template <typename Edge>
struct Tree : Graph<Edge> {
    using Graph<Edge>::g;
    using Graph<Edge>::add_directed_edge;
    using Graph<Edge>::add_undirected_edge;
    using Graph<Edge>::size;
    int root;

    Tree() = default;
    // root = -1 为无根树
    explicit Tree(int n, int root = -1) : Graph<Edge>(n), root(root) {}

    // todo: 可以加一些常用的树的操作，比如求重心，求直径，求子树大小等
    vector<int> get_diamater() {
        // 求直径
        int n = g.size();
        vector<int> fa(n), dep(n);

        function<void(int, int, int)> dfs = [&](int u, int pre, int d) {
            fa[u] = pre;
            dep[u] = d;
            for (auto v : g[u]) {
                if (v == pre) continue;
                dfs(v, u, d + 1);
            }
        };
        dfs(0, -1, 0);
        int rt = 0;
        for (int i = 0; i < n; i++) {
            if (dep[rt] < dep[i]) {
                rt = i;
            }
        }

        dfs(rt, -1, 0);

        for (int i = 0; i < n; i++) {
            if (dep[rt] < dep[i]) {
                rt = i;
            }
        }
        vector<int> ans;
        int now = rt;
        while (now != -1) {
            ans.push_back(now);
            now = fa[now];
        }
        return ans;
    }

    // 找质心, 质心保证：将质心拿走，分裂出来的子树，每颗的大小都不会超过总个数 / 2
    // https://codeforces.com/problemset/problem/321/C : 通过质心不断的去将树分裂
    int get_centroid() {
        int n = g.size();
        vector<int> sz(n);
        vector<int> fa(n);

        function<void(int, int)> dfs = [&](int u, int pre) {
            sz[u] = 1;
            fa[u] = pre;
            for (auto v : g[u]) {
                if (v == pre) continue;
                dfs(v, u);
                sz[u] += sz[v];
            }
        };

        dfs(root, -1);
        int all = n;
        int mi = 1e9;
        int centroid = root;

        for (int i = 0; i < n; i++) {
            int mx = all - sz[i];
            for (auto v : g[i]) {
                if (v == fa[i]) continue;
                mx = max(mx, sz[v]);
            }

            if (mx < mi) {
                mi = mx;
                centroid = i;
            }
        }
        return centroid;
    }
};

template <typename Edge>
struct BipartiteGraph : Graph<Edge> {
    using Graph<Edge>::g;
    using Graph<Edge>::add_directed_edge;
    using Graph<Edge>::add_undirected_edge;
    using Graph<Edge>::size;
    int n, m;
    // 二分图的左右两边的点
    vector<int> bl, br;

    BipartiteGraph() = default;
    explicit BipartiteGraph(int n, int m) : Graph<Edge>(n + m), n(n), m(m) {
        for (int i = 0; i < n; i++) bl.push_back(i);
        for (int i = n; i < n + m; i++) br.push_back(i);
    }

    void add_edge(int u, int v) {
        add_directed_edge(Edge(u, v + n));
    }
};