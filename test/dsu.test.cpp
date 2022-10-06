#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "src/data_structure/dsu.hpp"

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#else
#define debug(...) 42
#endif

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

    DSU dsu(n);

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            dsu.merge(u, v);
        } else {
            bool f = (dsu.leader(u) == dsu.leader(v));
            cout << f << endl;
        }
    }
    return 0;
}