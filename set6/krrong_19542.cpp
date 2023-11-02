#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// dfs 활용
// 자식 노드들의 깊이 중 가장 깊은 것을 사용
// 가장 깊은 값의 *2배

int N, S, D, ans = 0;
vector<int> graph[100002];
int depth[100002];
bool visited[100002];

int dfs(int node) {
    // 인접 노드에 대해 탐색
    for(auto next: graph[node]) {
        // 이미 방문한 노드라면 패스
        if(visited[next]) continue;

        // 방문처리
        visited[next] = true;

        // 더 깊은 깊이를 추가
        depth[node] = max(depth[node], dfs(next));
    }
    return depth[node] + 1;
}

void dfs2(int node) {
    for(auto next: graph[node]) {
        if(visited[next]) continue;

        if(depth[next] >= D) {
            ans++;
            visited[next] = true;
            dfs2(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S >> D;

    for(int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    fill_n(visited, 100002, false);

    visited[S] = true;
    dfs(S);
    fill_n(visited, 100002, false);

    visited[S] = true;
    dfs2(S);

    cout << ans * 2 ;

    return 0;
}