class Solution {
public:
    //bottom Up(not done)..TC-O(n*k)..
    int mod = 1e9+7;
    int dp[1001][1001];
    // int help(int n, int k)
    // {
    //     if(k<=0)    return k==0;
    //     if(n<=0)    return 0;
    //     if(dp[n][k]!=-1)    return dp[n][k];
    //     int ans = 0;
    //     for(int i=0; i<n; i++)
    //     {
    //         ans = (ans + help(n-1, k-i))%mod;   //check for n-1 elements..
    //     }
    //     return dp[n][k]=ans;
    // }
    int kInversePairs(int n, int k) {
        if(k==0)    return 1;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= k; ++j){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j - i >= 0){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod; 
                }
            }
        }
        return dp[n][k];
    }
};