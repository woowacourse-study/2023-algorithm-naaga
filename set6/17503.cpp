#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

// 맥주들을 <선호도, 도수 레벨>의 형태로 모두 저장한다.(200,000)
// 도수 레벨이 낮은 순으로 정렬한다. (NlogN)

// 아래 과정을 K번 반복한다.
//  Priority Queue에 맥주를 하나씩 담는다. (NlogN)
//  N개와 같아지면 선호도의 합이 M과 같은지 확인한다.
//  M보다 작으면 선호도가 가장 낮은 맥주를 뺀다.
//  M과 같으면 마지막에 넣은 도수 레벨을 출력한다.
// K번의 반복동안 정답이 안나오면 만족할 수 없다.

int N, M, K, res;
vector<pair<int, int>> beers;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // <선호도, 도수 레벨>

int comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
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

    sort(beers.begin(), beers.end(), comp);

    // 선호도의 합
    int sum = 0;

    for(int i = 0; i < K; i++) {
        pq.push(beers[i]);

        sum += beers[i].first;

        // 마실 수 있는 개수를 넘어선 경우 선호도가 가장 낮은 맥주를 삭제
        if(pq.size() > N) {
            sum -= pq.top().first;
            pq.pop();
        }

        // 조건에 만족하는 경우
        if(pq.size() == N && sum >= M) {
            cout << beers[i].second;
            return 0;
        }
    }

    cout << -1;
    return 0;
}