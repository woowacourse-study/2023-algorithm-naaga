#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;

// n개의 수를 뽑은 상태
void search(int n) {
    // 기저 조건 : M개의 수를 뽑은 상태라면 출력하고 종료
    if(n == M) {
        for(int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        ans.push_back(i);
        search(ans.size());
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    search(0);


    return 0;
}
