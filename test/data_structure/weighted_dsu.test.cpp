#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include "src/data_structure/weighted_dsu.hpp"

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

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    WeightedDSU<int> dsu(n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, z;
            // ay = ax + z
            cin >> x >> y >> z;
            dsu.merge(x, y, z);
        } else {
            int x, y;
            cin >> x >> y;

            if (dsu.leader(x).first != dsu.leader(y).first) {
                cout << "?" << endl;
            } else {
                // ay - ax
                cout << dsu.leader(x).second - dsu.leader(y).second << endl;
            }
        }
    }
    return 0;
}