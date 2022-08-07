class Solution {
public:
    //memoization, TC-O(n*5)
    int dp[20001][6];
    int mod = 1e9+7, m;
    int help(int i, int letter)
    {
        if(i>=m)    return 1;
        if(dp[i][letter]!=-1)   return dp[i][letter];
        long long ans=0;
        if(letter==5)
        {
            for(int j=0; j<5; j++)
                ans = (ans + help(i+1, j))%mod;
        }
        else if(letter==0)
        {
            ans = (ans + help(i+1, 1))%mod;
        }
        else if(letter==1)
        {
            ans = (ans + help(i+1, 0))%mod;
            ans = (ans + help(i+1, 2))%mod;
        }
        else if(letter==2)
        {
            ans = (ans + help(i+1, 0))%mod;
            ans = (ans + help(i+1, 1))%mod;
            ans = (ans + help(i+1, 3))%mod;
            ans = (ans + help(i+1, 4))%mod;
        }
        else if(letter==3)
        {
            ans = (ans + help(i+1, 2))%mod;
            ans = (ans + help(i+1, 4))%mod;
        }
        else 
        {
            ans = (ans + help(i+1, 0))%mod;
        }
        return dp[i][letter] = ans;
    }
    int countVowelPermutation(int n) {
        m=n;
        memset(dp, -1, sizeof dp);
        return help(0, 5);
    }
};