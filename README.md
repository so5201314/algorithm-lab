# Algorithm Lab

记录 C++ 算法、数据结构与数学推导练习。以自己动手实现、理解原理、验证正确性为主。

C++ algorithm and data-structure practice, including LeetCode and hand-written algorithms.

## 算法目录

### LeetCode

- [42. 接雨水 | Trapping Rain Water](leetcode/0042_trapping_rain_water.cpp) — 排序无关的左右双指针，时间 `O(n)`、额外空间 `O(1)`（LeetCode 提交通过）。
- [438. 找到字符串中所有字母异位词 | Find All Anagrams in a String](leetcode/0438_find_all_anagrams_in_a_string.cpp) — 26 位字符计数 + 固定长度滑动窗口，时间 `O(n)`、辅助空间 `O(1)`（已检查代码，待确认在线提交结果）。

### 独立算法

- [锦标赛算法：寻找最大值与第二大值](algorithms/tournament_top_two.cpp) (`algorithms/tournament_top_two.cpp`)

## LeetCode 438 | 找到字符串中所有字母异位词

**思路**：对目标字符串 `p` 和当前窗口分别统计 26 个小写字母的出现次数，比较两个计数数组是否相等。第一个窗口处理完后，每次右移一格：移出旧字符（计数减 1）、加入新字符（计数加 1）、记录满足条件的起始位置。

- 固定窗口长度：`p.size()`。
- 窗口起点：`left = right - p.size() + 1`。
- 时间复杂度：`O(n)`，因为比较的数组固定为 26 个元素。
- 辅助空间复杂度：`O(1)`，不计返回结果。
- **验证状态**：代码逻辑已检查；LeetCode 在线提交是否通过尚待确认。

## LeetCode 42 | 接雨水

**核心公式**：每个位置的积水量由左右最高挡板中较矮的一侧决定：

`water[i] = max(0, min(leftMax[i], rightMax[i]) - height[i])`

**学习过程**：

| 解法 | 时间 | 额外空间 |
| --- | --- | --- |
| 暴力枚举左右最高柱子 | `O(n²)` | `O(1)` |
| 预处理左右最大高度数组 | `O(n)` | `O(n)` |
| 左右双指针（归档代码） | `O(n)` | `O(1)` |

双指针从两端向中间处理当前较矮的一侧，维护 `leftMax` 和 `rightMax`，每次计算完当前位置的积水后移动对应指针。

源文件采用 LeetCode 的 `class Solution` 形式，可直接用于平台提交，不含独立 `main()`。

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

## 编译运行（锦标赛算法）

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
