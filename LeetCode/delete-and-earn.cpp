class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<int> values(max_val+1, 0);
        
        for(int num: nums) {
            values[num] += num;
        }
        
        int dp[max_val+ 1];
        dp[0] = values[0];
        dp[1] = max(values[0], values[1]);
        for(int i = 2; i < max_val + 1; i++) {
            dp[i] = max(dp[i-2] + values[i], dp[i-1]);
        }
        return max(dp[max_val], dp[max_val-1]);
    }
};