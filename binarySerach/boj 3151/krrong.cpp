#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long cnt;
vector<int> skills;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int skill;
        cin >> skill;
        skills.push_back(skill);
    }

    // 오름차순 정렬
    sort(skills.begin(), skills.end());

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            // 두 팀원을 고른 상태
            int sum = skills[i] + skills[j];

            // sum * -1 이상의 수가 처음 나오는 index 반환
            int start = lower_bound(skills.begin() + j + 1, skills.end(), sum * -1) - skills.begin();

            // sum * -1 초과 수가 처음 나오는 index 반환
            int end = upper_bound(skills.begin() + j + 1, skills.end(), sum * -1) - skills.begin();

            cnt += end - start;
        }
    }

    cout << cnt;

    return 0;
}

