# Codeforces Round 1134 (Div. 4)：2026-11-13 赛后补验

- 学生确认 A/B/C 均为线上 AC，赛中未看题解或获取算法提示；A 只询问过编译警告。未提供提交记录、准确用时或整场排名，不补写这些数据。
- A：[2290A Three Piles](https://codeforces.com/problemset/problem/2290/A)，`attempts/attempts-1-2230.cpp`。教师用官方合法范围内全部 220 组非降序三元组穷举对照，通过。`flag:` 后紧接右花括号，标签没有标记语句；Clang 因接受 C++23 扩展而仅警告。若保留标签，在后面加一个空语句 `;` 可消除警告。算法 AC 不受此影响。
- B：[2290B Stubborn Pen](https://codeforces.com/problemset/problem/2290/B)，`attempts/attempts-2-2313.cpp`。教师穷举长度 1～8 的 510 个红蓝串并与逐字符状态模拟对照，通过。`int j < s.size()` 有有符号/无符号比较警告，非本题判错原因。
- C：[2290C Books on a Shelf](https://codeforces.com/problemset/problem/2290/C)，`attempts/attempts-3-1131.cpp`。教师对 1092 个长度不超过 6、值域 1～3 的数组和另外 100 个小随机数组穷举所有排列，核对输出多重集、可见数与最大值，均通过。源码 `vector<vector<int>>` 是 C++11 起的语法，C++03 编译失败；该场线上 AC 成立，但今后默认课程代码仍按学生画像使用 C++03 兼容写法。
- 本轮没有把 A/B/C 的成功推断为所有贪心或构造题已掌握；赛后迁移以这三道独立 AC 为正面证据，较大的 C 题尤其体现了排序、双侧构造和输出校验能力。
