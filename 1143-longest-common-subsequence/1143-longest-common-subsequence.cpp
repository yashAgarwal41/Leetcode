class Solution {
public:
    //Bottom-Up DP ..TC-O(n^2), SC-O(n^2)
    int n, m;
    int dp[1001][1001];
    int help(int i, int j, string &text1, string &text2)
    {
        if(i<0 or j<0)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(text1[i] == text2[j])    
            return dp[i][j] = 1 + help(i-1, j-1, text1, text2);
        else 
            return dp[i][j] = max(help(i-1, j, text1, text2), help(i, j-1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size(), m=text2.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, m-1, text1, text2);
    }
};