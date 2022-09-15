#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    // sort
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // min * max +
    for(int i = 0; i < A.size(); i++) {
        answer += A[i] * B[B.size() - i - 1];
    }
    
    return answer;
}

int main() {
    vector<int> A = {1, 4, 2};
    vector<int> B = {5, 4, 4};
    cout << solution(A, B);
    return 0;
}