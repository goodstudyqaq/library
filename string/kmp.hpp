#include <bits/stdc++.h>
using namespace std;

/*
真前缀：除了 S 本身的 S 的前缀
真后缀：除了 S 本身的 S 的后缀
https://oi-wiki.org/string/basic/
前缀函数 pi[i] = 子串 s[0...i] 最长的相等的真前缀与真后缀的长度
pi[0] = 0
*/

/*
KMP 的本质是 next 数组，next[i] 表示子串 s[0:i] 最长的相等的真前缀与真后缀的长度
*/
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

    // 计算 s 在 t 中出现的位置
    vector<int> count(const string &t) {
        kmp_pre();
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

    // 最小循环节
    // 返回最小循环节以及循环次数
    // 如果没有循环节，那么返回原串 和 1
    pair<string, int> calc_min_period() {
        kmp_pre();
        int n = s.size();
        int m = next[n];
        if (m > 0 && n % (n - m) == 0) {
            return {s.substr(0, n - m), n / (n - m)};
        } else {
            return {s, 1};
        }
    }
};