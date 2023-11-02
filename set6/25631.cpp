#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// 같은 숫자가 가장 많은 개수가 곧 마트료시카의 개수다....!

int N, res;
vector<int> martosica;
vector<int> numberCount;

bool comp(int a, int b) {
    if (a > b) return true;
    return false;
}

bool isAllZero() {
    for(int i = 0; i < N; i++) {
        if(numberCount[i] != 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        martosica.push_back(tmp);
    }

    sort(martosica.begin(), martosica.end(), comp);

    int cnt = 0;
    int curNumber = martosica[0];
    for(int i = 0; i < N; i++) {
        if(curNumber != martosica[i]) {
            numberCount.push_back(cnt); // 개수 추가
            curNumber = martosica[i];   // 현재 바라보고 있는 숫자 갱신
            cnt = 1;    // 개수 갱신
            continue;
        }
        cnt++;
    }
    numberCount.push_back(cnt); // 개수 추가

    // while(!isAllZero()) {
    //     for(int i = 0; i < numberCount.size(); i++) {
    //         cout << numberCount[i] << ' ';
    //     }
    //     cout << endl;

    //     res++;
    //     int diff = 0;

    //     for(int i = 0; i < numberCount.size(); i++) {
    //         if(numberCount[i] != 0) {
    //             diff = numberCount[i];
    //             break;
    //         }
    //     }

    //     for(int i = 0; i < numberCount.size(); i++) {
    //         // 0인 경우 확인 작업을 거치지 않아도 된다.
    //         if(numberCount[i] == 0) continue;


    //         // 가장 큰 값의 개수보다 작은 경우 0으로 바꾼다
    //         if(numberCount[i] <= diff) {
    //             numberCount[i] = 0;
    //         } 
    //         // 가장 큰 값의 개수보다 많으면 가장 큰 값의 개수만큼 제거
    //         else {
    //             numberCount[i] -= diff;
    //         }
    //     }
    // }

    sort(numberCount.begin(), numberCount.end(), comp);
    cout << numberCount[0];


    return 0;
}