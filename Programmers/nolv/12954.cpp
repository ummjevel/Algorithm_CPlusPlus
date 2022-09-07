#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int temp = x;
    while(n > 0) {
        answer.push_back(x);
        x += temp;
        n--;
    }
    
    return answer;
}