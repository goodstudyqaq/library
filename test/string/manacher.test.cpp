#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "src/string/manacher.hpp"

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

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif
    string s;
    cin >> s;
    Manacher m(s);
    debug(m.s, m.s.size());
    debug(m.Mp, m.Mp.size());

    int n = s.size();
    for (int i = 0; i < n; i++) {
        cout << m.query(i, i) * 2 - 1 << " ";
        if (i + 1 < n) {
            cout << m.query(i, i + 1) * 2 << " ";
        }
    }
    cout << endl;
}