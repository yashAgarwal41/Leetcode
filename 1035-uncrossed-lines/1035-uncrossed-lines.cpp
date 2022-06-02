class Solution {
public:
    //Memoization..TC-O(n*m)..
    // similar to LCS..
    int dp[501][501];
    int help(int i, int j, vector<int>& v1, vector<int>& v2)
    {
        if(i<0  or j<0) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(v1[i] == v2[j])  return dp[i][j] = 1 + help(i-1, j-1, v1, v2) ;
        else return dp[i][j] = max(help(i-1, j, v1, v2), help(i, j-1, v1, v2));
    }
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
        int n=v1.size(), m=v2.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, m-1, v1, v2);
        
    }
};