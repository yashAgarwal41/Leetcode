class Solution {
public:
    //Top-Down...TC-O(n^2), SC-O(n^2)..
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++) 
                if(i==0 or j==0)    dp[i][j]=0;
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};