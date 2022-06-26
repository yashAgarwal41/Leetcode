class Solution {
public:
    //Memoization..TC-O(n*6*6)..
    //p1- previous, p2-second previous..
    int mod = 1e9+7;
    int dp[10001][7][7];
    int help(int i, int p1, int p2, int &n)
    {
        if(i>=n)    return 1;
        if(p1!=-1 and p2!=-1 and dp[i][p1][p2]!=-1) return dp[i][p1][p2];
        
        long long ans = 0;
        for(int j=1; j<=6; j++)
        {
            if(p1==-1 or __gcd(j, p1)==1)
            {
                if(j==1 and p1==1)    continue;     //gcd(1,1)=1, but cannot have same adjacent..
                if(j!=p2)                           //2nd condition satisfied..
                    ans = (ans + help(i+1, j, p1, n))%mod;
            }
        }
        
        if(p1!=-1 and p2!=-1)   return dp[i][p1][p2] = ans%mod;
        else return ans%mod;
    }
    
    int distinctSequences(int n) {
        memset(dp, -1, sizeof dp);
        return help(0, -1, -1, n);
    }
};