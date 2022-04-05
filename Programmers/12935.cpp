#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
    }
    else {
        int min = arr[0];
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] < min)
                min = arr[i];
            i++;
        }
        answer = arr;
        answer.erase(remove(answer.begin(), answer.end(), min), answer.end());
    }
    return answer;
}