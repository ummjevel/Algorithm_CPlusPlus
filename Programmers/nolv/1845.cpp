#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    // 2 - 성공
    // set 이용! 
    set<int> s;
    for(int i = 0 ; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    if (s.size() < nums.size()/2) {
        answer = s.size();
    } else {
        // s.size() < nums.size()/2
        answer = nums.size()/2;
    }

    // 다른 풀이는 unordered_set와 min 을 사용!

    // 1 - 실패
    /*
    int size = nums.size();
    // 중복 제거
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    // 원래 개수의 /2가 되는지 확인, 작으면 작은 수 바로 반환.
    // 다른 풀이 참고한 되는 조건 -> 중복제거한 사이즈가 /2한 사이즈보다 작을 경우, 그대로 넣어주고, 아니면 /2한 사이즈로..
    if (nums.size() == size) {
        // 중복 없으므로 /2 한 값 바로 반환.
        answer = size/2;
    } else if (nums.size() < size) {
        if (nums.size() == size/2) {
            answer = size/2;
        } else if (nums.size() < size/2) {
            answer = nums.size();
        }
    }
    */
    return answer;
}

int main() {

    vector<int> nums = {3,1,2,3};
    cout << "answer is : " << solution(nums) << endl;
    
    return 0;
}