#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isEven = true;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            answer += " ";
            isEven = true;
            continue;
        }
            
        answer += isEven ? toupper(s[i]) : tolower(s[i]);
        isEven = !isEven;
    }
    
    return answer;
}