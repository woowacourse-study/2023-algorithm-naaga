#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// K개의 조로 나눔
// 티셔츠를 맞추는 비용은 가장 큰 키와 가장 작은 키의 차이

using namespace std;
vector<int> kindergartners;
vector<int> tallDiff;

int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        kindergartners.push_back(tmp);
    }

    for(int i = 1; i < N; i++) {
        int diff = kindergartners[i] - kindergartners[i - 1];
        tallDiff.push_back(diff);
    }

    sort(tallDiff.begin(), tallDiff.end());

    int ans = 0;
    for(int i = 0; i < tallDiff.size() - (K - 1); i++) {
        ans += tallDiff[i];
    }

    cout << ans;


    return 0;
}