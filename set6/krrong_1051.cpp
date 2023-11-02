#include <iostream>
using namespace std; 

int N, M;
int board[51][51];
int maxSize = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            board[i][j] = tmp[j] - '0';
        }
    }

    // 가로 세로 중 더 짧은 것이 정사각형의 최대 변의 길이
    int length = min(N, M);
    int searchLength = 1;

    // 변의 길이가 1인 것부터 탐색
    while(searchLength <= length) {
        for(int i = 0; i < N - searchLength; i++) {
            for(int j = 0; j < M - searchLength; j++) {
                // 꼭지점이 모두 같은 경우
                if(board[i][j] == board[i + searchLength][j] && board[i][j] == board[i][j + searchLength] && board[i][j] == board[i + searchLength][j + searchLength]) {
                    maxSize = searchLength;
                }
                
            }
        }

        // 탐색하는 변의 길이를 늘림
        searchLength++;
    }

    cout << (maxSize + 1) * (maxSize + 1);

    return 0;
}