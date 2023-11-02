// https://www.luogu.com.cn/problem/P3375
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

struct KMP {
    string s;
    vector<int> next;
    KMP(const string &_s) {
        s = _s;
    }

    void kmp_pre() {
        int m = s.size();
        next.resize(m + 1);
        next[0] = -1;
        for (int i = 1; i <= m; i++) {
            int j = next[i - 1];
            while (j != -1 && s[i - 1] != s[j]) j = next[j];
            next[i] = j + 1;
        }
    }

    void fast_kmp_pre() {
        // 想想什么时候需要用到 next[i], 进行匹配时，到 s[i] 时失配，那么这时我们需要跳到 next[i].
        int m = s.size();
        next.resize(m + 1);
        int j = -1;
        next[0] = -1;
        for (int i = 1; i <= m; i++) {
            while (j != -1 && s[i - 1] != s[j]) j = next[j];
            j++;
            if (i < m && s[i] == s[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        }
    }

    // 计算 s 在 t 中出现的次数, 需要先调用 kmp_pre 函数
    vector<int> count(const string &t) {
        int m = s.size();
        int n = t.size();
        vector<int> ans;
        int now = 0;
        for (int i = 0; i < n; i++) {
            while (now != -1 && t[i] != s[now]) {
                now = next[now];
            }
            now++;
            // t[0:i+1] 的后缀和 s 的前缀的最长相等长度为 now
            if (now == m) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("./data.in", "r", stdin);
#endif
    string s, t;
    cin >> t >> s;

    KMP kmp(s);
    kmp.kmp_pre();
    vector<int> ans = kmp.count(t);
    for (auto it : ans) {
        cout << it + 1 << endl;
    }
    for (int i = 1; i <= s.size(); i++) {
        cout << kmp.next[i] << ' ';
    }
    cout << endl;
}