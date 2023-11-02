#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 친구의 친구는 친구다.
// 모든 사람과 친구가 되어야 한다.

// 친구의 연결 그래프를 쭉 이어놓고 가장 값이 낮은 친구를 선택한다.
// 친구가 되는 비용을 모두 계산한다.
// 만약 가지고 있는 돈보다 큰 경우 불가능하다.

int N, M, k, res = 0;
vector<int> money;
vector<vector<int>> friends;
bool isFriend[10002];

// 친구관계를 정의하고 가장 낮은 금액을 반환한다
int dfs(int friendNumber) {
    queue<int> q;
    q.push(friendNumber);
    int minMoney = money[friendNumber];
    isFriend[friendNumber] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < friends[cur].size(); i++) {
            int next = friends[cur][i];

            if(isFriend[next] == false) {
                minMoney = min(minMoney, money[next]);
                isFriend[next] = true;
                q.push(next);
            }
        }
    }
    
    return minMoney;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> k;
    money.push_back(0);
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        money.push_back(tmp);
    }

    // for(int i = 0; i < M; i++) { bad_alloc
    // for(int i = 0; i < N; i++) { outOfBounds
    for(int i = 0; i <= N; i++) {
        vector<int> tmp;
        friends.push_back(tmp);
        isFriend[i] = false;
    }

    // 친구 관계 정의
    for(int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        friends[v].push_back(w);
        friends[w].push_back(v);
    }

    for(int i = 1; i <= N; i++) {
        if(isFriend[i] == false) {
            res += dfs(i);
        }
    }

    // 필요한 금액이 가지고 있는 금액보다 크면 친구 사귀기 불가능
    if(res > k) {
        cout << "Oh no";
        return 0;
    }

    // 친구가 없다면 불가능
    for(int i = 1; i <= N; i++) {
        if(isFriend[i] == false) {
            cout << "Oh no";
            return 0;
        }
    }

    cout << res;

    return 0;
}