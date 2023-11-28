#include <iostream>
#include <queue>

// 그래프의 개수를 찾아라
// 그래프에 번호를 매긴다
// 전체 정점을 순회하면서 그래프를 찾아 번호를 매기고
// 다시 전체 정점을 순회하면서 번호가 가장 큰 것을 반환한다

using namespace std;

char graph[1002][1002];
int graphNumbers[1002][1002];
bool visited[1002][1002];
int curGraphNumber = 0;
int N, M;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우 순서
int dy[4] = { 0, 0, -1, 1 };

bool valid(int x, int y) {
    return !(x < 0 || x >= N || y < 0 || y >= M);
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;  // BFS에서 사용하는 큐
    queue<pair<int, int>> q2; // 전체 번호를 지정하기 위한 큐
    q.push(make_pair(x, y));
    q2.push(make_pair(x, y));
    visited[x][y] = true;
    int graphNumber = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(graph[cur.first][cur.second] == 'U') {
            int nextX = cur.first + dx[0];
            int nextY = cur.second + dy[0];

            if(valid(nextX, nextY) == false) continue;

            if(visited[nextX][nextY] == false) {
                q.push(make_pair(nextX, nextY));
                q2.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = true;
            }
            // 방문한 적이 있다면 graphNumber가 주어져 있음
            else {
                graphNumber = graphNumbers[nextX][nextY];
            }
         }
        else if(graph[cur.first][cur.second] == 'D') {
            int nextX = cur.first + dx[1];
            int nextY = cur.second + dy[1];

            if(valid(nextX, nextY) == false) continue;

            if(visited[nextX][nextY] == false) {
                q.push(make_pair(nextX, nextY));
                q2.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = true;
            }
            else {
                graphNumber = graphNumbers[nextX][nextY];
            }
        }
        else if(graph[cur.first][cur.second] == 'L') {
            int nextX = cur.first + dx[2];
            int nextY = cur.second + dy[2];

            if(valid(nextX, nextY) == false) continue;

            if(visited[nextX][nextY] == false) {
                q.push(make_pair(nextX, nextY));
                q2.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = true;
            }
            else {
                graphNumber = graphNumbers[nextX][nextY];
            }
        }
        else if(graph[cur.first][cur.second] == 'R') {
            int nextX = cur.first + dx[3];
            int nextY = cur.second + dy[3];

            if(valid(nextX, nextY) == false) continue;

            if(visited[nextX][nextY] == false) {
                q.push(make_pair(nextX, nextY));
                q2.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = true;
            }
            else {
                graphNumber = graphNumbers[nextX][nextY];
            }
        }
    }

    // graphNumber가 0이 아니면 이미 있는 그래프에 연결되는 것
    if(graphNumber != 0) {
        while(!q2.empty()) {
            pair<int, int> cur = q2.front();
            q2.pop();
            graphNumbers[cur.first][cur.second] = graphNumber;
        }
    }
    // graphNumber가 0이면 새로운 그래프에 연결되는 것
    else {
        curGraphNumber++;
        while(!q2.empty()) {
            pair<int, int> cur = q2.front();
            q2.pop();
            graphNumbers[cur.first][cur.second] = curGraphNumber;
        }
    }
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

    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] == false) {
                bfs(i, j);
            }
        }
    }

    int maxNumber = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            maxNumber = max(maxNumber, graphNumbers[i][j]);
        }
    }

    cout << maxNumber;

    return 0;
}