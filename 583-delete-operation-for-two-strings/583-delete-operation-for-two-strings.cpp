class Solution {
public:
    //Exactly LCS question...TC-O(n^2)
    int dp[501][501];
    int help(int i, int j, string &word1, string &word2)
    {
        if(i<0 or j<0)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(word1[i]==word2[j])  
            return dp[i][j] = 1 + help(i-1, j-1, word1, word2);
        else
            return dp[i][j] = max(help(i-1, j, word1, word2), help(i, j-1, word1, word2));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m=word2.size();
        memset(dp, -1, sizeof dp);
        int common = help(n-1, m-1, word1, word2);
        return n-common + m-common;
    }
};