#include <bits/stdc++.h>

#include "./string/trie.hpp"
using namespace std;

/*
@brief AC 自动机
@docs docs/aho_corasick.md
*/

struct AhoCorasick : Trie {
    vector<int> fail;

    AhoCorasick(int char_size, int margin) : Trie(char_size, margin) {
        fail.clear();
    }

    void build() {
        /*
         * build fail 函数
         */
        queue<int> Q;
        fail.resize(nodes.size());
        fail[root] = root;

        for (int i = 0; i < this->char_size; i++) {
            if (nodes[root].nxt[i] == -1) {
                nodes[root].nxt[i] = root;
            } else {
                fail[nodes[root].nxt[i]] = root;
                Q.push(nodes[root].nxt[i]);
            }
        }

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            for (int i = 0; i < char_size; i++) {
                if (nodes[node].nxt[i] == -1) {
                    nodes[node].nxt[i] = nodes[fail[node]].nxt[i];
                } else {
                    fail[nodes[node].nxt[i]] = nodes[fail[node]].nxt[i];
                    Q.push(nodes[node].nxt[i]);
                }
            }
        }
    }
};