#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    for(int i = 0 ;i < d.size(); i++)
        cout << d[i] << endl;

    return answer;
}

int main() {

    vector<int> d = {1,3,2,5,4};
    int budget = 9;
    cout << solution(d, budget) << endl;
    return 0;
}