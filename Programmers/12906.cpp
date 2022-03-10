#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (!answer.empty() && answer.back() == arr[i])
            continue;
        answer.push_back(arr[i]);
    }
    return answer;
}

int main() {

    vector<int> arr = { 1,1,3,3,0,1,1 };
    solution(arr);

    return 0;
}

// erase, unique 사용하면 됐는데...