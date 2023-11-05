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

struct SAM {
    vector<state> st;
    int last;

    int char_size, margin;

    int new_state(int len, int link = -1) {
        st.push_back(state(len, link, char_size));
        return st.size() - 1;
    }

    SAM(int _char_size, int _margin) : char_size(_char_size), margin(_margin) {
        last = new_state(0, -1);
    }

    void sam_extend(char it) {
        const int c = it - margin;
        int cur = new_state(st[last].len + 1, -1);

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
};
