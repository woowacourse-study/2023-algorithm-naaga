#include <iostream>
#include <string>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    cin >> str;

    string tmp1, tmp2;

    for(int i = 1; i <= N; i++){
        int sameCount = 0;
        tmp1.assign(str.begin(), str.begin() + i);
        tmp2.assign(str.end() - i, str.end());

        for(int j = 0; j < i; j++) {
            if(tmp1[j] != tmp2[j]) {
                sameCount++;
            }
        }
            
        if(sameCount == 1){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}