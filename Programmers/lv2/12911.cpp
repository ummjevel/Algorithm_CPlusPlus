#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convertBinary(int n) {
    string binary = "";

    while(n/2 >= 1) {
        binary = to_string(n%2) + binary;
        n = n/2;
    }

    binary = to_string(n%2) + binary;

    return binary;
}

int getOneCount(string binary) {
    int count = 0;
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == '1') count++;
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    
    // 1의 개수
    int oneCnt = getOneCount(convertBinary(n));
    int tempOneCnt = 0;
    
    while(1) {
        tempOneCnt = getOneCount(convertBinary(++n));
        if (oneCnt == tempOneCnt) {
        // if (oneCnt == getOneCount(convertBinary(++n))) {
            break;
        }
    }

    return n;
}

int main() {

    cout << solution(78) << endl;

    return 0;

}