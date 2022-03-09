#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;

    while (n % answer != 1)
        answer++;

    return answer;
}

int main() {

    cout << solution(10) << endl;
    return 0;
}