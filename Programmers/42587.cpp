#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<int> priority;
    priority.assign(priorities.size(), 0);
    priority[location] = 1;

    

    int i = 0;
    while(priority[i] != 1) {
        i++;
    }
    answer = ++i;

    return answer;
}

int main() {
    vector<int> priorities = {2, 1, 2, 1, 2, 1, 2, 1};
    int location = 1;
    solution(priorities, location);
    return 0;
}