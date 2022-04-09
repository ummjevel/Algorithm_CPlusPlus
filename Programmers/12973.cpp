#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(string s) {
    vector<string> v = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", "nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"};
    
    int i = 0;
    while(true) {    
        
        if(s.length() == 0) {
            break;
        } 
        if(s[i] == s[i + 1]) {
            cout << s << endl;
            s.erase(i, 2);
            i = 0;
            cout << s << endl;
        }
        i++;
    }
    
    
    if(s[0] == s[1]) {
        cout << "aaaaa" << endl;
        return 1;
    } else {
        cout << s.length() << endl;
    }
    return 0;
}

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
