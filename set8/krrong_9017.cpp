#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        queue<int> player;

        vector<int> teamScore[202]; // 팀 스코어 저장
        int teamCount[202] = { 0 }; // 팀원의 수
        set<int> teams;

        // 각 팀의 인원 계산, 팀원을 Player에 저장
        for(int i = 1; i <= N; i++) {
            int number;
            cin >> number;
            teamCount[number]++;
            player.push(number);
        }


        for(int i = 1; i <= N; i++) {
            int front = player.front();
            player.pop();

            // 팀이 6명인 경우에만 점수를 계산할 수 있도록 다시 Player에 추가
            if(teamCount[front] == 6) {
                player.push(front);
                teams.insert(front); // 6명 이상인 팀 번호 기록
            }
        }

        int size = player.size();

        // 팀에 맞게 점수 배분
        for(int i = 1; i <= size; i++) {
            int front = player.front();
            player.pop();
            teamScore[front].push_back(i);
        }

        int minScore = 2000000000;
        int minTeam = 0;
        for(auto iter = teams.begin(); iter != teams.end(); iter++) {
            int i = *iter;
            // 상위 4명의 점수를 더함
            int teamScoreSum = teamScore[i][0] + teamScore[i][1] + teamScore[i][2] + teamScore[i][3];

            // 점수가 같은 경우 5번째 선수의 점수를 고려
            if(teamScoreSum == minScore) {
                if(teamScore[i][4] < teamScore[minTeam][4]) {
                    minTeam = i;
                }
            }
            else if(teamScoreSum < minScore) {
                minScore = teamScoreSum;
                minTeam = i;
            }

        }
        cout << minTeam << '\n';
    }

    return 0;
}