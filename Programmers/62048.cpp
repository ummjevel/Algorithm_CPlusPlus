#include <iostream>

using namespace std;

long gcd(int w, int h) {
    int small = w < h ? w : h;
    int big = w < h ? h : w;
    long temp = small;
    while(true) {
        if (small % temp == 0 && big % temp == 0)
            break;
        temp--;
    }

    return temp;
}

long long solution(int w, int h) {
    return (long long)w * h - (w + h - gcd(w, h));
}

int main() {
    cout << solution(8, 12) << endl;

    return 0;
}

// https://taesan94.tistory.com/55

/*
// 정확도 66.7
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double slope = (double)h/w;
    for(long long i = 1; i <= w; i++) {
        answer += ceil(slope * i);
    }
    answer = (w*h - answer) * 2;
    return answer;
}
*/