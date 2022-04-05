
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    cout << answer << endl;
    for(int i = 1; i < s.length() /2; i++) {
        // int cnt = 0;        // 축약된 횟수
        int innerCnt = 1;   // 
        string tempAnswer = "";
        for(int j = 0; j < s.length(); j += i) {

            cout << i << " : " << j << endl;
            string current = s.substr(j, i);
            string next = "";
            if (j + i < s.length()) {
                next = s.substr(j + i, i);
            }

            if (current == next) {
                innerCnt++;
            } else {
                if (innerCnt != 1) {
                    // cnt++;
                    tempAnswer += to_string(innerCnt);
                } 
                innerCnt = 1;
                tempAnswer += current;
            }
        
        }
            cout << "tempAnswer : " << tempAnswer << endl;
        if (answer > tempAnswer.length())
            answer = tempAnswer.length();

    }
    
    return answer;
}

// 안됨. 이전-현재가 아닌 현재-다음 으로 위처럼 바꿔야..
// int solution(string s) {
//     int answer = s.length();
//     cout << answer << endl;
//     for(int i = 1; i < s.length(); i++) {
//         int cnt = 0; // 축약된 횟수
//         int innerCnt = 1;
//         string tempAnswer = "";
//         string sPrevious = s.substr(0, i);
//         int iPrevious = 0;
//         for(int j = i; j <= s.length(); j += i) {

//             if (sPrevious == s.substr(j, i)) {
//                 innerCnt++;
                
//             } else {
//                 if (innerCnt != 1) {
//                     cnt++;
//                     tempAnswer += to_string(innerCnt);
//                 }
//                 innerCnt = 1;
//                 tempAnswer += sPrevious;
                
//             }
//             cout << sPrevious<< endl;
//                 cout << s.length() << j << endl;  
//             sPrevious = s.substr(j, i);
        
//         }
//         if (answer > tempAnswer.length())
//             answer = tempAnswer.length();

//     }
    
//     return answer;
// }

int main() {
    cout << solution("aabbaccc") << endl;

    return 0;
}