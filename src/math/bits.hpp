

#include <bits/stdc++.h>
using namespace std;
/*
@brief 位运算
@docs docs/bits.md
*/
/*一些记不住的知识点*/
/*
    1. lowbit
    lowbit(x): x 的最低位 1 lowbit(100100) = 100
    lowbit(x) = x & (~x + 1)
    ~x 按位取反 ~0 = -1, ~1 = -2, ~2 = -3...
    显然 ~x + 1 = -x
    所以 lowbit(x) = x & -x

    2. __builtin_parity(x) x 有偶数个 1 返回 0，奇数个 1 返回 1
    3. __builtin_popcount(x) 返回 x 的 1 的个数
    3. __builtin_ctz(x) 此函数用于计算给定整数的尾随零
    4. __builtin_clz(x) 此函数用于计算整数的前导零。注意：clz = 计算前导零
*/
struct Subset {
    /*
    枚举 status 的全部子集
    */
    int status;
    Subset(int status) : status(status) {}
    struct Iterator {
        int i;
        int status;
        bool ok;
        Iterator(int _i, int _s, bool ok = true) : i(_i), status(_s), ok(ok) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i && ok != a.ok;
        }
        Iterator& operator++() {
            i = (i - 1) & status;
            ok = (i != status);
            return *this;
        }
    };
    Iterator begin() const {
        return Iterator(status, status, true);
    }
    Iterator end() const {
        // 作为结束条件，处理完 0 之后，会有 -1 & status = status
        return Iterator(status, status, false);
    }
};

struct NonEmptySubset {
    /*
    枚举 status 的全部非空子集
    */
    int status;
    NonEmptySubset(int status) : status(status) {}
    struct Iterator {
        int i;
        int status;
        Iterator(int _i, int _s) : i(_i), status(_s) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            i = (i - 1) & status;
            return *this;
        }
    };
    Iterator begin() const {
        return Iterator(status, status);
    }
    Iterator end() const {
        return Iterator(0, status);
    }
};

struct ProperSubset {
    /*
    枚举 status 的全部真子集
    */
    int status;
    ProperSubset(int status) : status(status) {}
    struct Iterator {
        int i;
        int status;
        Iterator(int _i, int _s) : i(_i), status(_s) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            i = (i - 1) & status;
            return *this;
        }
    };
    Iterator begin() const {
        return Iterator(status - 1, status);
    }
    Iterator end() const {
        return Iterator(status, status);
    }
};

struct NonEmptyProperSubset {
    /*
    枚举 status 的全部非空真子集
    */
    int status;
    NonEmptyProperSubset(int status) : status(status) {}
    struct Iterator {
        int i;
        int status;
        Iterator(int _i, int _s) : i(_i), status(_s) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            i = (i - 1) & status;
            return *this;
        }
    };
    Iterator begin() const {
        return Iterator(status - 1, status);
    }
    Iterator end() const {
        return Iterator(0, status);
    }
};

struct MultiSubset {
    // 求多个集合的所有非空子集的集合
    vector<bool> multi_subset(vector<int>& status) {
        int mx = *max_element(status.begin(), status.end());
        vector<bool> have(mx + 1);
        function<void(int)> f = [&](int v) {
            if (have[v]) return;
            have[v] = true;
            for (int w = v; w > 0; w &= w - 1) {
                // w 每次减去最后一个 1
                // v = 1001010 => w = 1001010, 1001000, 1000000
                f(v ^ (w & -w));
            }
        };
        for (auto v : status) {
            f(v);
        }
        return have;
    }
};

struct Superset {
    // 枚举 status 的全部超集
    int status;
    int n;
    Superset(int status, int n) : status(status), n(n) {}
    struct Iterator {
        int i;
        int status;
        int n;
        Iterator(int _i, int _s, int _n) : i(_i), status(_s), n(_n) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            i = (i + 1) | status;
            return *this;
        }
    };
    Iterator begin() const {
        return Iterator(status, status, n);
    }
    Iterator end() const {
        return Iterator(1 << n, status, n);
    }
};

struct SubsetK {
    // Gosper’s Hack：枚举大小为 n 的集合的大小为 k 的子集（按字典序）
    // https://en.wikipedia.org/wiki/Combinatorial_number_system#Applications
    // 参考《挑战程序设计竞赛》p.156-158 的实现
    // 把除法改成右移 bits.TrailingZeros 可以快好几倍
    // 比如在 n 个数中求满足某种性质的最大子集，则可以从 n 开始倒着枚举子集大小，直到找到一个符合性质的子集
    // 例题（TS1）https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/0000000000045875
    int n;
    int k;
    SubsetK(int n, int k) : n(n), k(k) {}
    struct Iterator {
        int i;
        int n;
        int k;
        Iterator(int _i, int _n, int _k) : i(_i), n(_n), k(_k) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            int lb = i & -i;
            int x = i + lb;
            i = x + ((x ^ i) >> (__builtin_ctz(lb) + 2));
        }
    };
    Iterator begin() const {
        return Iterator((1 << k) - 1, n, k);
    }
    Iterator end() const {
        return Iterator(1 << n, n, k);
    }
};

struct AllOne {
    // 枚举各个 1 位的位置
    // 每次统计尾 0 的个数，然后移除最右侧的 1
    int status;
    AllOne(int status) : status(status) {}
    struct Iterator {
        int i;
        int status;
        Iterator(int _i, int _s) : i(_i), status(_s) {}
        int operator*() const {
            return i;
        }
        bool operator!=(const Iterator& a) const {
            return i != a.i;
        }
        Iterator& operator++() {
            i &= (i - 1);
            return *this;
        }
    };
    Iterator begin() const {
        return Iterator(status, status);
    }
    Iterator end() const {
        return Iterator(0, status);
    }
};
