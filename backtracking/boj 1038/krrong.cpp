#include <iostream>
#include <string>
using namespace std;

int N;
int cnt;
bool isFind = false;

bool isDown(string num) {
    int front = 0;
    int second = 1;

    int size = num.size();

    while(true) {
        if(second == size) {
            break;
        }

        // 뒤자리가 더 크거나 같은 경우 (감소하는 수가 아닌경우)
        if(num[front] <= num[second]) {
            return false;
        }

        // 다음 자리 확인
        front++;
        second++;
    }
    return true;
}

// digit : 탐색하는 자리수
// num : 현재 숫자
// search : num은 감소하는 수일 때만 들어온다. digit 자리수까지 탐색을 하고 만족하면 종료한다.
void search(int digit, long long num) {
    // 기저조건 : num(현재 숫자)이 digit(탐색하는 자리수)에 만족하면 개수를 더해주고 종료
    if(to_string(num).size() == digit) {
        cnt++;
        if(cnt == N + 1) {
            cout << num;
            isFind = true;
            return;
        }
        return;
    }

    for(int i = 0; i < 10; i++) {
        string tmp = to_string(num) + to_string(i);
        if(isDown(tmp)) {
            search(digit, stoll(tmp));
        }
        else {
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i < 11; i++) { // 자리수
        for(int j = 0; j < 10; j++) { // 시작 숫자
            search(i, j);
        }
    }

    if(!isFind) {
        cout << -1;
    }

    return 0;
}
