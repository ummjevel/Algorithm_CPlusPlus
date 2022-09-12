#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    long long max = -10000000; long long min = 10000000;
    long long temp;
    stringstream ss(s);
    while(ss >> temp) {
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }

    cout << min << " " << max;

    answer = to_string(min) + " " + to_string(max);

    return answer;
}

int main() {
    solution("-1 -1");
    return 0;
}