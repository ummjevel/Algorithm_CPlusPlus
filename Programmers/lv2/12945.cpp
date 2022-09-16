#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {

    long long numbers[100001] = {0, };
    numbers[0] = 0;
    numbers[1] = 1;
    numbers[2] = 1;

    for(int i = 2; i <= n; i++) {
        numbers[i] = numbers[i - 1] % 1234567 + numbers[i - 2] % 1234567;
    }

    return numbers[n] % 1234567;
}

int main() {
    cout << solution(100000);
}