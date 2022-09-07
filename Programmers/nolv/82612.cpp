#include <iostream>
#include <cmath>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for (int i = 1; i <= count; i++) {
        answer += price * i;
    }
    if (answer < money)
        return 0;
    answer = answer - money;
    return answer;
}

int main() {
    cout << solution(, , ) << endl;
    return 0;
}

// 범위 때문..!!!!!, 다른 풀이는 n*(n+1)/2 사용, 가우스 공식 이용.