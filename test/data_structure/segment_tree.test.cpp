#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "src/data_structure/segment_tree.hpp"

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

struct MyInfo {
    // 默认值
    ll sum;
    MyInfo() { sum = 0; }
    MyInfo(ll x) { sum = x; }
    static MyInfo merge(const MyInfo& left_info, const MyInfo& right_info, int l, int r) { return MyInfo(left_info.sum + right_info.sum); }
};
int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    SegmentTree<MyInfo> seg(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seg.update(i, MyInfo(a[i]));
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            seg.update(p, MyInfo(x));
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.rangeQuery(l, r - 1).sum << endl;
        }
    }
    return 0;
}