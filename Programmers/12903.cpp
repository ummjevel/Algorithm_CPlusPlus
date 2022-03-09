#include <string>
#include <vector>

using namespace std;

string solution(string answer) {
    string s;
    if (answer.length() % 2 == 0) {
        s = answer[answer.length() / 2 - 1];
        s += answer[answer.length() / 2];
    }
    else {
        s = answer[answer.length() / 2 ];
    }

    return s;
}

int main() {


    solution("qwer");

    return 0;
}

// 다른 풀이는 substr 사용.. ㅠㅠ