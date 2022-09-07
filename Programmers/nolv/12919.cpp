#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    for(int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            string s = to_string(i);
            answer = "김서방은 " + s + "에 있다";
            break; 
        }
    }
    
    return answer;
}


int main() {

    vector<string> seoul = {"Jane", "Kim"};
    cout << solution(seoul) << endl;

    return 0;
}

// programmers 다른사람풀이 웃기니까 꼭 알려주고 넘어가자.