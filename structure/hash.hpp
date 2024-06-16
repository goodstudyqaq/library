#include <bits/stdc++.h>
using namespace std;
mt19937_64 mrand(random_device{}());

struct BinaryArrayHasher {
    vector<long long> h;
    BinaryArrayHasher(int n) {
        h.resize(n);
        for (int i = 0; i < n; i++) {
            h[i] = mrand();
        }
    }

    long long get_hash(vector<bool> &v) {
        assert(v.size() == h.size());
        long long res = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) res ^= h[i];
        }
        return res;
    };
};