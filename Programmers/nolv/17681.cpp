#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2진수 변환
vector<int> convertToBinary(int number, int n) {
    vector<int> answer;

    for (int i = 0; i < n; i++) answer.push_back(0);

    while (n-1 >= 0) {
        answer[n-1] = number % 2;
        number = number / 2;
        n--;
    }

    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> a1, a2;
    string s = "";
    // 2진수 변환
    for (int i = 0; i < n; i++) {
        a1 = convertToBinary(arr1[i], n);
        a2 = convertToBinary(arr2[i], n);

        for (int j = 0; j < n; j++) {
            if (a1[j] == 1 || a2[j] == 1) {
                s += "#";
            }
            else {
                s += " ";
            }
            
        }
        answer.push_back(s);

        a1.clear();
        a2.clear();
        s = "";

    }

    return answer;
}

int main() {

    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };
    solution(5, arr1, arr2);

    return 0;
}

// 다른 풀이는 비트연산자 쓰고 string이니까 앞에 붙이는 형식으로 했음..