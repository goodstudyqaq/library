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

struct Node : TrieNode {
    int cnt;
    Node(int char_size) : TrieNode(char_size), cnt(0) {}

    void update_when_finish_in_trie() { cnt++; }

    void update_when_build_fail(const Node &fail) { cnt += fail.cnt; }
};

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif

    string s;
    cin >> s;
    int n;
    cin >> n;

    AhoCorasick<Node> aho = AhoCorasick<Node>(26, 'A');
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        aho.add(t);
    }

    aho.build();

    int res = 0;

    Node rt = aho.nodes[aho.root];

    for (int i = 0; i < s.size(); i++) {
        rt = aho.nodes[rt.nxt[s[i] - 'A']];
        res += rt.cnt;
    }
    cout << res << endl;
    return 0;
}