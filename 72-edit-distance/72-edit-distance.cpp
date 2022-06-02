class Solution {
public:
    //Memoization..TC-O(n*n)
    int dp[501][501];
    int help(int i,int j, string &s1, string &s2)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j] = help(i-1, j-1, s1, s2);
        
        int ins = 1 + help(i, j-1, s1, s2);
        int del = 1 + help(i-1, j, s1, s2);
        int rep = 1 + help(i-1, j-1, s1, s2);
        
        return dp[i][j] = min({ins, del, rep});
    }
    int minDistance(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, m-1, s1, s2);
    }
};