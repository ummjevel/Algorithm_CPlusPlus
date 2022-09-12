#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

// // 44
// string solution(string s) {
//     string answer = "";

//     // 입력받기
//     string str;
//     stringstream ss(s);
//     while(ss >> str) {
//         if(isdigit(str[0]) == 0) {
//             if (islower(str[0]))
//                 str[0] = toupper(str[0]);
//         }
//         for(int i = 1; i < str.size(); i++) {
//             if (isupper(int(str[i])))
//                 str[i] = tolower(str[i]);
//         }
//         // str.erase(remove(str.begin(), str.end(), ' '), str.end());
//         answer +=  str + " ";
//     }

//     if (s[s.length() - 1] != ' ' && s.length() > 1)
//         answer = answer.substr(0, answer.length() - 1);

//     return answer;
// }

// 3개만 맞는다../;;;

// string solution(string s) {
//     string answer = "";

//     bool isPreviousSpace = true;
//     int i = 0;
//     while(i < s.size()) {
//         if(s[i] == ' ') {
//             isPreviousSpace = true;
//         }
//         else if (!isdigit(s[i])) {
//             if(isPreviousSpace && islower(s[i])) {
//                 s[i] = toupper(s[i]);
//                 isPreviousSpace = false;
//             }
//             else if (!isPreviousSpace && isupper(s[i])) {
//                 s[i] = tolower(s[i]);
//                 isPreviousSpace = false;
//             }
//         } else {
//             isPreviousSpace = false;
//         }
//         answer += s[i];
//         i++;
//     }
//     return s;
// }

string solution(string s) {
    string answer = "";
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.length(); i++) {
        if(s[i-1] == ' ') {
            s[i] = toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }
    }

    answer = s;

    return answer;
}

int main() {
    cout << solution(" A A A      A A     a   ");
    return 0;
}