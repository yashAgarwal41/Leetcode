class Solution {
public:
    int n;
    int dp[101];
    int help(int i, string &s)
    {
        if(i>=n)    return 1;
        if(dp[i]!=-1)   return dp[i];
        if(s[i]=='0')   return dp[i] = 0;
        
        int pickOne=0, pickTwo=0;
        pickOne = help(i+1, s);
        
        if(i<n-1)
        {
            int x = 10*(s[i]-'0') + (s[i+1]-'0');
            if(x <= 26)  pickTwo = help(i+2, s);
        }
           
        return dp[i] = pickOne + pickTwo;
    }
    int numDecodings(string s) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        return help(0, s);
    }
};