#include <bits/stdc++.h>
using namespace std;

// 最小表示法
// O(n)
// https://oi-wiki.org/string/minimal-string/
string small_representation(const string &s) {
    int k = 0, i = 0, j = 1;
    int n = s.size();
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) {
            k++;
        } else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    int idx = min(i, j);
    return s.substr(i, n - i) + s.substr(0, i);
}