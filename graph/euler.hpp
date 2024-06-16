#include <bits/stdc++.h>

#include "data_structure/dsu.hpp"
#include "graph/graph_template.hpp"
using namespace std;

/*
欧拉回路：通过图中每条边恰好一次的回路
欧拉通路：通过图中每条边恰好一次的通路
欧拉图：具有欧拉回路的图
半欧拉图：具有欧拉通路但不具有欧拉回路的图

# 性质
欧拉图中所有顶点的度数都是偶数。

若 G 是欧拉图，则它为若干个环的并，且每条边被包含在奇数个环内。


无向图是欧拉图当且仅当：
非零度顶点是连通的
顶点的度数都是偶数

无向图是半欧拉图当且仅当：
非零度顶点是连通的
恰有 2 个奇度顶点

有向图是欧拉图当且仅当：
非零度顶点是强连通的
每个顶点的入度和出度相等

有向图是半欧拉图当且仅当：
非零度顶点是弱连通的
至多一个顶点的出度与入度之差为 1
至多一个顶点的入度与出度之差为 1
其他顶点的入度和出度相等


完全图欧拉路：
如果节点个数 n 是奇数，那么 n 个点每个点都有 n - 1 个边，它可以构造成欧拉图，它的路径长度为 n * (n - 1) / 2
如果节点个数 n 是偶数，那么 n 个点每个点都有 n - 1 个边，它可以构造成半欧拉图，即有欧拉通路，但是我们得将除了 1 和 2 的点都删一条边，使得它们的边个数都是偶数，即删掉 3-4，5-6，7-8 。。。 它的路径长度为 n * (n - 1) / 2 - (n - 2) / 2
https://codeforces.com/contest/1981/problem/D
*/

struct edge {
    int to;
    bool exists;
    int revref;

    bool operator<(const edge& b) const { return to < b.to; }
};

const int maxn = 2e3 + 5;
vector<edge> beg[maxn];
int cnt[maxn];

vector<int> ans;

void Hierholzer(int x, int d) {  // 关键函数
    for (int& i = cnt[x]; i < (int)beg[x].size();) {
        if (beg[x][i].exists) {
            edge e = beg[x][i];
            beg[x][i].exists = 0;
            beg[e.to][e.revref].exists = 0;
            ++i;
            Hierholzer(e.to, d + 1);
        } else {
            ++i;
        }
    }
    ans.push_back(x);
}

void add_edge(int u, int v) {
    int sz1 = beg[u].size();
    int sz2 = beg[v].size();
    if (u != v) {
        beg[u].push_back(edge{v, 1, sz2});
        beg[v].push_back(edge{u, 1, sz1});
    } else {
        // 自环
        beg[u].push_back(edge{v, 1, sz2});
    }
}
