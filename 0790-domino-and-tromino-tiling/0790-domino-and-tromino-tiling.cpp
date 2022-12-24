class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        int dp[1001];
        dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for(int i=4; i<=n; i++)
        {
            dp[i] = (0LL + 2*dp[i-1] + dp[i-3])%mod;
        }
        return dp[n];
    }
};