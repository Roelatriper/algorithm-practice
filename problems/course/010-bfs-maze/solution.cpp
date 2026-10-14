#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Bucket {
    int x;
    int y;
    int dist;
};

typedef vector<vector<char> > Map;
typedef vector<vector<bool> > Visited;

Bucket bfs(const Map& map, Visited& visited) {
    Bucket failure;
    failure.x = -1;
    failure.y = -1;
    failure.dist = -1;

    if (map.empty() || map[0].empty()) {
        return failure;
    }

    int rows = static_cast<int>(map.size());
    int cols = static_cast<int>(map[0].size());

    if (map[0][0] == '#' || map[rows - 1][cols - 1] == '#') {
        return failure;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<Bucket> q;

    Bucket start;
    start.x = 0;
    start.y = 0;
    start.dist = 0;

    visited[0][0] = true;
    q.push(start);

    while (!q.empty()) {
        Bucket cur = q.front();
        q.pop();

        if (cur.x == rows - 1 && cur.y == cols - 1) {
            return cur;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) {
                continue;
            }
            if (map[nx][ny] == '#' || visited[nx][ny]) {
                continue;
            }

            Bucket next;
            next.x = nx;
            next.y = ny;
            next.dist = cur.dist + 1;

            visited[nx][ny] = true;
            q.push(next);
        }
    }

    return failure;
}

int main() {
    int rows;
    int cols;
    cin >> rows >> cols;

    Map map(rows, vector<char>(cols));
    Visited visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> map[i][j];
        }
    }

    Bucket answer = bfs(map, visited);
    cout << answer.dist << '\n';

    return 0;
}
