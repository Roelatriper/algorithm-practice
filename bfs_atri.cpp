/* BFS 迷宫最短路径 但是是atri写的*/
#include <iostream>
using namespace std;

int row, col;
char maze[100][100];       // 迷宫，'0'通路 '#'墙
int visited[100][100];     // 访问标记
int startX, startY;        // 起点
int endX, endY;            // 终点

// 手写队列（最原始）
int qx[10000];             // 队列存 x
int qy[10000];             // 队列存 y
int qstep[10000];          // 队列存步数
int head, tail;            // 队头队尾

// 上右下左 四个方向的偏移
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 判断能不能站在 (nx, ny)
int canGo(int nx, int ny) {
    if (nx < 0 || nx >= row) return 0;      // 出界
    if (ny < 0 || ny >= col) return 0;      // 出界
    if (maze[nx][ny] == '#') return 0;      // 是墙
    if (visited[nx][ny] == 1) return 0;     // 走过了
    return 1;
}

int bfs() {
    // 起点入队
    head = 0;
    tail = 0;
    qx[tail] = startX;
    qy[tail] = startY;
    qstep[tail] = 0;
    tail = tail + 1;
    visited[startX][startY] = 1;

    // 队列非空就继续
    while (head < tail) {
        // 取出队头
        int cx = qx[head];
        int cy = qy[head];
        int cstep = qstep[head];
        head = head + 1;

        // 到终点了，第一次到达就是最短，直接返回
        if (cx == endX && cy == endY) {
            return
cstep;
        }

        // 四个方向都试一遍
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (canGo(nx, ny) == 1) {
                visited[nx][ny] = 1;           // 入队前标记
                qx[tail] = nx;                 // 新点入队
                qy[tail] = ny;
                qstep[tail] = cstep + 1;
                tail = tail + 1;
            }
        }
    }

    return -1;   // 走不到终点
}

int main() {
    cin >> row >> col;

    // 读迷宫
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> maze[i][j];
        }
    }

    // 找起点和终点（假设 'S' 起点，'E' 终点）
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == 'S') {
                startX = i;
startY = j;
            }
            if (maze[i][j] == 'E') {
                endX = i; endY = j;
            }
        }
    }

    int ans = bfs();
    if (ans == -1) {
        cout << "走不到终点" << endl;
    } else {
        cout << "最短步数: " << ans << endl;
    }

    return 0;
}