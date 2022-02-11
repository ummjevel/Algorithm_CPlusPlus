#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    while(!lost.empty()) {
        auto it = lost.end();
        auto it1 = find(reserve.begin(), reserve.end(), *(it)-1);
        auto it2 = find(reserve.begin(), reserve.end(), *(it)+1);
        auto it3 = find(reserve.begin(), reserve.end(), *(it));
        if (it3 != reserve.end()) {
            reserve.erase(reserve.begin() + distance(reserve.begin(), it));
            continue;
        }
        if (it1 != reserve.end()) {
            reserve.erase(reserve.begin() + distance(reserve.begin(), it1));
        } else if (it2 != reserve.end()) {
            reserve.erase(reserve.begin() + distance(reserve.begin(), it2));
        } else {
            answer--;
        }
        lost.pop_back();
    }

    return answer;
}

int main() {
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    
    int result = solution(n, lost, reserve);
    cout << result << " ";
    cout << endl;
    return 0;
}