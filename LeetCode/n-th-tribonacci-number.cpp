#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        int T[n+1];
        T[0] = 0;
        if (n == 0)
            return T[0];
        T[1] = 1;
        if (n == 1)
            return T[1];
        T[2] = 1;
        for(int i = 3; i <= n; i++) {
            T[i] = T[i-3] + T[i-2] + T[i-1];
        }
        return T[n];
    }
};