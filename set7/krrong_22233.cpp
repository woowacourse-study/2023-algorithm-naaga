#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

int N, M;
unordered_set<string> keywords;

vector<string> split(string input, char dlim)
{
	vector<string> result;

	stringstream ss;
	string stringBuffer;
	ss.str(input);
	
	while (getline(ss, stringBuffer, dlim))	{
		result.push_back(stringBuffer);
	}

	return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        keywords.insert(tmp);
    }

    for(int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        vector<string> writing = split(tmp, ',');
        
        int size = writing.size();
        for(int j = 0; j < size; j++) {
            string key = writing[j];
            auto isFind = keywords.find(key);
            if(isFind != keywords.end()) {
                keywords.erase(isFind);
            }
        }

        cout << keywords.size() << '\n';
    }



    return 0;
}