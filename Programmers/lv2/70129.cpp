#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer, temp;
    int totalCnt = 0;
    int zeroCnt = 0;
    string str;
    
    // 넣을 때 0 제거.
    while(s != "1") {

        int i = 0;
        str = "";
        while(i < s.size()) {
            if(s[i] == '0') {
                zeroCnt++;  // 제거한 0의 개수
            } else {
                str += s[i];
            }
            // temp.push_back(s[i]);
            
            i++;
        }
        
        // 2진법 변환
        int tempInt = str.length();
        s = "";
        
        cout << "str: " << str << ", zeroCnt: " << zeroCnt << ", tempInt: " << tempInt << endl;
        
        while (tempInt/2 >= 1) {
            s = to_string(tempInt%2) + s;
            tempInt = tempInt/2;
        }
        
        if (tempInt%2 <= 1)
            s = to_string(tempInt%2) + s;

        cout << s << endl;

        if (s != "1") totalCnt++;

        if (s == "1") break;
    }

    if (zeroCnt > 0) totalCnt++;

    answer.push_back(totalCnt);
    answer.push_back(zeroCnt);

    return answer;
}

int main() {
    solution("110010101001");
}