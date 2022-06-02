class Solution {
public:
    //Tabulation..TC-O(n*m)
    
    //Recursion for reference..
//     int dp[501][501];
//     int help(int i,int j, string &s1, string &s2)
//     {
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j]!=-1)    return dp[i][j];
        
//         if(s1[i]==s2[j]) return dp[i][j] = help(i-1, j-1, s1, s2);
        
//         int ins = 1 + help(i, j-1, s1, s2);
//         int del = 1 + help(i-1, j, s1, s2);
//         int rep = 1 + help(i-1, j-1, s1, s2);
        
//         return dp[i][j] = min({ins, del, rep});
//     }
    int minDistance(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        // memset(dp, -1, sizeof dp);
        // return help(n-1, m-1, s1, s2);
        
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++) dp[i][0]=i;
        for(int j=0; j<=m; j++) dp[0][j]=j;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])  dp[i][j] = dp[i-1][j-1];
                else 
                {
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                }
            }
        }
        return dp[n][m];
    }
};