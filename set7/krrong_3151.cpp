#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2명을 선택하고 나머지 한 명을 선택한다.

int N, cnt;
vector<int> students;
vector<int> isSelected;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        students.push_back(tmp);
        isSelected.push_back(false);
    }

    // 코딩 실력을 오름차순으로 정렬
    sort(students.begin(), students.end());

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            // 두 팀원을 고른 상태
            int sum = students[i] + students[j];

            // sum * -1 이상의 수가 처음 나오는 index 반환
            int start = lower_bound(students.begin() + j + 1, students.end(), sum * -1) - students.begin();

            // sum * -1 초과 수가 처음 나오는 index 반환
            int end = upper_bound(students.begin() + j + 1, students.end(), sum * -1) - students.begin();

            cnt += end - start;
        }
    }

    cout << cnt / 2;

    return 0;
}