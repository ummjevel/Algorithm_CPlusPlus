#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string temp = to_string(n);

    for (int i = 0; i < temp.length(); i++) {
        answer += temp[i] - '0';
    }

    return answer;
}

int main() {

    solution(987);
    return 0;
}
