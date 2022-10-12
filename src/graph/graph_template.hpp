#pragma once
#include <bits/stdc++.h>
using namespace std;

/*
@brief Graph template
@docs docs/graph_template.md
*/

struct Edge {
    int from, to;
    int cost;

    Edge() = default;
    Edge(int from, int to, int cost = 1) : from(from), to(to), cost(cost) {}

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
};
