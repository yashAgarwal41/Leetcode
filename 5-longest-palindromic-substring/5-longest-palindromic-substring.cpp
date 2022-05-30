class Solution {
public:
    int dp[1001][1001];
    bool help(int l, int r, int &n, string &s)
    {
        if(l>=r)    return 1;
        if(dp[l][r] != -1)  return dp[l][r];
        if(s[l]!=s[r])  return 0;
        
        return dp[l][r] = help(l+1, r-1, n, s);
        
    }
    string longestPalindrome(string s) {
        int n=s.size(), maxi=0;
        string ans = "";
        memset(dp, -1, sizeof dp);
        
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=i; j--)
            {
                if(help(i,j,n,s))
                {
                    int currLen = j-i+1;
                    if(maxi < currLen)
                    {
                        ans = s.substr(i, currLen);
                        maxi = currLen;
                    }
                }
            }
        }
        
        return ans;
        
    }
};