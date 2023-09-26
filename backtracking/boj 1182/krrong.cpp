#include <iostream>
#include <vector>
using namespace std;

// 합계가 S인 경우 ans++ 해줌
// 합계가 S보다 커도 계속 확인해야 함 -> 음수를 원할 수도 있기 때문에

int N, S, ans = 0;
vector<int> numbers;
bool visited[21];

// n번 째 수까지의 합이 sum이다.
void search(int n, int sum) {
    // 합계가 S인 경우 ans++
    if(n > 0 && sum == S) {
        ans++;
    }

    for(int i = n; i < N; i++) {
        // 이미 선택한 수라면 패스
        if(visited[i] == true) continue;

        visited[i] = true;
        sum = sum + numbers[i];
        search(i + 1, sum);
        sum = sum - numbers[i];
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    search(0, 0);
    cout << ans;

    return 0;
}

