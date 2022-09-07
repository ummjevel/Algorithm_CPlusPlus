#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long ltemp = (long)num;
    while (answer < 500 && ltemp != 1) {
        if (ltemp % 2 == 0) {
            ltemp /= 2;
        }
        else {
            ltemp = ltemp * 3 + 1;
        }
        answer++;
    }

    if (ltemp != 1)
        answer = -1;

    return answer;
}