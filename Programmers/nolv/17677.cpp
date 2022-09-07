#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string toUpper(string str) {
    string result;

    for(int i = 0 ; i < str.length(); i++) {
        char c = toupper(str[i]);
        result += c;
    }
    return result;
}

vector<string> splitString(string str) {
    vector<string> result;

    for(int i = 0; i < str.length() - 1; i++) {
        string temp = str.substr(i, 2);
        if(isalpha(temp[0]) && isalpha(temp[1])) {
            
            result.push_back(toUpper(temp));
        }
    }
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> vecStr1, vecStr2;
    // 분리하고, 특수문자 있는 것은 제외하고 uppercase 해서 넣기
    vecStr1 = splitString(str1);
    vecStr2 = splitString(str2);

    // 합집합

    // 교집합

    // 

    return answer;
}

int main() {
    solution("aa1+aa2", "AAAA12");
}

// str1 = "FRANCE"
// str2 = "franch"

// s1 = set()
// s2 = set()
// for i in range(0, len(str1) - 1, 1):
//     temp = str1[i] + str1[i+1]
//     if temp.isalpha() == False:
//         continue
//     else:
//         s1.add(temp.lower())
        
// for i in range(0, len(str2) - 1, 1):
//     temp = str2[i] + str2[i+1]
//     if temp.isalpha() == False:
//         continue
//     else:
//         s2.add(temp.lower())
        
// s3 = s1.union(s2)
// s4 = s1.intersection(s2)

// count = int(len(s4)/len(s3) * 65536)

// print(count)