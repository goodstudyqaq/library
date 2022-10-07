# Hash pair

## 概要
主要是用于`std::unordered_map`的`hash`函数，用于计算`std::pair`的`hash`值。
```cpp
int main() {
    std::unordered_map<std::pair<int, int>, pair_hash> mp;
    mp[std::make_pair(1, 2)] = 3;
    std::cout << mp[std::make_pair(1, 2)] << std::endl;

    std::unordered_set<std::pair<int, int>, pair_hash> st;
    st.insert(std::make_pair(1, 2));
    std::cout << st.count(std::make_pair(1, 2)) << std::endl;

}
```


## 常见问题

## 题集