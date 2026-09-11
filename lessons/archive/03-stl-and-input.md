# 历史讲义：C++ STL 基础与输入输出

> 原讲义完成于正式课程仓库建立之前。本文件作为第一阶段参考，掌握情况仍需通过练习验证。

## vector

```cpp
#include <vector>
using namespace std;

vector<int> values;
values.push_back(3);
values.push_back(9);

for (int value : values) {
    // 使用 value
}
```

`vector` 是长度可以动态变化的连续数组。常用操作包括 `push_back`、`size`、`back` 和下标访问。

## string 与整数转换

```cpp
#include <string>

string token;
cin >> token;

if (token != "null") {
    int value = stoi(token);
}
```

当输入中混合数字与 `null` 时，应先按字符串读取，判断后再转换。

## queue 与 stack

```cpp
#include <queue>
#include <stack>

queue<int> q;
q.push(1);
int first = q.front();
q.pop();

stack<int> st;
st.push(1);
int top = st.top();
st.pop();
```

- 队列先进先出，是 BFS 的核心容器。
- 栈后进先出；DFS 可用显式栈或递归实现。

## sort

```cpp
#include <algorithm>
#include <vector>

sort(values.begin(), values.end());
```

结构体可以使用 lambda 指定排序规则：

```cpp
struct Interval {
    int start;
    int end;
};

sort(intervals.begin(), intervals.end(),
     [](const Interval& a, const Interval& b) {
         return a.end < b.end;
     });
```

## EOF 输入

```cpp
int value;
while (cin >> value) {
    // 每次成功读到一个整数时处理
}
```

读取失败或到达文件末尾时，循环自然结束。不要用字符 `NULL` 判断文本输入是否结束。

## 练习

1. 读取数量未知的一组整数并倒序输出。
2. 读取由整数和 `null` 组成的输入，对全部整数求和。
3. 使用队列模拟轮转：队首出队后重新进入队尾，输出第 `k` 次操作后的队首。
