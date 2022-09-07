#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vec;

    // 3진수로 변환
    while(n/3 != 0) {
        vec.push_back(n%3);
        cout << n%3 << endl;
        n /= 3;
    }
    vec.push_back(n%3);
    // 앞에서부터 10진수로 변환해서 계산
    int decimal = 1;
    for(int i = vec.size() - 1; i >= 0; i--, decimal *= 3) {
        cout << vec[i] * decimal << endl;
        answer += vec[i] * decimal;
    }

    cout << "answer::::: " << endl;
    return answer;
}

int main() {
    cout << solution(45) << endl;
    return 0;
}

// 다른 풀이의 경우 계산하는 부분을 나처럼 for문이 아닌 while 문이면서 back(), pop_back()을 활용함.