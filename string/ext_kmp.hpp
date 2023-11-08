#include <bits/stdc++.h>
using namespace std;

// z[i] 表示 s 和 s[i, n - 1](即以 s[i] 开头的后缀) 的最长公共前缀(LCP) 的长度
// O(n)
vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}