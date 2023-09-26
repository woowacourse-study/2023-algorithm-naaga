#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 최대 숫자를 정하는 법 : 맨 앞에 9부터 넣어서 찾는다.
// 최소 숫자를 정하는 법 : 맨 앞에 0부터 넣어서 찾는다.

int k;
string maxString, minString;
vector<int> answer;
vector<char> inequality;
bool visited[10];


// n개의 숫자를 선택한 상태
void search(int n) {
    // 기저조건 : 선택한 숫자의 개수가 k+1과 같은데 조건에 만족하면 종료
    if(n == k + 1) {
        for(int i = 0; i < k + 1; i++) {
            maxString += to_string(answer[i]);
        }
        return;
    }

    // 큰 값부터 찾아 내려감
    for(int i = 9; i >= 0; i--) {
        if(visited[i] == true) continue;

        if(n == 0) {
            visited[i] = true;
            answer.push_back(i);
            search(n + 1);
            visited[i] = false;
            answer.pop_back();
        }

        // n - 1번 째 있는 부등호가 < 인 경우
        if(n - 1 >= 0 && inequality[n - 1] == '<') {
            // 부등호 조건에 맞는 경우
            if(answer[n - 1] < i) {
                visited[i] = true;
                answer.push_back(i);
                search(n + 1);
                visited[i] = false;
                answer.pop_back();
            }
        }
        // n번 째 있는 부등호가 > 인 경우
        else {
           if(answer[n - 1] > i) {
                visited[i] = true;
                answer.push_back(i);
                search(n + 1);
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for(int i = 0; i < k; i++) {
        char tmp;
        cin >> tmp;
        inequality.push_back(tmp);
    }

    search(0);

    for(int i = 0; i < k + 1; i++) {
        cout << maxString[i];
    }

    cout << '\n';

    int size = maxString.size();
    for(int i = 0; i < k + 1; i++) {
        cout << maxString[size - 1 - k + i];
    }


    return 0;
}

