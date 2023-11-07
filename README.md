# Gstnt's library

## 算法目录

- 集合论与位运算
- 数据结构
  - 单调栈
  - 单调队列
    - 二维单调队列
  - 双端队列
  - 堆（优先队列）
    - 支持修改、删除指定元素
  - 并查集
    - 点权
    - 边权（种类）
    - 持久化
    - 回滚操作（动态图连通性）
  - 稀疏表（ST 表）
  - 树状数组
    - 差分树状数组（支持区间加、区间求和）
  - 线段树
    - 延迟标记（懒标记）
    - 动态开点
    - 线段树合并
    - 线段树分裂
    - 持久化（主席树）
  - 0-1 线段树
  - 左偏树（可并堆）
  - 笛卡尔树
  - 二叉搜索树公共方法
  - Treap
  - 伸展树
  - 动态树 LCT
  - 红黑树
  - 替罪羊树
  - k-d 树
  - 珂朵莉树（ODT）
    - 数组版
    - 平衡树版
  - 根号分治、分块
  - 莫队算法
    - 普通莫队
    - 带修莫队
    - 回滚莫队
    - 树上莫队
- 字符串
  - [标准库](./string/stl.hpp)
  - [字符串哈希](./string/hash.hpp)
  - [KMP](./string/kmp.hpp)
    - [最小循环节](./string/kmp.hpp#L73)
  - [扩展 KMP (Z algorithm)](./string/ext_kmp.hpp)
  - [最小表示法](./string/smallest_representation.hpp)
  - [最长回文子串 Manacher 算法](./string/manacher.hpp)
  - [后缀数组(SA)](./string/sa.hpp)
  - [后缀自动机](./string/sam.hpp)
  - [广义后缀自动机](./string/general_sam.hpp)
  - [后缀树](./string/suffix_tree.hpp)
  - 后缀平衡树
  - 回文树
  - [字典树](./string/trie.hpp)
    - 持久化
    - [AC 自动机](./string/aho_corasick.hpp)
  - 异或字典树
    - 持久化
    - Hack：构造一组数据，最大化树上的节点数
- 数学
  - 数论
    - 辗转相除法（最大公因数 GCD）
    - 类欧几里得算法 ∑⌊(ai+b)/m⌋
    - Pollard-Rho 质因数分解算法
    - 埃氏筛（埃拉托斯特尼筛法）
    - 欧拉筛（线性筛）
    - 欧拉函数
    - 原根
    - 扩展 GCD
      - 二元一次不定方程
    - 逆元
      - 线性求逆元
    - 中国剩余定理（CRT）
      - 扩展中国剩余定理
    - 离散对数
    - 大步小步算法（BSGS）
      - 扩展大步小步算法
    - 二次剩余
    - Jacobi 符号
    - N 次剩余
    - 卢卡斯定理
      - 扩展卢卡斯定理
    - 卡特兰数
    - 默慈金数
    - 那罗延数
    - 斯特林数
      - 第一类斯特林数（轮换）
      - 第二类斯特林数（子集）
    - 贝尔数
    - 欧拉数
    - 莫比乌斯函数
    - 数论分块
    - 杜教筛
  - 组合数学
    - 常见模型
    - 常用恒等式
    - 容斥原理
  - 快速傅里叶变换 FFT
  - 快速数论变换 NTT
    - 包含多项式全家桶（求逆、开方等等）
  - 快速沃尔什变换 FWT
  - 连分数、佩尔方程
  - 线性代数
    - 矩阵相关运算
    - 高斯消元
    - 行列式
    - 线性基
  - 数值分析
    - 自适应辛普森积分
    - 拉格朗日插值
  - 计算几何
    - 线与点
    - 线与线
    - 圆与点
      - 最小圆覆盖
        - 随机增量法
      - 固定半径覆盖最多点
    - 圆与线
    - 圆与圆
    - 圆与矩形
    - 最近点对
    - 多边形与点
      - 判断点在凸多边形内 O(log n)
      - 判断点在任意多边形内
        - 转角法（统计绕数）
    - 凸包
    - 最远点对
      - 旋转卡壳
    - 半平面交
  - 博弈论
    - SG 函数
- 动态规划
  - 背包
    - 0-1 背包
    - 完全背包
    - 多重背包
      - 二进制优化
      - 单调队列优化
    - 分组背包
    - 树上背包（依赖背包）
    - 字典序最小方案
  - 线性 DP
    - 最大子段和
    - LCS
    - LPS
    - LIS
      - 狄尔沃斯定理
    - LCIS
    - 长度为 m 的 LIS 个数
    - 本质不同子序列个数
  - 区间 DP
  - 环形 DP
  - 状压 DP
    - 旅行商问题（TSP）
    - 高维前缀和（SOS DP）
    - 插头 DP
  - 数位 DP
  - 倍增优化 DP
  - 斜率优化 DP（CHT）
  - 树形 DP
    - 树的直径个数
    - 在任一直径上的节点个数
    - 树上最大独立集
    - 树上最小顶点覆盖
    - 树上最小支配集
    - 树上最大匹配
    - 换根 DP（二次扫描法）
- 图论
  - 链式前向星
  - 欧拉回路和欧拉路径
    - 无向图
    - 有向图
  - 割点
  - 割边（桥）
  - 双连通分量（BCC）
    - v-BCC
    - e-BCC
  - 最短路
    - Dijkstra
    - SPFA（队列优化的 Bellman-Ford）
      - 差分约束系统
    - Floyd-Warshall
    - Johnson
    - 0-1 BFS（双端队列 BFS）
    - 字典序最小最短路
    - 同余最短路
  - 最小环
  - 最小生成树（MST）
    - Kruskal
    - Prim
  - 单度限制最小生成树
  - 次小生成树
  - 曼哈顿距离最小生成树
  - 最小差值生成树
  - 最小树形图
    - 朱刘算法
  - 二分图判定（染色）
  - 二分图找奇环
  - 二分图最大匹配
    - 匈牙利算法
  - 带权二分图最大完美匹配
    - Kuhn–Munkres 算法
  - 拓扑排序
  - 强连通分量（SCC）
    - Kosaraju
    - Tarjan
  - 2-SAT
  - 基环树
  - 最大流
    - Dinic
    - ISAP
    - HLPP
  - 最小费用最大流
    - SPFA
    - Dijkstra
  - 三元环计数
  - 四元环计数
  - 仙人掌
  - 树上问题
    - 直径
    - 重心
      - 点分治
    - 最近公共祖先（LCA）
      - 倍增
      - ST 表
      - Tarjan
      - 树上差分
    - 重链剖分（HLD）
    - 长链剖分
    - 树上启发式合并（DSU）
    - 树分块
    - Prufer 序列
- 其他
  - 位运算笔记
    - bitset
    - 区间位运算 trick（含 GCD）
  - 二分 三分
    - 0-1 分数规划
    - 整体二分
  - 搜索
    - 枚举排列
    - 枚举组合
    - 生成下一个排列
    - 康托展开
    - 逆康托展开
    - 枚举子集
      - Gosper's Hack
    - 折半枚举（Meet in the middle）
      - 超大背包问题
  - 随机算法
    - 模拟退火
  - 杂项 A
    - 算法思路整理
    - 前缀和
    - 二维前缀和
    - 二维差分
    - 离散化
  - 杂项 B
- 快速输入输出模板
