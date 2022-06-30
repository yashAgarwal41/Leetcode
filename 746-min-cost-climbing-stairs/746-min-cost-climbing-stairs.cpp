class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = cost[1], prev2 = cost[0];
        cost.push_back(0);
        for(int i=2; i<=n; i++)
        {
            int curr = min(prev, prev2) + cost[i];
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};