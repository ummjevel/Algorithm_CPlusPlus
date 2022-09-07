#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> command, uid;
    string stringBuffer;
    map<string, string> map;
    
    for(int i = 0; i < record.size(); i++) {
        istringstream ss(record[i]);
        string str1, str2, str3;
        ss >> str1 >> str2 >> str3;
        command.push_back(str1);
        uid.push_back(str2);
        if (command[i] == "Enter" || command[i] == "Change")
            map[str2] = str3;
    }

    // 출력
    for(int i = 0; i < record.size(); i++) {
        if (command[i] == "Change") {

        } else {
            string str1 = map.find(uid[i])->second;
            string str2;
            if (command[i] == "Enter") {
                str2 = "님이 들어왔습니다.";
            } else if (command[i] == "Leave") {
                str2 =  "님이 나갔습니다.";
            } 
            answer.push_back(str1 + str2);
        }
    }
    return answer;
}

int main() {
    vector<string> vec = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(vec);
    return 0;
}