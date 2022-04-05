#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    answer = answer / arr.size();
    
    return answer;
}

int main() {

    vector<int> arr = {1,2,3,4};
    cout << solution(arr) << endl;

    return 0;
}