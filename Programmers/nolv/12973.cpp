#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> stk;
    int i = s.size() - 1;
    while(i >= 0) {
        if (!stk.empty() && stk.top() == s[i])
            stk.pop(); 
        else
            stk.push(s[i]);
        i--;
    }
    
    if(stk.empty()) return 1;
    else return 0;
}

// 시간초과 나옴. 정확성은 통과.. 스택 이용해야 한다고 함..
// int solution(string s) {
//     // vector<string> v = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", "nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"};
   
//     int i = 0;
//     while(true) {    
        
//         if(s.empty() || i >= s.length()) {
//             break;
//         } 
//         if(s[i] == s[i + 1]) {
//             cout << s << endl;
//             s.erase(i, 2);
//             i = -1;
//         }
//         i++;
//     }
    
//     if (s.length() == 0) {
//         return 1;
//     } else {
//         return 0;
//     }
    
//     return 0;
// }

int main() {
    cout << solution("baabaa") << endl;
    return 0;
}




// int solution(string s)
// {
//     int answer = -1;
//     int i  = 1;
//     string temp = s;
//     int j = 1;
//     while(true) {
//         if (temp.length() == 0) {
//             answer = 1;
//             break;
//         }
//         else {
//             if(temp[i - 1] == temp[i]) {
//                 cout << "temp[i-1] == temp[i] : " << temp[i-1] << temp[i] << endl;
//                 string front = temp.substr(0, i - 1);
//                 string back = temp.substr(i+1, temp.length() - (i + 1));
//                 cout << "front: " << front << ", back: " << back << endl;
//                 temp = front + back;
//                 cout << "temp : " << temp << endl;
//                 i -= 2;
//                 j += 2;
//             } else if (j == s.length()) {
//                 answer = 0;
//                 break;
//             }
//             i++;
//             j++;
//         }
        
//     }

//     return answer;
// }
