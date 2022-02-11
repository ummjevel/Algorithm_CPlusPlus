#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> supo1 = {1, 2, 3, 4, 5};
    vector<int> supo2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> supo3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int idx_supo1 = 0, idx_supo2 = 0, idx_supo3 = 0;
    int sum_supo1 = 0, sum_supo2 = 0, sum_supo3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        
        if (answers[i] == supo1[idx_supo1])
            sum_supo1++;
        if (answers[i] == supo2[idx_supo2])
            sum_supo2++;
        if (answers[i] == supo3[idx_supo3])
            sum_supo3++;

        idx_supo1 = (idx_supo1+1)%5;
        idx_supo2 = (idx_supo2+1)%8;
        idx_supo3 = (idx_supo3+1)%10;
            
    }
    cout << sum_supo1 << ", " << sum_supo2 << ", " << sum_supo3 << endl;
    // 비교, 큰 수부터 오름차순.
    if (sum_supo1 == sum_supo2 && sum_supo1 == sum_supo3) {
        answer = {1,2,3};
    } else if (sum_supo1 < sum_supo2 && sum_supo2 == sum_supo3) {
        answer = {2,3};
    } else if (sum_supo2 < sum_supo1 && sum_supo1 == sum_supo3) {
        answer = {1,3};
    } else if (sum_supo3 < sum_supo1  && sum_supo1 == sum_supo2) {
        answer = {1,2};
    } else {
        answer.push_back(sum_supo1 < sum_supo2 ? (sum_supo2 < sum_supo3 ? 3 : 2) : (sum_supo1 < sum_supo3 ? 3 : 1));
    }
    return answer;
}

int main() {
    vector<int> answers = {1, 2, 3, 4, 5};
    
    vector<int> result = solution(answers);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}

// 14번 case : 1, 2, 1, 1, 2 -> 3