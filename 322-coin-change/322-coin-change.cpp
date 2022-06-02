class Solution {
public:
    int dp[13][10001];
    int help(int i, int target, vector<int> &v)
    {
        if(target<=0)   return 0;
        if(i<0) return INT_MAX-1;
        if(dp[i][target]!=-1)   return dp[i][target];
        
        int take = INT_MAX;
        if(target >= v[i])
            take = help(i, target-v[i], v) + 1;
        int notTake = help(i-1, target, v);
        
        return dp[i][target] = min(take, notTake);
    }
    int coinChange(vector<int>& v, int target) {
        int n=v.size();
        memset(dp, -1, sizeof dp);
        int ans = help(n-1, target, v);
        return ans < 1e9 ? ans : -1;
    }
};