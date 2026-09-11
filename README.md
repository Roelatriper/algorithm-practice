# 白衣的 C++ 算法竞赛课堂

这是一个能够跨设备、跨聊天继续使用的长期学习仓库。课程讲义、本人作答、订正记录、教师评估与下一步计划都保存在 Git 中；GitHub 是 MacBook、宿舍机 WSL 与各个 GPT/Codex 会话之间的同步中心。

## 新会话开箱即用

在 Codex 中打开仓库后直接说：

> 请先读取根目录 `AGENTS.md`，然后根据课程状态继续给我上课。

支持仓库说明的智能助手会按 `AGENTS.md` 自动找到学生档案、当前进度和授课规则。若使用的聊天工具不会自动读取仓库，就把上面这句话发给它，并确保它能够访问仓库文件。

当前课程入口：[`course/STATE.md`](course/STATE.md)

完整课程路线：[`course/CURRICULUM.md`](course/CURRICULUM.md)

第一课：[`lessons/01-cpp-toolchain-and-correctness.md`](lessons/01-cpp-toolchain-and-correctness.md)

## 当前状态

- 当前阶段：阶段 0——工具链、正确性与调试闭环
- 当前语言：标准 C++17
- 日常环境：MacBook；Apple Clang
- 宿舍环境：Windows + WSL；Linux GCC；较大项目可由 MacBook 经 SSH 使用
- 默认近期目标：蓝桥杯/校赛入门；长期目标为 ICPC/CCPC 校队选拔基础水平

具体、可更新的状态只写在 `course/STATE.md`，本页不重复维护详细进度。

## 仓库结构

```text
.
├── AGENTS.md              # 新 GPT/Codex 会话的启动与交接规则
├── course/
│   ├── STATE.md           # 当前课程状态；每次课后更新
│   ├── STUDENT_PROFILE.md # 稳定的学生画像
│   ├── CURRICULUM.md      # 课程路线与结课标准
│   ├── TEACHING_PROTOCOL.md
│   └── sessions/          # 每次课的追加式记录
├── lessons/               # 课程讲义
├── scripts/               # Mac 与 WSL 共用的编译/运行入口
├── stats/                 # 练习统计页
└── *.cpp                  # 早期五道题的原始作答和参考代码
```

后续新题统一放在 `problems/编号-题目名/`，至少保留：

```text
attempt.cpp    # 本人首次作答，保留真实过程
solution.cpp   # 订正后或参考实现
review.md      # 错因、最小反例、提示等级与复习结果
```

## MacBook / WSL 使用

编译一个文件：

```bash
./scripts/build.sh dp.cpp
```

编译后直接运行：

```bash
./scripts/run.sh dp.cpp
```

使用准备好的输入文件：

```bash
./scripts/run.sh dp.cpp path/to/input.txt
```

脚本默认调用系统的 `c++`：MacBook 上通常是 Apple Clang，WSL 上通常是 GCC。也可临时指定编译器：

```bash
CXX=g++ ./scripts/build.sh dp.cpp
```

所有产物进入 `.build/`，不会提交到 GitHub。

建议每次开始前同步远端，结束后提交并推送。每台设备使用独立 clone；WSL 的 clone 建议位于 `~/projects/`，不要让 Windows Git 与 WSL Git 同时操作同一个工作目录。

## 初始练习记录

| 日期 | 题目 | 当前判定 | 耗时 |
|---|---|---|---:|
| 2026-08-24 | DFS 枚举子集 | 未独立完成；课后整理版 | 2.5h |
| 2026-08-24 | 区间调度 | 主体接近正确；仍需标准写法与边界验证 | 2.5h |
| 2026-08-25 | 迷宫最短路径 | 当前本人代码不是 BFS，需重学 | 1h |
| 2026-08-26 | 走楼梯 | 简单记忆化递归可独立完成 | 0.5h |
| 2026-08-27 | 二叉树最大深度 | 未完成；输入、建树与递归边界均需补课 | 2h |

## 隐私边界

本仓库只保存算法学习材料。新生学号表、个人材料、学校文件、账号凭据和其他保研资料均不得加入。若不希望公开学习记录，请在 GitHub 确认仓库可见性为 Private。
