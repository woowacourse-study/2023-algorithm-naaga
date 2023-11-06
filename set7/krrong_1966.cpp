#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, res;

bool comp(int a, int b) {
    if(a > b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--) {
        cin >> N >> M;

        int count = 0;
        queue<pair<int, int>> printQ; // <문서의 순서, 중요도>
        priority_queue<int> priority;    // 중요도

        for(int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            priority.push(tmp);
            printQ.push({i, tmp});
        }

        while(true) {
            pair<int, int> curPrint = printQ.front();
            printQ.pop();

            // 출력하려는 프린트가 원하는 것인 경우
            if(curPrint.first == M) {
                // 우선순위가 가장 높으면 출력 후 종료
                if(curPrint.second == priority.top()) {
                    cout << ++count << '\n';
                    break;
                }
                // 우선순위가 가장 높지 않으면 다시 큐에 추가
                printQ.push(curPrint);
            }
            // 출력하려는 프린트가 원하는 것이 아니지만 우선순위가 가장 높은 경우 출력
            else if(curPrint.second == priority.top()) {
                count++;
                priority.pop();
            }
            // 출력하려는 프린트가 원하는 것이 아니고 우선순위도 낮으면 다시 큐에 추가
            else {
                printQ.push(curPrint);
            }
        }
    }


    return 0;
}