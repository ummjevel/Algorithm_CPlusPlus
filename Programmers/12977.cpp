#include <vector>
#include <iostream>
using namespace std;

int is_prime(int number) {
    for(int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;

    for(int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                //cout << "nums(i,j,k) : " << nums[i] << ", " << nums[j] << ", " << nums[k] << endl;
                if (is_prime(sum))
                    answer++;
                else {
                    // cout << "sum is not prime : " << sum << endl;
                }
            }
        }
    }
    cout << "answer : " << answer << endl;
    return answer;
}

int main() {

    vector<int> nums = {1,2,3,4};
    solution(nums);

    return 0;
}