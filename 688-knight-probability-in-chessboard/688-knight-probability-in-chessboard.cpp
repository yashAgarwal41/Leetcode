// #define ll long long
class Solution {
public:
    //Memoization..TC-O(n*n*k)..
    // double dp[26][26][101];
    double help(int i, int j, int k, int &n, vector<vector<vector<double>>> &dp)
    {
        if(i<0 or j<0 or i>=n or j>=n)  return 0;
        if(k==0)    return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        double ans = 0;
        ans += help(i-2, j-1, k-1, n, dp);
        ans += help(i-2, j+1, k-1, n, dp);
        ans += help(i-1, j-2, k-1, n, dp);
        ans += help(i-1, j+2, k-1, n, dp);
        ans += help(i+2, j-1, k-1, n, dp);
        ans += help(i+2, j+1, k-1, n, dp);
        ans += help(i+1, j-2, k-1, n, dp);
        ans += help(i+1, j+2, k-1, n, dp);
        
        ans=ans/8.0;
        
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        // for(int i=0; i<=n; i++)
        // {
        //     for(int j=0; j<=n; j++)
        //     {
        //         for(int x=0; x<=k; x++) dp[i][j][k]=2;
        //     }
        // }
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n + 1, vector<double>(k + 1, -1)));
        return help(row, column, k, n, dp);
//         double insideBoundary = help(row, column, k, n);
//         return insideBoundary;
        
//         //total no of moves will be 8^k..
//         //so probability = insideBoundary/totalMoves;
//         //so to avoid bigIntegerOverFlow..use while loop..
//         while(k--)
//         {
//             prob = prob/8.0;
//         }
        
//         return prob;
    }
};