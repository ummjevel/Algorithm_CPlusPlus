#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000000;
    if (s.length() == 1)
        return 1;
        
    for(int i = 1; i <= s.length()/2; i++) {
        string temp = s;
        int innerCnt = 1;
        string tempAnswer = "";
        for(int j = 0; j < s.length(); j += i) {
            string current = temp.substr(j, i);
            string next = "";
            if (j + i < s.length())
                next = temp.substr(j + i, i);
            if (current.compare(next) == 0) {
                innerCnt++;
            } else {
                if(innerCnt != 1) {
                    tempAnswer += to_string(innerCnt);
                } 
                innerCnt = 1;
                tempAnswer += current;
            }
        }
        if(answer > tempAnswer.length()) answer = tempAnswer.length();
    }


    return answer;
}

int main() {
    solution("a");
    return 0;
}