class Solution {
public:
    //Longest common "Substring"(LCS)
    //Tabulation..TC-O(n*m)
    int findLength(vector<int>& v1, vector<int>& v2) {
        int n=v1.size(), m=v2.size();
        int dp[n+1][m+1], maxi=0;
        memset(dp, 0, sizeof dp);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(v1[i-1] == v2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else 
                    dp[i][j] = 0;
                
                maxi=max(maxi, dp[i][j]);
            }
        }
        
        return maxi;
    }
};