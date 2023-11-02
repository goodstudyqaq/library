#include <bits/stdc++.h>

#include "src/graph/graph_template.hpp"
using namespace std;
/*
@brief Tarjan
@docs docs/tarjan.md
todo: 待整理
*/

// template <typename T = int>
// struct Tarjan : Graph<T> {
//     vector<int> low, dfn, stk;
//     vector<bool> in_stk;
//     int timestamp, scc_cnt;

//     Tarjan() = default;
//     explicit Tarjan(int n) : Graph<T>(n), low(n), dfn(n), in_stk(n), timestamp(0), scc_cnt(0) {}

//     void dfs(int u) {
//         low[u] = dfn[u] = ++timestamp;
//         stk.push_back(u);
//         in_stk[u] = true;

//         int flag = 0;
//         for (auto& e : this->g[u]) {
//             int v = e.to;
//             if (!dfn[v]) {
//                 dfs(v);
//                 low[u] = min(low[u], low[v]);

//                 if (low[v] == dfn[u]) {
//                     flag++;
//                     if (u !=)
//                 }

//             } else if (in_stk[v]) {
//                 low[u] = min(low[u], dfn[v]);
//             }
//         }

//         if (low[u] == dfn[u]) {
//             scc_cnt++;
//             while (true) {
//                 int x = stk.back();
//                 stk.pop_back();
//                 in_stk[x] = false;
//                 if (x == u) {
//                     break;
//                 }
//             }
//         }
//     }

//     void solve() {
//         for (int i = 0; i < this->g.size(); i++) {
//             if (!dfn[i]) {
//                 dfs(i);
//             }
//         }
//     }
// };

//边从0到tot-1，点从1到N
//如果有重边的话，在tarjan函数自己加上判断函数即可。
//不管是有向图还是无向图，LOW数组都不能代表点所在的连通分量。
const int maxn = 1e5;
const int maxm = 1e5 + 5;
struct Edge {
    int u, v, next;
    Edge(int _u, int _v, int _nxt) : u(_u), v(_v), next(_nxt) {}
    Edge() {}
} edges[maxm * 2];
int head[maxn], tot;
void addedge(int u, int v) {
    edges[tot] = Edge(u, v, head[u]);
    head[u] = tot++;
}
int DFN[maxn], LOW[maxn], id;
int stk[maxn], tot1;
bool is_cut[maxn];
vector<vector<int>> dcc;
void tarjan(int u) {
    DFN[u] = LOW[u] = ++id;
    stk[tot1++] = u;
    int flag = 0;
    for (int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].v;
        if (!DFN[v]) {
            tarjan(v);
            LOW[u] = min(LOW[u], LOW[v]);
            if (LOW[v] == DFN[u]) {
                flag++;
                if (u != 1 || flag > 1) is_cut[u] = true;
                int t;
                dcc.push_back({});
                do {
                    t = stk[tot1 - 1];
                    tot1--;
                    dcc.back().push_back(t);
                } while (t != v);
                dcc.back().push_back(u);
            }
        } else {
            LOW[u] = min(LOW[u], DFN[v]);
        }
    }
}
void init() {
    id = 0;
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN));
    memset(LOW, 0, sizeof(LOW));
    memset(is_cut, 0, sizeof(is_cut));
    dcc.clear();
}