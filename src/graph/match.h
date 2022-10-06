#include <bits/stdc++.h>

#include "src/graph/graph_template.hpp"
using namespace std;
/*
@brief 最大匹配
@docs docs/match.md
todo: 待整理
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

    Hungary() {}
    Hungary(int uN, int vN, vector<vector<int>> &_g) {
        g = _g;
        cx.resize(uN, -1);
        cy.resize(vN, -1);
        used.resize(vN, 0);
        int res = 0;
        for (int u = 0; u < uN; u++) {
            used.assign(vN, 0);
            if (dfs(u)) res++;
        }
        count = res;
    }
};