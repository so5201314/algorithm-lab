# Algorithm Lab

记录 C++ 算法、数据结构与数学推导练习。以自己动手实现、理解原理、验证正确性为主。

C++ algorithm and data-structure practice, including LeetCode and hand-written algorithms.

## 算法目录

- [锦标赛算法：寻找最大值与第二大值](algorithms/tournament_top_two.cpp) (`algorithms/tournament_top_two.cpp`)

## 锦标赛算法 | Tournament Top Two

**问题**：给定至少两个互不相同的整数，找出最大值与第二大值，尽量减少比较次数。

**方法**：
1. `alive` 保存当前参赛选手在原数组中的下标。
2. 两两比较，胜者进入下一轮；人数为奇数时，最后一人轮空晋级。
3. `beaten[winner]` 记录胜者直接击败过的对手下标。
4. 冠军产生后，只需在其直接击败的对手中查找第二大值。

**复杂度**：
- 最坏比较次数：`n + ceil(log2(n)) - 2`（`n >= 2`，输入值互不相同）。
- 时间复杂度：`O(n)`。
- 额外空间复杂度：`O(n)`。
- 输入少于两个元素时抛出 `std::invalid_argument`。

## 编译运行

在支持 C++17 的电脑环境下运行：

```bash
g++ -std=c++17 -Wall -Wextra -pedantic algorithms/tournament_top_two.cpp -o tournament_top_two
./tournament_top_two
```

预期输出：

```text
Maximum: 12
Second:  10
```

> 本仓库是独立的学习代码，不包含公司的 MCU 工程源码。
