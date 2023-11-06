#include <iostream>
#include <vector>
using namespace std;

// 무조건 4개의 세트가 되어야 함
// 한 세트에는 무조건 하나의 나무는 포함되어 있어야 함
// 가능한 4개의 세트를 모두 구해서 크기 비교

int N, maxSum;
vector<int> trees;

int getMulti(int start, int end) {
    int res = 1;
    for(int i = start; i < end; i++) {
        res *= trees[i];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        trees.push_back(tmp);
    }

    // i, j, k는 한 세트의 마지막 지점 -> 이후 지점부터 탐색해야 함
    for(int i = 0; i < N - 3; i++) {
        for(int j = i + 1; j < N - 2; j++) {
            for(int k = j + 1; k < N - 1; k++) {
                for(int l = k + 1; l < N; l++) {
                    int sum = getMulti(0, j) + getMulti(j, k) + getMulti(k, l) + getMulti(l, N);
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }

    cout << maxSum;


    return 0;
}