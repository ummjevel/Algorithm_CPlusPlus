#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int cnt = 0;
int findPrime(int n) {
    for(int i = 2; i <= n; i++) {
        bool flag = true;
        for(int j = 2; j*j <= i; j++) {
            if (i%j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    findPrime(n);
    answer = cnt;
    return answer;
}

int main() {

    cout << solution(10) << endl;

    return 0;
}

// 어려운 프라임넘버..