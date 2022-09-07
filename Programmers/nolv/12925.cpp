#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    
    if (s[0] == '-') {
        return (-1) * stoi(s.substr(1));
    }

    return stoi(s);
}

int main() {

    cout << solution("1234") << endl;

    return 0;
}

// 이상하게 기분 안좋게하는 문제. 똑같은 방법인데 안됐었음.
// - 는 cstlib 의 atoi 를 쓰면 그대로 쓸 수 있음.