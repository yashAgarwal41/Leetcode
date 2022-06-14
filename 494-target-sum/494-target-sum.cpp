class Solution {
public:
    int dp[21][2005];
    int help(int i, int sum, int &target, vector<int> &v)
    {
        if(i<0)
            return sum==target;
        
        if(sum>=0 and dp[i][sum]!=-1)   return dp[i][sum];
        if(sum<0 and dp[i][1000-sum]!=-1)   return dp[i][sum];
        
        int add = help(i-1, sum+v[i], target, v);
        int sub = help(i-1, sum-v[i], target, v);
        
        if(sum<0)   return dp[i][1001 - sum] = add + sub;
        else return dp[i][sum] = add + sub;
    }
    int findTargetSumWays(vector<int>& v, int target) {
        int n=v.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, 0, target, v);
    }
};