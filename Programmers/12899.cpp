#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    
    
    if (n < 3) {
         answer = to_string(n);
         return answer;
     } else if (n == 3) {
         answer = to_string(4);
         return answer;
     }
    int temp;
    // 3진법이라고 생각하고 풀기
    while(n/3 != 0 && n > 3) {
        
        temp = n%3;
        if (temp == 0) temp = 4;
        else if (temp == 1) temp = 1;
        else if (temp == 2) temp = 2;
        n = n - 1; // key!!!
        n = n/3;
        answer = to_string(temp) + answer;
    }
    
    temp = n%3;
    
    if (temp == 0) temp = 4;
    else if (temp == 1) temp = 1;
    else if (temp == 2) temp = 2;
    answer = to_string(temp) + answer;
    
    // cout << "---" << answer << endl;

    return answer;
}

int main() {
    cout << solution(6) << endl;
    return 0;
}

// key!!! 라고 표시한 부분은 질문하기에서 참고하여 풀었음. 0이 필요없기 때문에(이건 알았는데) 몫이 나눠졌을 때 하나 빼줘야 한다고 함..