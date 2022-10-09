#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>

#include "src/data_structure/lazy_segment_tree.hpp"

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
const int mod = 998244353;

struct MyTag {
    int a, c;
    MyTag() {
        a = 1;
        c = 0;
    }
    MyTag(int a, int c) : a(a), c(c) {}
    // apply 之前需要判断 v 是否为默认值
    void apply(const MyTag &v, int l, int r) {
        a = 1LL * a * v.a % mod;
        c = (1LL * c * v.a % mod + v.c) % mod;
    }
};

struct MyInfo {
    int sum;
    MyInfo() {
        sum = 0;
    }
    MyInfo(int sum) : sum(sum) {}
    // apply 之前需要判断 v 是否为默认值
    // [l, r]
    void apply(const MyTag &v, int l, int r) {
        sum = (1LL * sum * v.a % mod + 1LL * (r - l + 1) * v.c % mod) % mod;
    }

    static MyInfo merge(const MyInfo &left_info, const MyInfo &right_info, int l, int r) {
        return MyInfo((left_info.sum + right_info.sum) % mod);
    }
};

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    LazySegmentTree<MyInfo, MyTag> seg(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        seg.update(i, MyInfo(a));
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.rangeUpdate(l, r - 1, MyTag(b, c));
        } else {
            int l, r;
            cin >> l >> r;
            debug(l, r);
            int res = seg.rangeQuery(l, r - 1).sum;
            cout << res << endl;
        }
    }
    return 0;
}