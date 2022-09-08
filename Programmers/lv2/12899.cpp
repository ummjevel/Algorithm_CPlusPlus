#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    // 3진법인데 3일 경우 4로 표시.
    if( n == 1)
        return "1";
    else if (n == 2)
        return "2";
    else if (n == 3)
        return "4";
    else {
        int na;
        // 나눠서 나오는 몫을 왼쪽으로 붙이기. 나머지 주의.
        while(n/3 != 0 && n > 3) {
            na = n%3;
            
            if (na == 0) answer = "4" + answer;
            else if (na == 1) answer = "1" + answer;
            else if (na == 2) answer = "2" + answer;

            n = n - 1;
            n /= 3;
        }
        na = n%3;
        if (na == 1 || na == 2)
            answer = to_string(na) + answer;
        else if (na == 0)
            answer = "4" + answer;
    }

    return answer;
}

int main() {

    solution(12);
    return 0;
}