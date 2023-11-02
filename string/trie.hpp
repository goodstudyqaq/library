#include <bits/stdc++.h>

using namespace std;

/*
@brief Trie
@docs docs/trie.md
*/

struct TrieNode {
    vector<int> nxt;
    TrieNode(int char_size) {
        nxt.resize(char_size, -1);
    }
};

struct Trie {
   public:
    vector<TrieNode> nodes;
    int root;
    int char_size;
    int margin;
    Trie(int char_size, int margin) : root(0), char_size(char_size), margin(margin) {
        nodes.push_back(TrieNode(char_size));
    }

    void add(const string &s, int s_idx, int node_idx) {
        if (s_idx == s.size()) {
            return;
        } else {
            const int c = s[s_idx] - margin;
            if (nodes[node_idx].nxt[c] == -1) {
                nodes[node_idx].nxt[c] = nodes.size();
                nodes.push_back(TrieNode(char_size));
            }
            add(s, s_idx + 1, nodes[node_idx].nxt[c]);
        }
    }

    void add(const string &s) {
        add(s, 0, root);
    }
};
