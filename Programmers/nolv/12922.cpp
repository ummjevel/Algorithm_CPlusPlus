#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    string temp1 = "수", temp2 = "박";
    bool isOne = true;
    while(n > 0) {
        if(isOne)
            answer += temp1;
        else
            answer += temp2;
        n--;
        isOne = !isOne;
    }

    return answer;
}

int main() {

    cout << solution(3) << endl;

    return 0;
}