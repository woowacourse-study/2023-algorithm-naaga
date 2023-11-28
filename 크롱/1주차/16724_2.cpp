#include <iostream>

// 그래프의 개수를 찾아라
// visited를 활용한다
// visited가 0인 경우 : 방문하지 않음
// visited가 1인 경우 : 방문함
// visited가 2인 경우 : 사이클임을 확인

using namespace std;

char graph[1002][1002];
int visited[1002][1002];
int ans = 0;
int N, M;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우 순서
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    visited[x][y] = 1;
    int dir = 0;
    if(graph[x][y] == 'U') dir = 0;
    else if(graph[x][y] == 'D') dir = 1;
    else if(graph[x][y] == 'L') dir = 2;
    else if(graph[x][y] == 'R') dir = 3;

    int nextX = x + dx[dir];
    int nextY = y + dy[dir];

    if(visited[nextX][nextY] == 1) ans++;
    if(visited[nextX][nextY] == 0) dfs(nextX, nextY);
    visited[x][y] = 2;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        for(int j = 0; j < M; j++) {
            graph[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
    cout << ans;

    return 0;
}