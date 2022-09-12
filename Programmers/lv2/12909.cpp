#include<string>
#include <iostream>

using namespace std;

// bool solution(string s)
// {
//     int i = 0;
//     int temp = 0;
    
//     if (s[0] == ')') return false;
//     else {
//         while(i < s.size()) {
//             if(s[i] == '(') temp++; 
//             else if(s[i] == ')') temp--;
//             i++;
//         }
    
//         if (temp == 0)
//             return true;
//         else    
//             return false;
//     }
// }
// 테스트케이스와 효율성에서 일부 틀림.

// 중간에 닫힌 가로 개수가 더 많다면 무조건 false로.
bool solution(string s)
{
    int i = 0;
    int temp = 0;
    
    if (s[0] == ')') return false;
    else {
        while(i < s.size()) {
            if(s[i] == '(') temp++; 
            else if(s[i] == ')') temp--;
            i++;
            if (temp < 0) return false;
        }
    
        if (temp == 0)
            return true;
        else    
            return false;
    }
}

int main() {
    cout << solution("())()(()");
    return 0;
}