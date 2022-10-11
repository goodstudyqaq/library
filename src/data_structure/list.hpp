#include <bits/stdc++.h>
using namespace std;

/*
@brief 链表
@docs docs/list.md
*/

struct Node {
    int next, last;
    Node() { next = last = -1; }
};

template <typename Node>
struct List {
    vector<Node> nodes;
    Node ed;
    int init() {
        nodes.clear();
        ed = Node();
        nodes.emplace_back(ed);
        return nodes.size() - 1;
    }

    void link(int a, int b) {
        nodes[a].next = b;
        nodes[b].last = a;
    }

    int new_node(int idx, Node it) {
        nodes.emplace_back(it);
        int sz = nodes.size() - 1;
        int last = nodes[idx].last;
        if (last != -1) {
            link(last, sz);
        }
        link(sz, idx);
        return sz;
    }

    int erase_node(int idx) {
        int last = nodes[idx].last, next = nodes[idx].next;

        if (last != -1) {
            nodes[last].next = -1;
        }
        if (next != -1) {
            nodes[next].last = -1;
        }

        if (last != -1 && next != -1) {
            link(last, next);
        }
        return last;
    }
};
