#include <bits/stdc++.h>
using namespace std;

long long get_small_palindrome(long long val) {
    // 返回小于等于 val 的最大的回文数
    // debug(val);
    if (val < 10) return val;
    vector<int> v;
    long long val2 = val;
    while (val2) {
        v.push_back(val2 % 10);
        val2 /= 10;
    }
    reverse(v.begin(), v.end());
    if (v[0] == 1) {
        // 1000000
        bool flag = true;
        for (int j = 1; j < v.size(); j++) {
            if (v[j] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return val - 1;
        }
    }
    int n = v.size();
    for (int i = n / 2; i < n; i++) {
        v[i] = v[n - 1 - i];
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = res * 10 + v[i];
    }
    if (res <= val) return res;

    if (v[n / 2] != 0) {
        v[n / 2]--;
        if (n % 2 == 0) {
            v[n / 2 - 1]--;
        }
        res = 0;
        for (int i = 0; i < n; i++) {
            res = res * 10 + v[i];
        }
        return res;
    } else {
        int now = n / 2;
        if (n % 2 == 0) now--;
        while (v[now] == 0) now--;
        v[now]--;
        for (int i = now + 1; i < n / 2; i++) {
            v[i] = 9;
        }
        for (int i = n / 2; i < n; i++) {
            v[i] = v[n - 1 - i];
        }
        res = 0;
        for (int i = 0; i < n; i++) {
            res = res * 10 + v[i];
        }
        return res;
    }
}