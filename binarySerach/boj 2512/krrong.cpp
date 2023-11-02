#include <iostream>
#include <vector>
using namespace std;

int N, M, maxMoney;
vector<int> requireMoney;

bool enough(int money) {
    long long allMoney = 0;

    for(int i = 0; i < N; i++) {
        // 상한보다 더 큰 금액을 요구하면 상한을 지급
        if(requireMoney[i] > money) {
            allMoney += money;
        }
        // 상한보다 작은 금액을 요구하면 그만큼 지급
        else {
            allMoney += requireMoney[i];
        }
    }

    // 전체 금액이 M보다 작거나 같아야 충분함
    return allMoney <= M;
}

// 상한 금액을 결정하는 이분탐색
int search() {
    int lo = 1;
    int hi = maxMoney;
    int mid = 0;

    while(lo <= hi) {
        mid = (lo + hi) / 2;

        if(enough(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return hi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        requireMoney.push_back(a);

        maxMoney = max(maxMoney, a);
    }

    cin >> M;

    cout << search();

    return 0;
}