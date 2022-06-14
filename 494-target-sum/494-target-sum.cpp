class Solution {
public:
    int dp[21][1001];
    int total=0;
    int help(int i, int sum1, int &target, vector<int> &v)
    {
        if(i<0)
        {
            int remaining = total - sum1;
            if(sum1-remaining == target)    return 1;
            else return 0;
        }
        if(dp[i][sum1]!=-1) return dp[i][sum1];
        
        int pick = help(i-1, sum1+v[i], target, v);
        int notPick = help(i-1, sum1, target, v);
        
        return dp[i][sum1] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& v, int target) {
        int n=v.size();
        for(int i=0; i<n; i++)  total+=v[i];
        memset(dp, -1, sizeof dp);
        return help(n-1, 0, target, v);
    }
};