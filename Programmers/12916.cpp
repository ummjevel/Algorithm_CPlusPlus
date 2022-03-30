#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int temp = 0;
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == 'p' || s[i] == 'P')
            temp++;
        else if(s[i] == 'y' || s[i] == 'Y')
            temp--;
        i++;
    }

    // if (temp % 2 != 0) answer = false;
    
    // return answer;
    return temp ? false : true;
}