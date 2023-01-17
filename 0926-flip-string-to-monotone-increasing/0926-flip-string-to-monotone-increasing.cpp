class Solution {
public:
    //Memoization DP
    int dp[100001][2];
    int help(int i, int flag, string &s, int n)
    {
        if(i==n)    return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        int flip=1e9, notFlip=1e9;
        
        if(s[i] == '1')
        {
            if(flag == 0)   flip = 1 + help(i+1, 0, s, n);
            notFlip = help(i+1, 1, s, n);    
        }
        else if(s[i] == '0') 
        {
            if(flag == 1)   flip = 1 + help(i+1, 1, s, n);
            else notFlip = help(i+1, 0, s, n);
        }
        
        return dp[i][flag] = min(flip, notFlip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size(), i=0;
        while(i<n and s[i] == '0')    i++;
        if(i==n)    return 0;
        memset(dp, -1, sizeof dp);
        return help(i, 0, s, n);
    }
};