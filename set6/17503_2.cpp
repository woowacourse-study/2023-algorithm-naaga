#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std; 

// 맥주를 선호도 순으로 정렬한다.
// 선호도를 만족하는 간 레벨을 매개변수 탐색으로 찾는다.
//      N개를 마셨을 때 선호도를 모두 더한다.
//      선호도가 M이상이면 간레벨을 높인다.
//      선호도가 M이하면 간레벨을 낮춘다.

int N, M, K, res;
vector<pair<int, int>> beers;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int v, c;
        cin >> v >> c;
        beers.push_back({v, c});
    }

    // 선호도 순으로 정렬
    sort(beers.begin(), beers.end(), comp);

    long low = 1;
    long high = INT_MAX;

    // 최적의 간수치를 찾는 이분탐색
    while(low <= high) {
        long mid = (low + high) / 2;

        int pref = 0;
        int beerCount = 0;
        bool satisfy = false;

        for(auto beer: beers) {
            // 간 레벨을 넘지 않는 맥주는 마실 수 있다.
            if(beer.second <= mid) {
                pref += beer.first;
                beerCount++;
            }
            
            // N개의 맥주를 모두 마신 경우
            if(beerCount == N) {
                // 선호도를 만족하는지 확인
                if(pref >= M) {
                    satisfy = true;
                }
                break;
            }
        }

        // 선호도를 만족한 경우 간 레벨 Down
        if(satisfy) {
            high = mid - 1;
        } 
        // 선호도를 만족하지 않은 경우 간 레벨 Up
        else {
            low = mid + 1;
        }
    }

    if(low > INT_MAX) {
        cout << -1;
        return 0;
    }

    cout << low;


    return 0;
}