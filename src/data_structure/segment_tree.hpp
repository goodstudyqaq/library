#include <bits/stdc++.h>
using namespace std;
/*
@brief 线段树
@docs docs/segment_tree.md
*/
struct Info {
    int l, r;
    Info(int l = -1, int r = -1) : l(l), r(r) {}
    friend Info operator+(const Info& a, const Info& b) {}
};

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
struct SegmentTree {
    SegmentTree(int n) : n(n), info(4 << __lg(n)) {}
    SegmentTree(vector<Info> init) : SegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int l, int r, int rt) {
            if (l == r) {
                info[rt] = init[l];
                info[rt].l = l;
                info[rt].r = r;
                return;
            }
            int m = l + r >> 1;
            build(lson);
            build(rson);
            push_up(rt, l, r);
        };
        build(0, n - 1, 1);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(l, r, 0, n - 1, 1);
    }

    void update(int L, Info v) {
        return update(L, v, 0, n - 1, 1);
    }

   private:
    const int n;
    vector<Info> info;
    void push_up(int rt, int l, int r) {
        info[rt] = info[rt << 1] + info[rt << 1 | 1];
        info[rt].l = l;
        info[rt].r = r;
    }

    Info rangeQuery(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return info[rt];
        }
        int m = l + r >> 1;
        if (L <= m && R > m) {
            return rangeQuery(L, R, lson) + rangeQuery(L, R, rson);
        } else if (L <= m) {
            return rangeQuery(L, R, lson);
        } else {
            return rangeQuery(L, R, rson);
        }
    }

    void update(int L, Info& v, int l, int r, int rt) {
        if (l == r) {
            info[rt] = info[rt] + v;
            info[rt].l = l;
            info[rt].r = r;
            return;
        }
        int m = l + r >> 1;
        if (L <= m) {
            update(L, v, lson);
        } else {
            update(L, v, rson);
        }
        push_up(rt, l, r);
    }
};
