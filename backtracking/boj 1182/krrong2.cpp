#include <iostream>
#include <vector>
using namespace std;

int N, S, cnt = 0;
vector<int> numbers;

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

    int k = (1 << N) - 1;

    for(int i = 1; i <= k; i++) {
        int ans = 0;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                ans += numbers[j];
            }
        }
        if(ans == S) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}

