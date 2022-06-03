class Solution {
public:
    //Memoization..TC-O(n*target)
    int n;
    int dp[201][1001];
    int help(int i, int tar, vector<int> &v)
    {
        if(tar==0)  return 1;
        if(i<0 or tar<0) return 0;
        if(dp[i][tar]!=-1)  return dp[i][tar];
        
        int take = 0;
        if(tar>=v[i])   take = help(n-1, tar-v[i], v);
        int notTake = help(i-1, tar, v);
        
        return dp[i][tar] = take + notTake;
    }
    int combinationSum4(vector<int>& v, int target) {
        n=v.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, target, v);
    }
};