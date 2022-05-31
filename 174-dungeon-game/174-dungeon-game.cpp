class Solution {
public:
    //Bottom-Up Dp..TC-O(n*m), SC-O(n*m)..
    int calculateMinimumHP(vector<vector<int>>& v) {
        int n=v.size(), m=v[0].size();
        int dp[n][m];
        dp[n-1][m-1] = v[n-1][m-1]>0 ? 0 : v[n-1][m-1];
        // if at any step health is > 0 , then put 0 there, because min health required for that cell will be 0 + 1. But if its negative, then put that negative value there, because min value require will be abs(min value) + 1;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i==n-1 and j==m-1)   continue;
                if(i==n-1)
                {
                    int health = v[i][j] + dp[i][j+1];
                    dp[i][j] = health>0 ? 0 : health;
                }
                else if(j==m-1)
                {
                    int health = v[i][j] + dp[i+1][j];
                    dp[i][j] = health>0 ? 0 : health;
                }
                else 
                {
                    int health = max(dp[i][j+1], dp[i+1][j]) + v[i][j];
                    dp[i][j] = health>0 ? 0 : health; 
                }
            }
        }
        return abs(dp[0][0]) + 1;
    }
};