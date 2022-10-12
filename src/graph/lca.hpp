#include <bits/stdc++.h>

#include "src/graph/graph_template.hpp"
using namespace std;
/*
@brief LCA
@docs docs/lca.md
*/
template <typename Tree>
struct Lca {
    Lca(Tree &tree) : tree(tree), root(tree.root) {}
    int get_lca(int x, int y) {
        if (dep[x] > dep[y]) swap(x, y);
        for (int j = LOG - 1; j >= 0 && dep[x] != dep[y]; j--) {
            if (dep[y] - (1 << j) < dep[x]) continue;
            y = parent[y][j];
        }
        if (x == y) return x;
        for (int j = LOG - 1; j >= 0; j--) {
            if (dep[x] - (1 << j) < 0 || parent[x][j] == parent[y][j]) continue;
            x = parent[x][j], y = parent[y][j];
        }
        return parent[x][0];
    }

    void build(int rt = -1) {
        int n = tree.size();
        // 2^k <= n

        if (rt != -1) root = rt;
        assert(root != -1);

        LOG = lg2(n) + 1;
        dep.resize(n);
        parent.resize(n, vector<int>(LOG, -1));
        dfs(root, -1, 0);
        rmq(n);
    }

   private:
    vector<int> dep;
    vector<vector<int>> parent;
    Tree &tree;
    int root;
    int LOG;
    int lg2(long long x) { return sizeof(long long) * 8 - 1 - __builtin_clzll(x); }
    void dfs(int u, int pre, int d) {
        parent[u][0] = pre;
        dep[u] = d;
        for (auto v : tree[u]) {
            if (v == pre) continue;
            dfs(v, u, d + 1);
        }
    }
    void rmq(int n) {
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                if ((1 << i) > dep[j]) continue;
                int k = parent[j][i - 1];
                parent[j][i] = parent[k][i - 1];
            }
        }
    }
};