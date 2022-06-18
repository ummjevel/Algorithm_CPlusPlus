#include <vector>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 10, 15, 20, 0
        // 0,  1,  2,  3
        cost.push_back(0);
        for(int i = cost.size() - 3; i >= 0; i--) {
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        return min(cost[0], cost[1]);
    }
};