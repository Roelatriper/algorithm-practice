# 11-15 CCPC 荆州赛前能力证据图

> 截至 2026-11-14 23:26（Asia/Shanghai）。只依据仓库原稿、学生报告和教师实际验证；“教师测试通过”“线上 AC”“独立掌握”分开记。

## 相对强项

| 思想 | 当前证据 | 边界 |
|---|---|---|
| 相向双指针 | `problems/course/017-two-pointers-pair-sum/review.md`：独立实现、延迟重写和7天迁移，固定/随机对照通过，暂评9/10 | 已记掌握；新题仍须读清排序和端点含义 |
| 基础赛题与构造实现 | `problems/contests/cf-round-1134-2026-11-12-2235/review.md`：学生确认2290 A/B/C赛场独立线上AC；教师对小输入核对通过 | C的11-14闭卷复写未完成，不把赛场AC推成整个贪心/构造专题掌握 |
| 二分与数值处理的独立探索 | `problems/online-judges/luogu/P1873-tree-cut/review.md`：P1873核心排序分段算法自写，教师随机对照通过；`problems/course/017-two-pointers-pair-sum/review.md` 也体现有序结构利用 | P1873事后AI核对过，专题迁移和自主精确测试仍缺 |
| 0/1背包的计算核心 | `problems/course/025-zero-one-knapsack/review.md`：闭卷双算法重写计算经穷举对照通过 | 完整输出多一行，自主测试与变式025仍缺，不记专题掌握 |

## 当前弱点

| 思想或环节 | 证据与实际风险 |
|---|---|
| DP 状态与初值统一 | `problems/course/023-min-cost-stairs/review.md`：新稿计算通过，但独立测试预期曾把跨级路径算成逐级求和；`problems/course/033-nonadjacent-maximum/review.md`：先有 `dp[-1]` 与32位状态，第二稿双负数初值漏0；学生随后要求不复验，现有最终稿未验。 |
| 贪心正确性与排序前提 | `problems/course/022-greedy-two-person-boats/review.md`：复写初稿独乘不计数、未排序；提示后订正版教师对照通过，但独立交换论证和新题迁移未齐。 |
| 自主测试的输入、预期、输出核对 | `problems/course/029-dynamic-maximum/review.md`：首行命令数与实际条数不符、漏报一次 `Q`；`problems/course/023-min-cost-stairs/review.md`：测试预期未按最优路径计算；`problems/course/025-zero-one-knapsack/review.md`：完整程序多输出一行。 |
| 图搜索的本地边界 | `problems/online-judges/luogu/P1443-horse-traversal/review.md`：线上AC存在，但本地中心起点和单格输出仍有差异；BFS不记稳定无提示迁移。 |

## 重要空白与优先级

| 优先级 | 思想 | 依据 |
|---|---|---|
| 高 | 树与图的表示、邻接表、图遍历 | `course/STATE.md` 中树输入/建树仍有障碍；`course/CURRICULUM.md` 的015图存储尚无独立作答。Dijkstra 前应先能正确表示图和边。 |
| 高 | 并查集与单源最短路（Dijkstra） | `course/CURRICULUM.md` 的013、017尚未开始；012堆的029只是提示后订正。赛后先补013/015前置，再学017，不把今晚未授内容记为弱点。 |
| 中 | 拓扑排序与最小生成树 | `course/CURRICULUM.md` 的016、018待学，分别依赖图与并查集。 |
| 中 | 基础数论、字符串匹配与更广的DP模型 | `course/CURRICULUM.md` 的019、021及010后续模型未有足够独立迁移；现阶段优先巩固基础状态、测试与图的前置。 |

## 赛后最小交接

1. 先记录11-15比赛实际题号、提交结果、用时与是否看提示，独立赛场证据单独评估。
2. 033按学生要求赛前停止验收；赛后从保留的最终稿、双负数和64位边界继续。CF 2290C有未完成新稿，赛后如继续也保留本次真实尝试。
3. 做025最大装满变式和034区间覆盖，分别检验DP容量状态与贪心交换；再补树/图表示、并查集和Dijkstra前置。
