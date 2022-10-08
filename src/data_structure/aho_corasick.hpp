#include <bits/stdc++.h>

#include "./src/string/trie.hpp"
using namespace std;

/*
@brief AC 自动机
@docs docs/aho_corasick.md
*/

template <typename T = TrieNode>
struct AhoCorasick : Trie<T> {
    vector<int> fail;

    AhoCorasick(int char_size, int margin) : Trie<T>(char_size, margin) {
        fail.clear();
    }

    void build() {
        /*
         * build fail 函数
         */
        queue<int> Q;
        fail.resize(this->nodes.size());
        int root = this->root;
        fail[root] = root;

        for (int i = 0; i < char_size; i++) {
            if (this->nodes[root].nxt[i] == -1) {
                this->nodes[root].nxt[i] = root;
            } else {
                fail[this->nodes[root].nxt[i]] = root;
                Q.push(this->nodes[root].nxt[i]);
            }
        }

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            // 根据 fail 节点更新当前节点
            this->nodes[node].update_when_build_fail(nodes[fail[node]]);

            for (int i = 0; i < char_size; i++) {
                if (this->nodes[node].nxt[i] == -1) {
                    this->nodes[node].nxt[i] = this->nodes[fail[node]].nxt[i];
                } else {
                    fail[this->nodes[node].nxt[i]] = this->nodes[fail[node]].nxt[i];
                    Q.push(this->nodes[node].nxt[i]);
                }
            }
        }
    }
};