#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 105;
int n, m;
int grid[MAXN][MAXN];   // 地图：0 空地，1 墙
int dist[MAXN][MAXN];   // 从起点到每个格子的最短步数，0 表示还没走到
int dx[4] = {-1, 1, 0, 0};  // 上、下、左、右
int dy[4] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});     // 起点入队
    dist[0][0] = 1;     // 起点算第 1 格

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 第一次弹出终点时，一定是最短路径（BFS 按层扩展）
        if (x == n - 1 && y == m - 1) return dist[x][y];

        // 尝试朝四个方向走
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 出界 / 撞墙 / 已经走过 -> 跳过
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == 1) continue;
            if (dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[x][y] + 1;  // 步数 = 当前格步数 + 1
            q.push({nx, ny});
        }
    }
    return -1;  // 走不到终点
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << bfs() << endl;
    return 0;
}
