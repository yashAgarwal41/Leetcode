class Solution {
public:
    //Bottom Up DP..TC-O(n*target*k)
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int tar=1; tar<=target; tar++)
            {
                for(int face=1; face<=k; face++)
                {
                    if(face > tar)  break;
                    dp[i][tar] = (dp[i][tar]%mod + dp[i-1][tar-face]%mod)%mod;
                }
             }
        }
        return dp[n][target]%mod;
    }
};