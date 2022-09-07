#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector<int> result;
    map<string, int> numbers;
    numbers["zero"] = 0;
    numbers["one"] = 1;
    numbers["two"] = 2;
    numbers["three"] = 3;
    numbers["four"] = 4;
    numbers["five"] = 5;
    numbers["six"] = 6;
    numbers["seven"] = 7;
    numbers["eight"] = 8;
    numbers["nine"] = 9;

    string words = "";
    for(int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            result.push_back(s[i] - '0');
            continue;
        }
        words += s[i];
        if (numbers.find(words) != numbers.end()) {
            result.push_back(numbers.find(words)->second);
            words = "";
        }
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    int mul = 1;
    for(int i = 0; i < result.size(); i++) {
        int it2 = result[result.size() - 1 - i];
        answer += ((it2) * mul);
        mul *= 10;
    }

    return answer;
}

int main() {

    solution("one4seveneight");

    return 0;
}

// 다른 풀이는 정규표현식 regex_replace 쓰고 마지막에 stoi 썼음..