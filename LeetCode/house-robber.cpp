#include <vector>

class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        if (nums.size() == 1) {
            return nums[0];
        } 
        
        vector<int> temp;
        temp.assign(nums.size() + 1, 0);
        temp[0] = nums[0];
        temp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            temp[i] = max(temp[i-2] + nums[i], temp[i-1]);
        }
        
        return temp[nums.size() - 1];
    }
};