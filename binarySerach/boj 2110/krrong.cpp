#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> homes;

bool canInstall(int distance) {
    int installRouter = 1;          // 설치된 공유기 개수
    int curLocation = homes[0];     // 현재 공유기가 설치되어 있는 위치
    int nextLocation = homes[1];    // 다음 위치

    for(int i = 1; i < N; i++) {
        nextLocation = homes[i];

        // 두 지점 사이의 거리가 이분 distance Mid보다 크면 설치
        if(nextLocation - curLocation > distance) {
            installRouter++;
            curLocation = homes[i];
        }
    }

    return installRouter >= C;
}

int binarySearch() {
    int lo = 0;
    int hi = homes[N-1];
    int mid = 0;

    while(lo <= hi) {
        mid = (lo + hi) / 2;

        if(canInstall(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        homes.push_back(tmp);
    }

    sort(homes.begin(), homes.end());

    cout << binarySearch();

    return 0;
}