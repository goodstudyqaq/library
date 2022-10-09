#include <bits/stdc++.h>
using namespace std;
/*
@brief SOSdp
@docs docs/sos_dp.md
*/
template <typename T>
struct SOSDP {
    // https://codeforces.com/blog/entry/45223
    /*
        F[mask] = \sum_{i \in mask} A[i]
        Time: O(N2^N)
    */
    vector<vector<T>> iterative_version(vector<T>& A) {
        int N = A.size();
        vector<vector<T>> dp(1 << N, vector<T>(N + 1));
        vector<T> F(1 << N);
        for (int mask = 0; mask < (1 << N); ++mask) {
            dp[mask][0] = A[mask];  // handle base case separately (leaf states)
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {
                    dp[mask][i + 1] = dp[mask][i] + dp[mask ^ (1 << i)][i];
                } else {
                    dp[mask][i + 1] = dp[mask][i];
                }
            }
            F[mask] = dp[mask][N];
        }
        return dp;
    }

    vector<vector<T>> easy_version(vector<T>& A) {
        vector<T> F(1 << N);
        // memory optimized, super easy to code.
        for (int i = 0; i < (1 << N); ++i) {
            F[i] = A[i];
        }
        for (int i = 0; i < N; ++i) {
            for (int mask = 0; mask < (1 << N); ++mask) {
                if (mask & (1 << i)) {
                    F[mask] += F[mask ^ (1 << i)];
                }
            }
        }
        return F;
    }
};
