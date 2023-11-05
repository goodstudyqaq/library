#include <bits/stdc++.h>
using namespace std;

struct state {
    int len, link;
    vector<int> next;

    state() {}
    state(int _len, int _link, int char_size) : len(_len), link(_link) {
        next.resize(char_size, 0);
    }
};

struct GSAM {
    vector<state> st;
    int char_size, margin;
    int root;
    int new_state(int len = 0, int link = -1) {
        st.push_back(state(len, link, char_size));
        return st.size() - 1;
    }

    GSAM(int _char_size, int _margin) : char_size(_char_size), margin(_margin) {
        root = new_state();
    }

    void add(const string &s) {
        int n = s.size();
        int now = root;
        for (int i = 0; i < n; i++) {
            const int c = s[i] - margin;
            if (st[now].next[c] == 0) {
                st[now].next[c] = new_state();
            }
            now = st[now].next[c];
        }
    }

    int extend(int last, int c) {
        int cur = st[last].next[c];

        int v = st[last].link;  // 1. 先跳一步，因为 last 的 next 已经是 cur 了

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
                for (int i = 0; i < char_size; i++) {
                    st[y].next[i] = st[st[x].next[i]].len != 0 ? st[x].next[i] : 0;  // 2. 只复制已经遍历到的点，因为如果不这样的话，在 44 行可能会中途 break，break 之后又因为 len = 0，就会有问题。而不复制的话，之后它的 link 链会跳到 y，然后在 45 行重新赋值上去，没有影响。(感觉这样理解是对的)
                }
                st[y].link = st[x].link;
                while (v != -1 && st[v].next[c] == x) {
                    st[v].next[c] = y;
                    v = st[v].link;
                }
                st[x].link = st[cur].link = y;
            }
        }
        return cur;
    }

    void build() {
        queue<pair<int, int>> Q;

        for (int i = 0; i < char_size; i++) {
            if (st[root].next[i]) Q.push({i, root});
        }

        while (!Q.empty()) {
            auto [c, node] = Q.front();
            Q.pop();

            int last = extend(node, c);

            for (int i = 0; i < char_size; i++) {
                if (st[last].next[i]) {
                    Q.push({i, last});
                }
            }
        }
    }
};