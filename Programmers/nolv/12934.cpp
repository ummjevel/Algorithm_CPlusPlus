#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
        
    if (sqrt(n) == int(sqrt(n))) {
        return (sqrt(n) + 1) * (sqrt(n) + 1);
    } else
        return -1;
    
}

// 83.3 : 3, 6, 13

// long long solution(long long n) {
//     long long answer = 0;
        
//     if (sqrt(n) * sqrt(n) == n) {
//         return (sqrt(n) + 1) * (sqrt(n) + 1);
//     } else
//         return -1;
    
// }