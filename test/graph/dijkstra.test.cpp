#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "src/graph/dijkstra.hpp"

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "copypaste/debug.h"
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
struct MyEdge {
    int from, to;
    ll cost;

    MyEdge() = default;
    MyEdge(int from, int to, ll cost = 1) : from(from), to(to), cost(cost) {}

    // Edge e = Edge(); int to = e;
    operator int() const { return to; }
};

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Graph<MyEdge> g(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_directed_edge(MyEdge(a, b, c));
    }

    Dijkstra<Graph<MyEdge>, ll> dijkstra(g);

    dijkstra.dijkstra(s);

    if (dijkstra.dist[t] == dijkstra.inf) {
        cout << -1 << endl;
    } else {
        debug(dijkstra.dist, dijkstra.num);
        int now = t;
        vector<pii> ans;
        while (now != s) {
            int prev = dijkstra.prev[now];
            ans.emplace_back(prev, now);
            now = prev;
        }
        cout << dijkstra.dist[t] << ' ' << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for (auto [a, b] : ans) {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}