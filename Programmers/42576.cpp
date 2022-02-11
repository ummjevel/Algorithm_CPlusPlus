#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // 1 효율성 테스트에서 실패..
    /*
    for(int i = 0; i < participant.size(); i++) {
        auto it = find(completion.begin(), completion.end(), participant[i]);
        if (it != completion.end()) {
            completion.erase(completion.begin() + distance(completion.begin(), it));
            continue;
        } else {
            answer = participant[i];
            break;
        }
    }*/
    // 2 hash 사용해서 다시..
    
    unordered_map<string, int> hash;

    for(int i = 0 ; i < participant.size(); i++) {
        if (hash.find(participant[i]) == hash.end())
            hash.insert(make_pair(participant[i], 1));
        else {
            
            auto it = hash.find(participant[i]);
            if (it != hash.end())
                it->second++;
                
        }
    }
/*
    for(unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }
*/
    for(int i = 0; i < completion.size(); i++) {
        auto it = hash.find(completion[i]);
        if (it != hash.end()) {
            it->second -= 1;
        }
    }
/*
    for(unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }
*/

    for(unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); it++) {
        if (it->second != 0) {
            answer = it->first;
        }
    }

    return answer;
}

int main() {

    vector<string> participant = {"mislav", "stanko", "mislav", "ana"}; // {"leo", "kiki", "eden"};
    vector<string> completion = {"stanko", "ana", "mislav"}; // {"eden", "kiki"};
    cout << solution(participant, completion) << endl;

    return 0;
}