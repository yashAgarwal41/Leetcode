class Solution {
public:
    int n;
    int dp[100001];
    int mod = 1e9+7;
    int help(int i, string &s)
    {
        if(i>=n)    return 1;
        if(dp[i]!=-1)   return dp[i];
        if(s[i]=='0') return dp[i] = 0;
        int pickOne=0, pickTwo=0;
        
        if(s[i]!='*')   pickOne = help(i+1, s);
        else
        {
            for(int j=1; j<=9; j++)
            {
                pickOne = (pickOne + help(i+1, s) + 0LL)%mod;
            }
        }
        
        if(i<n-1)
        {
            if(s[i]!='*' and s[i]<='2')
            {
                if(s[i+1]!='*') 
                {
                    int x = 10*(s[i]-'0') + (s[i+1]-'0');
                    if(x<=26)   pickTwo = (pickTwo + help(i+2, s) + 0LL)%mod;
                }
                else 
                {
                    for(int j=1; j<=9; j++)
                    {
                        int x =10*(s[i]-'0') + j;
                        if(x <= 26) pickTwo = (pickTwo + help(i+2, s) + 0LL)%mod;
                    }
                }
            }
            else if(s[i] == '*')
            {
                if(s[i+1] != '*')
                {
                    for(int j=1; j<=2; j++)
                    {
                        int x = j*10 + (s[i+1]-'0');
                        if(x<=26)   pickTwo = (pickTwo + help(i+2, s) + 0LL)%mod;
                    }
                }
                else 
                {
                    for(int j=1; j<=2; j++)
                    {
                        for(int k=1; k<=9; k++)
                        {
                            int x = j*10 + k;
                            if(x<=26)   pickTwo = (pickTwo + help(i+2, s) + 0LL)%mod;
                        }
                    }
                }
            }
        }
        return dp[i] = (pickOne + pickTwo)%mod;
    }
    int numDecodings(string s) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        return help(0, s);
    }
};