#include <bits/stdc++.h>

#include "src/graph/graph_template.hpp"
using namespace std;
/*
@brief 最大匹配
@docs docs/max_match.md
todo: 判断是否是二分图，如果不是二分图，需要报错
*/
template <typename T = int>
struct Hungary : Graph<T> {
    vector<int> cx, cy;
    vector<bool> used;
    int count;

    bool dfs(int u) {
        for (auto v : g[u]) {
            if (!used[v]) {
                used[v] = 1;
                if (cy[v] == -1 || dfs(cy[v])) {
                    cy[v] = u;
                    cx[u] = v;
                    return 1;
                }
            }
        }
        return 0;
    }

    void hungary() {
        // 需要保证 graph 为二分图
        int n = g.size();
        cx.resize(n);
        cy.reserve(n);
        used.resize(n);
        for (int i = 0; i < n; i++) {
            cx[i] = cy[i] = -1;
            used[i] = 0;
        }
        int res = 0;
        for (int u = 0; u < n; u++) {
            if (cx[u] == -1) {
                for (int i = 0; i < n; i++) used[i] = 0;
                if (dfs(u)) res++;
            }
        }
    }
};