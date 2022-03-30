#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    string temp = to_string(x);

    for (int i = 0; i < temp.length(); i++) {
        sum += temp[i] - '0';
    }

    return x % sum == 0 ? true : false;
}

int main() {

    cout << solution(18) << endl;
    return 0;
}
