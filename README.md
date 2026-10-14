# 白衣的 C++ 算法竞赛课堂

这是一个跨设备、跨聊天持续使用的算法学习仓库。课程状态、本人作答、订正证据和下一步计划均以仓库记录为准。

## 从这里开始

1. 先读 [`course/STATE.md`](course/STATE.md)：当前课、掌握证据和下一步。
2. 再读 [`course/STUDENT_PROFILE.md`](course/STUDENT_PROFILE.md) 与 [`course/TEACHING_PROTOCOL.md`](course/TEACHING_PROTOCOL.md)：长期约束和教学规则。
3. 题目统一从 [`problems/README.md`](problems/README.md) 进入，不直接把 `problems/` 的文件数量当作待办数量。

## 目录职责

```text
.
├── course/       # 当前状态、课程路线、教学协议、会话记录和待决提案
├── lessons/      # 按教学顺序编写的讲义
├── problems/     # 学生作答与题目证据；内部按来源分区
├── scripts/      # 跨 MacBook / WSL 的编译、运行和调试入口
├── stats/        # 外部题库统计页，不作为课程进度的唯一依据
├── .build/       # 本地构建与检查产物，已忽略，不提交
├── tmp.cpp       # 当前临时工作文件，可随时变化
└── AGENTS.md     # Tutor / Curator 的仓库维护规则
```

`course/STATE.md` 是当前状态的唯一入口；详细历史留在 `course/sessions/` 和每题的 `review.md`，README 不重复维护易过期的进度。

## 编译与运行

```bash
./scripts/build.sh path/to/file.cpp
./scripts/run.sh path/to/file.cpp
./scripts/debug.sh path/to/file.cpp
```

构建产物进入 `.build/`。课程代码默认采用 C++03 兼容写法；统一脚本仍以 C++17 编译，用于跨 Apple Clang 与 Linux GCC 验证。

## 内容边界

这里只保存算法课程所需材料。个人资料、学校文档、账号凭据和其他无关交付物应放在仓库外。
