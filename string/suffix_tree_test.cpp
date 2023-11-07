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
    int link, start, len;
    vector<int> next;

    state() {}
    state(int _link, int _start, int _len, int char_size) : link(_link), start(_start), len(_len) {
        next.resize(char_size, 0);
    }
};

struct suffixTree {
    const int inf = 1e9;
    vector<state> st;
    int root;
    vector<int> v;

    int char_size, margin;

    suffixTree(const string &s, int _char_size, int _margin) : char_size(_char_size), margin(_margin) {
        int n = s.size();
        debug(s);
        v.resize(n + 1);
        for (int i = 0; i < n; i++) {
            v[i] = s[i] - margin;
        }
        v[n] = char_size;  // 终止符号
        char_size++;       // char_size + 1 需要额外加一个终止符号

        root = new_state(0, 0);
        build();
    }

    int new_state(int start, int len, int link = 0) {
        st.push_back(state(link, start, len, char_size));
        return st.size() - 1;
    }

    void build() {
        int rem = 0;
        int now = root;

        function<void(int)> add = [&](int n) {
            // add s[n]
            const int c = v[n];
            rem++;
            int last = root;

            while (rem) {
                while (true) {
                    int first = v[n - rem + 1];
                    int go = st[now].next[first];
                    if (go && rem > st[go].len) {
                        rem -= st[go].len;
                        now = go;
                    } else {
                        break;
                    }
                }

                int first = v[n - rem + 1];
                int &go = st[now].next[first];  // go 为引用，所以后面的 go = xxx ，实际上是修改的是 st[now].next[first] 的值
                int end = v[st[go].start + rem - 1];
                if (!go || end == c) {
                    st[last].link = now;
                    last = now;
                    if (!go) {
                        go = new_state(n, inf);  // 为什么这里 start = n 呢 ？ 因为如果根本没有 go 这个点，此时 rem 必然为 1，那么 start = n - rem + 1 = n。
                    } else {
                        break;  // 无法加入，直接 break
                    }
                } else {
                    // 需要裂变
                    int u = new_state(st[go].start, rem - 1);
                    st[u].next[end] = go;
                    st[u].next[c] = new_state(n, inf);
                    st[go].start += rem - 1;
                    st[go].len -= rem - 1;
                    st[last].link = u;
                    go = u;
                    last = u;
                }
                if (now == 0)
                    rem--;
                else
                    now = st[now].link;
            }
        };

        for (int i = 0; i < v.size(); i++) {
            add(i);
        }

        // for (int i = 0; i < st.size(); i++) {
        //     debug(i, st[i].len, st[i].link, st[i].start);
        //     for (int j = 0; j < st[i].next.size(); j++) {
        //         if (st[i].next[j] != 0) {
        //             cout << st[i].next[j] << ' ';
        //         }
        //     }
        //     cout << endl;
        // }
    }

    long long work() {
        vector<int> num(st.size());

        function<void(int)> dfs = [&](int u) {
            bool flag = true;
            for (int i = 0; i < char_size; i++) {
                if (st[u].next[i]) {
                    flag = false;
                    dfs(st[u].next[i]);
                    num[u] += num[st[u].next[i]];
                }
            }
            if (flag) {
                num[u] = 1;
            }
        };
        dfs(0);

        long long ans = 0;
        function<void(int, int)> dfs2 = [&](int u, int dep) {
            if (num[u] > 1) {
                ans = max(ans, 1LL * num[u] * (dep + st[u].len));
            }

            for (int i = 0; i < char_size; i++) {
                if (st[u].next[i]) {
                    dfs2(st[u].next[i], dep + st[u].len);
                }
            }
        };
        dfs2(0, 0);
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif
    string s;
    cin >> s;
    suffixTree st(s, 26, 'a');

    cout << st.work() << endl;
}