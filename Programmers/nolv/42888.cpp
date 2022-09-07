#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> map;
    for(int i = 0; i < record.size(); i++) {
        vector<string> vec;
        stringstream ss(record[i]);
        string temp;
        while(getline(ss, temp, ' ')) {
            vec.push_back(temp);
        }
        if (vec[0] == "Enter" || vec[0] == "Change") {

            map[vec[1]] = vec[2];
        }
    }

    for(int i = 0; i < record.size(); i++) {
        vector<string> vec;
        stringstream ss(record[i]);
        string temp;
        while(getline(ss, temp, ' ')) {
            vec.push_back(temp);
        }
        if (vec[0] == "Enter") {
            answer.push_back(map[vec[1]] + "님이 들어왔습니다.");

        } else if (vec[0] == "Leave") {
            answer.push_back(map[vec[1]] + "님이 나갔습니다.");
        }
    }

    return answer;
}

// 시간초과

// string findNick = "";

// vector<string> solution(vector<string> record) {
//     vector<string> answer;
//     vector<pair<string, string> > pairAnswer;
//     vector<pair<string, string> > nickname;
    
//     for(int i = 0; i < record.size(); i++) {
//         vector<string> vec;
//         stringstream ss(record[i]);
//         string temp;
//         while(getline(ss, temp, ' ')) {
//             vec.push_back(temp);
//         }
        
//         if (vec[0] == "Leave") {
//             pairAnswer.push_back(make_pair(vec[1], "님이 나갔습니다."));
//         } else {
//             if (vec[0] == "Enter") {
//                 pairAnswer.push_back(make_pair(vec[1], "님이 들어왔습니다."));
//             }
            
//             if (!nickname.empty()) {
//                 findNick = vec[1];
               
//                 // 닉네임 변경
//                 nickname.erase(remove_if(nickname.begin(), nickname.end(), [](const auto& p) { 
//                     return p.first == findNick; 
                    
//                 }), nickname.end());
//             }
//             nickname.push_back(make_pair(vec[1], vec[2]));
//         }
//     }
    
//    for(pair<string, string> &nick : nickname) {
//        cout << nick.first << ", " << nick.second << endl;
//    }
    
//     for(pair<string, string> &p : pairAnswer) {
//         for(pair<string, string> &nick : nickname) {
//             if(p.first == nick.first) {
//                 string s(nick.second + p.second);
//                 p.second = s;
//             }
//         }
//         answer.push_back(p.second);
//     }
    
//     return answer;
// }

int main() {
    vector<string> answer;
    vector<string> vec= {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    answer = solution(vec);
    
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}