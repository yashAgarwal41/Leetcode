class Solution {
public:
    int mod = 1e9+7;
    int dp[10001][2][2];
    int help(int i, int prev1, int prev2, int &n)
    {
        if(i>=n)    return 1;
        if(dp[i][prev1][prev2]!=-1) return dp[i][prev1][prev2];
        
        int ans = 0;
        if(prev1==0 and prev2==0)
        {
            ans = (ans + help(i+1, 0, 0, n))%mod;
            ans = (ans + help(i+1, 0, 1, n))%mod;
            ans = (ans + help(i+1, 1, 0, n))%mod;
            ans = (ans + help(i+1, 1, 1, n))%mod;
        }
        else if(prev1==0 and prev2==1)
        {
            ans = (ans + help(i+1, 0, 0, n))%mod;
            ans = (ans + help(i+1, 1, 0, n))%mod;
        }
        else if(prev1==1 and prev2==0)
        {
            ans = (ans + help(i+1, 0, 0, n))%mod;
            ans = (ans + help(i+1, 0, 1, n))%mod;
        }
        else 
            ans = (ans + help(i+1, 0, 0, n))%mod;
        
        return dp[i][prev1][prev2] = ans;

    }
    int countHousePlacements(int n) {
        memset(dp, -1, sizeof dp);
        return help(0,0,0,n);
    }
};