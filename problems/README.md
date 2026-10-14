# 题目与作答索引

`problems/` 保存题目、学生真实作答、订正和验证证据，不等于“当前待做题单”。当前任务始终以 [`../course/STATE.md`](../course/STATE.md) 为准。

## 三个稳定分区

| 目录 | 职责 | 是否自动进入课程 |
|---|---|---|
| [`course/`](course/) | Tutor 按课程顺序布置的训练、重写和迁移题 | 是，由 `STATE.md` 指定当前题 |
| [`online-judges/`](online-judges/) | 洛谷等在线题库中的独立作答 | 否，按课程需要选取 |
| [`contests/`](contests/) | 整场比赛或校队往届题的题面归档 | 否，只作诊断、模拟或后续选题 |

## 单题目录约定

```text
problem-name/
├── statement.md   # 题面；没有本地题面时可省略
├── attempt.cpp    # 首次或基线真实作答
├── solution.cpp   # 学生订正终版或明确标注的参考实现
├── review.md      # 当前结论、错误证据、提示等级和复查计划
├── attempts/      # 有独立意义的时间戳作答快照
├── tests/         # 学生测试与验证记录
├── solutions/     # 需要保留的阶段性订正版
└── variants/      # 同模型迁移题
```

不是每题都必须拥有全部文件或子目录。题目根目录只保留稳定入口，过程快照收进对应子目录。

## 为什么 10 月后文件突然变多

- 2026-10-08 起，BFS 与洪水填充调试过程按教学协议保留了多次真实作答快照；这些不是重复生成的答案，也不是编译产物。
- 2026-10-10 的提交 `d778a64` 一次性保存了牛客 141092 未通过的 F～M 八份题面、四张插图，以及当日 BFS、快速幂和 E 题的学习证据。
- 旧结构把课程题、在线题库和整场比赛题面放在同一层，视觉上像“代码爆增”。本次只重新分区和收纳，未删除任何学生作答。

## 旧路径迁移

2026-10-14 前的 session 会保留当时路径，不回写历史记录。查找时按下列规则转换：

```text
problems/006-... 至 problems/015-...  -> problems/course/...
problems/P... 与 problems/1427-...   -> problems/online-judges/luogu/...
problems/team-selection/             -> problems/contests/team-selection-2026/
problems/nowcoder-141092*/           -> problems/contests/nowcoder-141092/
根目录早期诊断源码                    -> problems/course/000-initial-diagnostic/
```

时间戳 `attempt-*.cpp` 通常移入同题的 `attempts/`，测试记录移入 `tests/`。

