#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "src/graph/lca.hpp"

#include <bits/stdc++.h>

using namespace std;

// #ifdef LOCAL
// #include "copypaste/debug.h"
// #else
// #define debug(...) 42
// #endif

#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    };
} fast_ios_;

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    Tree<Edge> tree(n);

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        tree.add_directed_edge(Edge(p, i));
    }
    Lca<Tree<Edge>> lca(tree);
    lca.build(0);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.get_lca(u, v) << endl;
    }
    return 0;
}