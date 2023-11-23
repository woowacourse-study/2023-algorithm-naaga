#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 교차점을 구하고 교차점까지의 합을 미리 구해놓는다. 그리고 더 큰 길을 선택하도록

int sequenceSize1, sequenceSize2;  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        cin >> sequenceSize1;

        if(sequenceSize1 == 0) {
            break;
        }

        vector<int> sequence1, sequence2;
        
        for(int i = 0; i < sequenceSize1; i++) {
            int tmp;
            cin >> tmp;
            sequence1.push_back(tmp);
        }

        cin >> sequenceSize2;
        for(int i = 0; i < sequenceSize2; i++) {
            int tmp;
            cin >> tmp;
            sequence2.push_back(tmp);
        }

        vector<int> crossing; // 교차점의 값을 저장
        
        // 교차점을 찾아 값을 crossing에 저장
        for(int i = 0; i < sequenceSize1; i++) {
            for(int j = 0; j < sequenceSize2; j++) {
                if(sequence1[i] == sequence2[j]) {
                    crossing.push_back(sequence1[i]);
                }
            }   
        }

        // 교차점이 없는 경우
        if(crossing.empty()) {
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < sequenceSize1; i++) {
                sum1 += sequence1[i];
            }

            for(int i = 0; i < sequenceSize2; i++) {
                sum2 += sequence2[i];
            }

            cout << max(sum1, sum2) << '\n';
            continue;
        }

        vector<int> sequence1Sum, sequence2Sum;

        int index = 0;
        int size = crossing.size();
        int sum = 0;
        int i;

        for(i = 0; i < sequenceSize1; i++) {
            sum += sequence1[i];
            // 현재 보고 있는 수열의 항이 교차점인 경우
            if(sequence1[i] == crossing[index]) {
                sequence1Sum.push_back(sum);    // 합 저장
                sum = 0;    // 합을 0으로 초기화
                index++;    // 다음 교차점 확인
            }

            // 교차점의 마지막을 바라보면
            if(index == size) {
                break;
            }
        }

        sum = 0;
        for(int a = i + 1; a < sequenceSize1; a++) {
            sum += sequence1[a];
        }
        sequence1Sum.push_back(sum);


        index = 0;    
        sum = 0;
        for(i = 0; i < sequenceSize2; i++) {
            sum += sequence2[i];
            // 현재 보고 있는 수열의 항이 교차점인 경우
            if(sequence2[i] == crossing[index]) {
                sequence2Sum.push_back(sum);    // 합 저장
                sum = 0;    // 합을 0으로 초기화
                index++;    // 다음 교차점 확인
            }

            // 교차점의 마지막을 바라보면
            if(index == size) {
                break;
            }
        }

        sum = 0;
        for(int a = i + 1; a < sequenceSize2; a++) {
            sum += sequence2[a];
        }
        sequence2Sum.push_back(sum);
        
        // for(int i = 0; i < sequence1Sum.size(); i++) {
        //     cout << sequence1Sum[i] << ' ';
        // }
        // cout << endl;

        // for(int i = 0; i < sequence2Sum.size(); i++) {
        //     cout << sequence2Sum[i] << ' ';
        // }
        // cout << endl;

        int answer = 0;
        for(int i = 0; i < sequence1Sum.size(); i++) {
            answer += max(sequence1Sum[i], sequence2Sum[i]);
        }
        cout << answer << '\n';
    }

    return 0;
}