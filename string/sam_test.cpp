// https://www.luogu.com.cn/problem/P3804
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "copypaste/debug.h"
#else
#define debug(...) 42
#endif

#define endl '\n'

struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    };
} fast_ios_;
struct state {
    int len, link;
    vector<int> next;
    int cnt;

    state() {}
    state(int _len, int _link, int char_size) : len(_len), link(_link) {
        next.resize(char_size, 0);
        cnt = 0;
    }
};

struct SAM {
    vector<state> st;
    int last;

    int char_size, margin;

    int new_state(int len, int link) {
        st.push_back(state(len, link, char_size));
        return st.size() - 1;
    }

    SAM(int _char_size, int _margin) : char_size(_char_size), margin(_margin) {
        last = new_state(0, -1);
    }

    void sam_extend(char it) {
        const int c = it - margin;
        int cur = new_state(st[last].len + 1, -1);
        st[cur].cnt = 1;

        int v = last;

        while (v != -1 && st[v].next[c] == 0) {
            st[v].next[c] = cur;
            v = st[v].link;
        }

        if (v == -1) {
            st[cur].link = 0;
        } else {
            int x = st[v].next[c];
            if (st[v].len + 1 == st[x].len) {
                st[cur].link = x;
            } else {
                int y = new_state(st[v].len + 1, -1);
                st[y].next = st[x].next;
                st[y].link = st[x].link;
                while (v != -1 && st[v].next[c] == x) {
                    st[v].next[c] = y;
                    v = st[v].link;
                }
                st[x].link = st[cur].link = y;
            }
        }
        last = cur;
    }

    long long work() {
        int mx_len = 0;
        for (int i = 0; i < st.size(); i++) {
            mx_len = max(mx_len, st[i].len);
        }

        vector<int> h(mx_len + 1);
        for (int i = 0; i < st.size(); i++) {
            h[st[i].len]++;
        }
        for (int i = 1; i <= mx_len; i++) h[i] += h[i - 1];
        vector<int> rk(st.size() + 1);

        for (int i = 0; i < st.size(); i++) {
            rk[h[st[i].len]--] = i;
        }

        long long ans = 0;
        for (int i = st.size(); i > 1; i--) {
            int idx = rk[i];
            int fa = st[idx].link;
            st[fa].cnt += st[idx].cnt;
            if (st[idx].cnt > 1) {
                ans = max(ans, 1LL * st[idx].cnt * st[idx].len);
            }
        }
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif

    string s;
    cin >> s;

    SAM sam(26, 'a');

    for (int i = 0; i < s.size(); i++) {
        sam.sam_extend(s[i]);
    }

    cout << sam.work() << endl;
}