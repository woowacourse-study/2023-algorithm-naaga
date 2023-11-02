#include <iostream>
#include <vector>
using namespace std;

int N, M, Max;
vector<long> treeHeighs;

// 높이가 h일 때 가져갈 수 있는 길이
long getLength(int h) {
    long length = 0;

    for(int i = 0; i < N; i++) {
        long canGetLength = treeHeighs[i] - h;

        if(canGetLength > 0) {
            length += canGetLength;
        }
    }

    return length;
}

// M만큼의 길이를 가져갈 수 있는 최대 높이를 반환
int binarySerach() {
    int low = 1;
    int high = Max;

    while(low <= high) {
        int mid = (low + high) / 2;

        // 여기를 long으로 해주는게 중요
        long treeLength = getLength(mid);

        // 조건 : 높이 mid에서 나무를 잘라 가져갈 수 있는 길이가 M보다 작거나 같은 경우
        if(treeLength <= M) {
            // 작거나 같은 경우 더 많이 잘라야 한다. == 높이를 낮춰야 한다. == high를 내려야 한다.
            high = mid - 1;
        }
        else {
            // 큰 경우 덜 잘라야 한다. == 높이를 올려야 한다. == low를 높여야 한다.
            low = mid + 1;
        }
    }

    // 조건에 만족하는 경우 low가 정답
    if (getLength(low) >= M) {
        return low;
    }
    // 조건에 만족하지 않는 경우 high가 정답
    return high;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;    
    
    for(int i = 0; i < N; i++) {
        int height;
        cin >> height;

        if(Max < height) {
            Max = height;
        }

        treeHeighs.push_back(height);
    }

    cout << binarySerach();

    return 0;
}