# 用运行证据调试 C++ 程序

## 当前目标

结合洪水填充重写练习，学习固定失败输入、缩小输入、定位非法访问及验证修改。使用 C++03 兼容代码；不替代后续自主测试与迁移。

## 一次调试的顺序

1. 写下同一份输入、预期输出、实际输出或报错。每次修改后运行同一份输入，保证比较有依据。
2. 缩小输入，每删一部分就重新运行。只有仍然触发原症状，才能保留这次缩小。
3. 列出可能原因及能区分它们的证据。本次按地图越界、空队列读取、行列混用排列；分别观察地图下标、front 调用及非方形尺寸。
4. 用检查器或断点观察出错位置和变量。工具报告的库函数不是一定需要修改的地方，要沿调用栈找到自己写的函数。
5. 一次只修改一个原因；重跑最小输入和原输入，既检查退出状态，也比较完整输出。没有崩溃不等于答案正确。

## 本次真实案例

- 学生输入：`2 2 .##.`，等价于两行地图 `.#`、`#.`。
- 预期：三行 `2`、`1`、`1`，因为对角不连通。
- 原稿两次正常编译运行均退出 -11（SIGSEGV），没有输出。
- 最小规模复现：`1 2 / .#`，预期两行 `1`、`1`；1×1 点和墙都正常，因此缩小到两格即可。
- AddressSanitizer 报告 `heap-buffer-overflow`，调用栈包含 `vector<char>::operator[]`、`bfs`、`main`。
- 本机检查器符号化失败，使用 atos 映射 bfs 地址后确认原稿第 22 行。
- 只在地图读取前打印坐标的临时探针记录：`nx=1 ny=0 rows=1 cols=2`，随后崩溃。临时探针已删除，学生源文件未修改。

原稿第 22 行先读取 `maps[nx][ny]` 和访问标记，后检查坐标。C++ 的 `||` 从左到右求值，遇到 true 才跳过剩余项；边界条件写在后面，无法保护已经发生的读取。请学生自行调整判断次序，本记录不提供整题实现。

## 开启内存检查器

在仓库根目录执行：

```sh
./scripts/debug.sh problems/course/014-flood-fill-components/rewrite.cpp
```

然后输入失败地图。脚本自动编译并运行，二进制放入 ignored `.build/debug/`。也可在命令最后追加输入文件路径。CXX 环境变量可指定编译器，默认 c++；使用严格 C++03，沿用当前授课语法约束。

两个长参数只需知道用途，不要求背拼写：

- `-fsanitize=address,undefined`：开启运行时检查。address 查越界、释放后使用等内存问题；undefined 查部分未定义行为，例如有符号整数溢出。
- `-fno-omit-frame-pointer`：保留函数调用链的线索，帮助检查器显示调用路径，比如 main → bfs → 地图读取。这里的 frame pointer 是编译器内部用到的信息。

脚本还设置 `-g` 保留调试信息、`-O0` 关闭优化。这些都是编译选项。检查器能帮助查运行错误，但不会判断区域数是否符合题意。后续授课优先使用短命令，按当前报错逐条讲解。

## 本机实践与交接

- 原稿保存在 `problems/course/014-flood-fill-components/attempts/attempt-2026-10-12-2026.cpp`，工作文件 rewrite.cpp 保持学生内容。
- 本机可重复检查命令：`python3 .build/flood-fill-debug-2026-10-12/check.py`。它每次重编译工作文件，检查原输入、最小输入及题面样例。首次运行结果 FAIL、FAIL、PASS，脚本退出 1。
- `.build/` 不参与同步；其他设备按本文的三个输入重建检查即可。
- LLDB 已安装且可以设置 main 断点，但本次启动进程失败，提示 `process exited with status -1 (no such process)`；未获得断点停住或单步成功证据。本轮使用检查器及定向输出完成定位。
- 下一步由学生修改判断顺序，再验证输出。不得把本轮记为独立调试或程序通过；本题累计最高提示为 4。

## VS Code 图形调试：由学生操作

### 先理解 tasks.json 与 launch.json

- tasks.json 描述构建任务：执行什么命令、传什么参数，最后生成可执行文件。
- launch.json 描述调试启动：启动哪个可执行文件、使用哪个调试器、启动前先跑哪个构建任务。

按 F5 的流程是：launch 的 preLaunchTask → tasks 中同名 label → 编译源文件 → 调试器启动 launch 的 program → 在用户设的断点暂停。

