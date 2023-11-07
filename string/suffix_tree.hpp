#include <bits/stdc++.h>
using namespace std;
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
    }
};