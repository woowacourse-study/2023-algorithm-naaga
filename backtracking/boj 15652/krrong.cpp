#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;

// n개의 수를 뽑은 상태, 마지막 수는 last 임
void search(int n, int last) {
    // 기저 조건 : 개수가 M개라면 출력 후 종료
    if(n == M) {
        for(int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = last; i <= N; i++) {
        ans.push_back(i);
        search(n+1, i);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    search(0, 1);


    return 0;
}
