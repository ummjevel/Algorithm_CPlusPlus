#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int i;

bool compare(string a, string b) {
    if (a[i] == b[i]) {
        return a < b;
    } else {
        return a[i] < b[i];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    i = n;
    sort(strings.begin(), strings.end(), compare);

    answer = strings;

    return answer;
}

int main() {

    vector<string> strings = {"sun", "bed", "car"};
    solution(strings, 1);

    return 0;
}

// compare 찾다가 봐버림. 전역 변수로 해당되는 i번째를 전달함.