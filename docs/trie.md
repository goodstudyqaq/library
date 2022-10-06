# Trie

## 概要
字典树是一种树形结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。在该模板中，它分为两个部分。
### `TrieNode`
`TrieNode` 是字典树的节点，它包含了一个 `vector<int> nxt`，用于存储该节点的子节点。在使用时可以增加其他的属性，例如 `int cnt`，用于存储以该节点为结尾的单词的数量。它提供了 3 个 hook 函数。
- `void update_when_finish_in_trie()`: 当一个单词被插入到字典树中后，在该单词的最后一个字符的节点上调用该函数。
- `void update_when_push_in_trie(TrieNode &child_node)`: 当一个单词被插入到字典树的过程中，根据当前节点的子节点 `child_node` 来更新当前节点的属性。
- `void update_when_build_fail(TrieNode &fail_node)`: 当字典树被构造完成后，根据当前节点的失败指针 `fail_node` 来更新当前节点的属性。

### `Trie`
`Trie` 类是字典树的核心类，它提供了一些方法来构造字典树。
- `Trie(int char_size, int margin)`: 构造一个 `Trie` 类，用于存储字符集大小为 `char_size` 的字符串，`margin` 为字符集的起始字符。
- `void add(const string &s)`: 将字符串 `s` 插入到字典树中。

## 常见问题

## 题集