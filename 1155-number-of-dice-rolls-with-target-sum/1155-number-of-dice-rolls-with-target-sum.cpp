class Solution {
public:
    //Memoization..TC-O(n*k*target)
    int mod = 1e9+7;
    int dp[31][1001];
    int help(int i, int target, int &k)
    {
        if(i==0 and target==0)  return 1;
        if(i==0 or target<=0)    return 0;
        if(dp[i][target] != -1)   return dp[i][target];
        
        long long ans = 0;
        for(int j=1; j<=k; j++)
        {
            if(j>target)    break;
            ans = (ans + help(i-1, target-j, k))%mod;
        }
        return dp[i][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) 
    {
        memset(dp, -1, sizeof dp);
        return help(n, target, k);
    }
};