//Memoization..TC-O(n*4*3)
#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int dp[4][3][5001];
    vector<vector<int>> grid{   {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}  };

    ll help(int i, int j, int n)
    {
        if(i<0 or j<0 or i>3 or j>2 or (i==3 and (j==0 or j==2)))   
            return 0;
        if(n==0)    return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        ll ans = 0;
        //up
        ans = (ans + help(i-2, j-1, n-1))%mod;
        ans = (ans + help(i-2, j+1, n-1))%mod;
        //left
        ans = (ans + help(i-1, j-2, n-1))%mod;
        ans = (ans + help(i+1, j-2, n-1))%mod;
        //right
        ans = (ans + help(i-1, j+2, n-1))%mod;
        ans = (ans + help(i+1, j+2, n-1))%mod;
        //down
        ans = (ans + help(i+2, j-1, n-1))%mod;
        ans = (ans + help(i+2, j+1, n-1))%mod;
        
        return dp[i][j][n] = ans;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof dp);
        ll ans = 0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
            {
                ans = (ans + help(i, j, n-1))%mod;
            }
        }
        
        return ans;
    }
};