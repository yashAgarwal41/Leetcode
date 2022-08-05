class Solution {
public:
    int dp[201][1001];
    int help(int i, int target, vector<int> &v, int n)
    {
        if(target==0)   return 1;
        if(i<0 or target<0) return 0;
        if(dp[i][target]!=-1)   return dp[i][target];
        
        int pick = 0;
        if(target>=v[i]) pick = help(n-1, target-v[i], v, n);    //have to take all permutations
        int notPick = help(i-1, target, v, n);
        
        return dp[i][target] = pick + notPick;
    }
    int combinationSum4(vector<int>& v, int target) {
        int n = v.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, target, v, n);
    }
};