当前仓库有两处必须对上：

1. launch 的 `preLaunchTask` 值 `build current C++ file for debugging`，必须与 tasks 的 `label` 完全一致。
2. launch 的 `program` 必须指向构建任务生成的可执行文件。普通模式的 build.sh 把 rewrite.cpp 编译成 `.build/rewrite`；断点模式的 build-debug.sh 编译成 `.build/gui-debug/rewrite`，对应 launch 分别指向这两个文件。

VS Code 会替换这些占位符：`${workspaceFolder}` 是打开的仓库根目录，`${file}` 是当前活动文件的完整路径，`${fileBasenameNoExtension}` 是当前文件名去掉扩展名，例如 rewrite。

当前普通 task 的 command 是 build.sh，断点调试 task 的 command 是 build-debug.sh，两者的 args 都是当前文件路径。断点任务等价于在仓库根目录执行 `./scripts/build-debug.sh problems/course/014-flood-fill-components/rewrite.cpp`，由脚本设置 -g/-O0 等编译选项。10-12 收尾时改为两个脚本，build.sh 保留原来的单参数接口。

launch 的常用选项：`MIMode: lldb` 使用当前 Mac 的 LLDB；`stopAtEntry: true` 启动后先停在 main 入口；`externalConsole: true` 打开交互输入终端；`cwd` 是程序运行时的工作目录；`args` 是程序命令行参数，本题地图通过终端的标准输入读入，因此 args 留空。

以后独立配置，先确定构建命令及其输出路径，再让 program 指向该输出，用 preLaunchTask 与 label 连接两份配置；随后才能检验断点暂停和变量观察。

1. 打开要调试的 cpp 文件并保存。在需要观察的行号左边点击，出现红点就是断点。本题先用第 22 行。
2. 打开左侧“运行和调试”，选择“C++ 图形调试（当前文件）”，点击绿色开始按钮（F5）。启动前自动用 -g -O0 构建，能观察源码和变量。
3. 当前配置在 main 入口先暂停一次。黄色行表示下一条要执行的位置，尚未执行。点击继续后，切换到弹出的终端窗口输入地图；程序输入应写在该终端。
4. 遇到第 22 行断点后暂停。把鼠标放在 nx、ny 上看值，也可用左侧“变量”查看当前函数变量；全局尺寸可悬停 a、b 查看。
5. “单步跳过”（F10）执行当前行再暂停；“继续”（F5）运行到下一断点或异常；红色方块停止调试。先掌握这三个按钮，避免一次引入更多操作。Mac 功能键被系统占用时用鼠标按钮或 Fn 配合。
6. 本次由学生亲自停到断点、报告坐标并检查范围，不由教师代为修正源码。下一题按同样流程选择观察点，而非固定使用第 22 行。

本机准备情况：已安装微软 C/C++ 扩展。普通编译仍是原 build.sh 的 C++17/-O2，并为默认构建任务；独立 build-debug.sh 使用 C++03/-g/-O0，输出到另一目录。launch.json 提供“C++ 普通运行（原编译模式）”和“C++ 图形调试（当前文件）”两个入口。两者均已构建并按 launch 的 program 路径运行题面单格样例通过，学生源码未改。尚未实际成功启动 GUI 调试进程，不将配置检查通过记为单步验证成功；收尾检查时 VS Code 窗口已关闭。

同步：按学生要求提交配置，gitignore 已允许共享 .vscode/launch.json，与 task 和两个构建脚本一起通过 git 同步。配置在 Mac 使用 LLDB，Linux/WSL 使用 GDB；本轮只验证 Mac 构建，未验证其他平台调试。macOS 的 cppdbg/LLDB 使用外部终端承接交互输入，依据 [VS Code 官方调试配置说明](https://code.visualstudio.com/docs/cpp/launch-json-reference)。以下为当前断点入口的关键配置，完整两模式见 .vscode/launch.json。

```json
{
  "version": "0.2.0",
  "configurations": [{
    "name": "C++ 图形调试（当前文件）",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/.build/gui-debug/${fileBasenameNoExtension}",
    "cwd": "${workspaceFolder}",
    "stopAtEntry": true,
    "externalConsole": true,
    "MIMode": "gdb",
    "osx": { "MIMode": "lldb" },
    "preLaunchTask": "build current C++ file for debugging"
  }]
}
```
