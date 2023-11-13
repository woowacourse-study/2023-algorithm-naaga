#include <iostream>
using namespace std;

// K시간만큼 사람이 서있다가 L시간만큼 사람이 없어야 Flush를 할 수 있음

int K, L, N;
bool isFlush = false;
string urinal;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> L >> N;
    cin >> urinal;

    bool isStartOne = false;
    bool isStartZero = false;
    bool needFlush = false;
    int onPerson = 0;
    int nonPerson = 0;

    for(int i = 0; i < N; i++) {
        if(urinal[i] == '1') {
            // 처음 1을 만난 경우 (0뒤에 1이 나오는 경우 서 있는 시간 갱신)
            if(isStartOne == false) {
                isStartZero = false; // 1을 만났음을 표시

                onPerson = 0;
                isStartOne = true;
            }
            // 1인 경우 서 있는 시간 증가
            onPerson++;

            // 사용중 감지 센서보다 크거나 같으면 있는 것을 인지 -> Flush가 필요함
            if(onPerson >= K) {
                needFlush = true;
            }
        }
        else if(urinal[i] == '0') {
            // 1뒤의 0을 만난 경우
            if(isStartZero == false) {
                isStartOne = false; // 0을 만났음을 표시

                nonPerson = 0;
                isStartZero = true;
            }
            // 0인 경우 없는 시간 증가
            nonPerson++;

            // 사람이 있는 것을 인지하고 없는 것을 인지하는 시간동안 지난 경우 Flush
            if(needFlush && nonPerson >= L) {
                cout << i + 1 << '\n';
                needFlush = false;
                isFlush = true;
            }
        }
    }

    // Flush가 필요한 경우
    if(needFlush) {
        isFlush = true;
        cout << N + L;
    }

    // Flush가 필요하지 않은 경우
    if(!isFlush) {
        cout << "NIKAD";
    }

    return 0;
}