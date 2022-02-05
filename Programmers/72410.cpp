#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    regex re3("[.]+");
    regex re2("[^-.\\w]");
    cout << new_id << endl;
    // 1. 대문자 -> 소문자
    for (int i = 0; i < new_id.length(); i++) {
        int curr_val = int(new_id[i]);
        if (65 <= curr_val && curr_val <= 90) {
            new_id[i] = char(int(new_id[i]) + 32); // 97 - 65 = 32
        }
    }
    cout << "1. " << new_id << endl;
    // 2. 소문자, 숫자, 빼기, 밑줄, 마침표 제외
    new_id = regex_replace(new_id, re2, "", regex_constants::match_default);
    cout << "2. " << new_id << endl;
    // 3. 마침표 연속 -> 하나로 치환
    new_id = regex_replace(new_id, re3, ".", regex_constants::match_default);
    cout << "3. " << new_id << endl;
    // 4. 마침표 앞뒤 위치 시 삭제
    if (new_id[0] == '.') {
        new_id = new_id.substr(1, new_id.length() - 1);
    }
    if (new_id[new_id.length() - 1] == '.') {
        new_id = new_id.substr(0, new_id.length() - 1);
    }
    cout << "4. " << new_id << endl;
    // 5. 빈 문자열이면  a 대입
    if (new_id.empty()) {
        new_id = "a";
    }
    cout << "5. " << new_id << endl;
    // 6. 16자 이상이면 15개만 남기고, 제거 후 마침표가 끝에 위치할 경우 제거
    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
    }
    if (new_id[new_id.length() - 1] == '.') {
        new_id = new_id.substr(0, new_id.length() - 1);
    }
    cout << "6. " << new_id << endl;
    // 7. 2자 이하시 길이가 3이 될 때까지 마지막 문자 반복
    if (new_id.length() <= 2) {
        char last_char = new_id.substr(new_id.length() - 1, 1)[0];
        while(new_id.length() < 3)
            new_id += last_char;
    }
    cout << "7. " << new_id << endl;
    cout << new_id << endl;
    
    return answer;
}

int main() {

    string new_id = "123_.def";

    solution(new_id);

    return 0;
}