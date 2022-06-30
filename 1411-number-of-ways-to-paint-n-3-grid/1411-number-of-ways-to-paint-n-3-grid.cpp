class Solution {
public:
    //Memoization..TC-O(n*4*4*4)..
    //here pc-> previous column paint value..
    int mod = 1e9+7;
    int dp[5001][4][4][4];
    int help(int i, int pc1, int pc2, int pc3, int n)
    {
        if(i>=n)    return 1;
        if(dp[i][pc1][pc2][pc3]!=-1)    return dp[i][pc1][pc2][pc3];
        
        int ans=0;
        for(int a=1; a<=3; a++)
        {
            if(a!=pc1)
            {
                for(int b=1; b<=3; b++)
                {
                    if(b!=pc2 and b!=a)
                    {
                        for(int c=1; c<=3; c++)
                        {
                            if(c!=pc3 and c!=b)
                            ans = (ans + help(i+1, a, b, c, n))%mod;
                        }
                    }
                    
                }
            }
            
        }
        return dp[i][pc1][pc2][pc3] = ans%mod;
    }
    int numOfWays(int n) {
        memset(dp, -1, sizeof dp);
        return help(0, 0, 0, 0, n);
    }
};