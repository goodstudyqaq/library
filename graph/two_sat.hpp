#include <bits/stdc++.h>

#include "graph/graph_template.hpp"
/*
@brief two-sat
@docs docs/two_sat.md
*/
template <typename T = Edge<int>>
struct TwoSat : Graph<T> {
    using Graph<T>::add_directed_edge;
    using Graph<T>::add_undirected_edge;
    using Graph<T>::g;

    // [0, 2 * n]
    int n;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), ans(n), Graph<T>(2 * n) {}
    void addClause(int u, bool f, int v, bool g) {
        // (u, f) 和 (v, g) 有矛盾
        add_directed_edge(2 * u + !f, 2 * v + g);
        add_directed_edge(2 * v + !g, 2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : g[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i)
            if (dfn[i] == -1) tarjan(i);

        /*
            方案可以通过变量在图中的拓扑序确定该变量的值，如果变量 !x 的拓扑序在 x 之后，那么 x 为真.
            应用到 tarjan 当中，即 x 的 SCC 编号在 !x 之前，取 x 为真。因为 tarjan 用到了栈，所以 tarjan 求出的 SCC 编号相当于反拓扑序。
        */

        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};