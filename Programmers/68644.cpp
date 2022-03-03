#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    sort(numbers.begin(), numbers.end());

    for(int i = 0 ; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

int main() {
    vector<int> numbers = {2,1,3,4,1};
    solution(numbers);
}

// 다른 풀이 set 을 사용, 나도 사용하려다 말았는데..^^, 마지막에 assign(처음, 나중)으로 한방에..