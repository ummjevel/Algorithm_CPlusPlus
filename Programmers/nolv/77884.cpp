#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isEven(int number) {
    int cnt = 0;

    for(int i = number; i >= 1; i--) {
        if(number%i == 0)
            cnt++;
    }

    if (cnt%2 == 0)
        return true;
    else
        return false;
}

int solution(int left, int right) {
    int answer = 0;

    for(int i = left; i <= right; i++) {
        if(isEven(i)) {
            answer += i;
        } else {
            answer -= i;
        }
    }

    return answer;
}

int main() {
    int left = 24;
    int right = 27;
    cout << solution(left, right) << endl;
}