#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int i = 0;
    vector<int> values = {0,0,0};
    int Idx = 0;
    while (i < dartResult.length()) {

        string number = "";
        string section = "";    // s, d, t
        string option = "";     // *, #
        int iNumber = 0;
        int temp = 0;
        // 입력 받은 것 구분
        while (!isalpha(dartResult[i])) {
            number += dartResult[i];
            i++;
        }
        section = dartResult[i++];
        iNumber = stoi(number);
        if (!isdigit(dartResult[i])) {
            option = dartResult[i++];
        }

        if (section == "S") {
            temp = iNumber;
        }
        else if (section == "D") {
            temp = pow(iNumber, 2);
        }
        else if (section == "T") {
            temp = pow(iNumber, 3);
        }

        values[Idx] = temp;
        Idx++;

        if (option == "*") {
            if (Idx == 1) {
                values[0] *= 2;
            }
            else {
                values[Idx - 1] *= 2;
                values[Idx - 2] *= 2;
            }
        }
        else if (option == "#") {
            values[Idx - 1] *= -1; 
        }
    }

    for (int i = 0; i < 3; i++) answer += values[i];
    
    return answer;
}
int main() {


    cout << solution("1D2S3T*") << endl;

    return 0;
}
