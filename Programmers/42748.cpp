#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        // 범위로 새로 넣기
        vector<int> temp;
        temp.insert(temp.end(), array.begin() + (commands[i][0] - 1), array.begin() + (commands[i][1]));
        // 정렬
        sort(temp.begin(), temp.end());
        // n 번째 숫자
        answer.push_back(*(temp.begin() + commands[i][2] - 1));
    }
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {
        {2, 5, 3}, {4, 4, 1}, {1, 7, 3}
    };
    vector<int> result = solution(array, commands);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}