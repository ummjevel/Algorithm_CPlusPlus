#include <string>
#include <vector>

using namespace std;

int GCM(int a, int b) {
    if (b % a == 0)
        return a;
    else {
        return GCM(b % a, a);
    }
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int small = n < m ? n : m;
    int big = n < m ? m : n;

    answer.push_back(GCM(small, big));
    answer.push_back((n * m) / answer[0]);

    return answer;
}

// 87.5 3, 16
//vector<int> solution(int n, int m) {
//    vector<int> answer;
//    int small = n < m ? n : m;
//    int big = n < m ? m : n;
//    int min = 1, max = 1;
//    for (int i = 1; i <= big; i++) {
//        if (small % i == 0 && big % i == 0) {
//            min *= i;
//            small = small / i;
//            big = big / i;
//        }
//    }
//
//    max = n * m / min;
//
//    answer.push_back(min);
//    answer.push_back(max);
//    return answer;
//}
// 다른 풀이에서는 큰 수부터 작은 수로 for문 돌리고, 둘 다 나머지가 0일 때 빠져나옴.

int main() {

    solution(2, 5);
    return 0;
}
