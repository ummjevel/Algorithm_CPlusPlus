#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    if (b < a) {
        int swap;
        swap = a;
        a = b;
        b = swap;
    }
    
    for(int i = a; i <= b; i++)
        answer += i;
    
    
    return answer;
}

// 다른 사람 풀이랑 똑같음 ㅎㅎ