class Solution {
public:
    //DFS + DP..TC-O(m*n*maxMove)
    int mod = 1e9+7;
    int dp[51][51][51];
    int dfs(int i, int j, int maxMove, int &m, int &n)
    {
        if(maxMove<0)   return 0;
        if(i<0 or j<0 or i>=m or j>=n)  return 1;
        if(dp[i][j][maxMove]!=-1)   return dp[i][j][maxMove]%mod;
        
        int d1 = dfs(i-1, j, maxMove-1, m, n)%mod;
        int d2 = dfs(i, j-1, maxMove-1, m, n)%mod;
        int d3 = dfs(i+1, j, maxMove-1, m, n)%mod;
        int d4 = dfs(i, j+1, maxMove-1, m, n)%mod;
        
        return dp[i][j][maxMove] = (0LL + d1 + d2 + d3 + d4)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        return dfs(startRow, startColumn, maxMove, m, n);
    }
};