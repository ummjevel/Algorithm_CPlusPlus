#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int result = 0;

    vector<string> vec = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    vector<int> month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 1; i < a; i++) {
        result += month[i];
    }
    result += b;

    answer = vec[result%7];

    return answer;
}

int main() {

    cout << solution(5, 24) << endl;
    return 0;
}