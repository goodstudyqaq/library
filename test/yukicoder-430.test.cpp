#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "copypaste/debug.h"
#else
#define debug(...) 42
#endif
#include "src/data_structure/aho_corasick.hpp"

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
    int n;
    cin >> n;

    AhoCorasick aho = AhoCorasick(26, 'A');
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        aho.add(t);
    }

    aho.build();
}