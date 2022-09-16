#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = 1, pivot = 1, pivot2 = 1;
    
    while(pivot <= n) {
        if (temp == n) {
            answer++;
        }

        if (temp >= n) {
            pivot++;
            pivot2 = pivot;
            temp = pivot2;
        } else {
            temp += pivot2 + 1;
            pivot2++;
        }
    }

    return answer;
}

int main() {
    cout << solution(15);
    return 0;
}