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
    Trie(int char_size, int margin) : char_size(char_size), margin(margin) {
        root = new_node();
    }

    int new_node() {
        nodes.push_back(TrieNode(char_size));
        return nodes.size() - 1;
    }

    void add(const string &s) {
        int n = s.size();
        int now = root;
        for (int i = 0; i < n; i++) {
            const int c = s[i] - margin;
            if (nodes[now].nxt[c] == -1) {
                nodes[now].nxt[c] = new_node();
            }
            now = nodes[now].nxt[c];
        }
    }
};
