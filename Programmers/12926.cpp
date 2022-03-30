#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++) {
        // space
        if (s[i] == ' ')
            answer += " ";
        // 글자가 Z-A
        else if(isupper(s[i]) && int(s[i]) + n > 90) {
            answer += char(int(s[i]) + n - 90 + 64);
        }
        // 글자가 z-a
        else if(islower(s[i]) && int(s[i]) + n > 122) {    
            answer += char(int(s[i]) + n - 122 + 96);
        }
        else {
            answer += char(int(s[i]) + n);
        }
    }
    
    return answer;
}