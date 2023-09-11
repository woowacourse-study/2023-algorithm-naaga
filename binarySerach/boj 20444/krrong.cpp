#include <iostream>
using namespace std;

long long n, k;

// 가로로 몇 번 자를지를 반환하는 이분탐색
string search() {
    long long lo = 0;
    long long hi = n / 2;
    long long mid = 0;

    while(lo <= hi) {
        mid = (lo + hi) / 2;

        long long papers = (mid + 1) * (n - mid + 1);

        if(papers <= k) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    
    long long papers = (hi + 1) * (n - hi + 1);

    if(papers == k) {
        return "YES";
    }
    return "NO";
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cout << search();
    
    return 0;
}