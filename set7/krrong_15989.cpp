#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

// 모든 수는 1 + 1 + 1.. 로 나타낼 수 있다.
// 기본적으로 한 개는 만들 수 있다.

int T, n;
int dp[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 모두 1개씩은 있어서 기본 값 세팅
    for(int i = 0; i < 10002; i++) {
        dp[i] = 1;
    }

    for(int i = 2; i < 10002; i++) {
        dp[i] += dp[i-2];
    }

    for(int i = 3; i < 10002; i++) {
        dp[i] += dp[i-3];
    }

    cin >> T;

    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}