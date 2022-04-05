#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool compare(char &a, char &b) {
    return a > b;
}

string solution(string s) {
    string answer = "";
    
    vector<char> v;
    for(int i = 0; i < s.length(); i++) v.push_back(s[i]);
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < s.length(); i++) answer += v[i];
    
    return answer;
}


int main() {

    cout << solution("Zbcdefg") << endl;

    return 0;
}

// vector에 안넣고 string 그대로 sort에 넣어도 됩니다.
// 까무러치는 방법:
// sort(s.rbegin(),s.rend());