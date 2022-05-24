class Solution {
public:
    //DP-Memoization
    int dp[102][10001];
    int help(int i, int tar, vector<int> &sq)
    {
        if(tar<0 or i>=sq.size())  return INT_MAX-1;
        if(dp[i][tar] != -1)  return dp[i][tar];
        if(tar == 0)    return 0;
        
        int take = INT_MAX;
        if(sq[i]<=tar)  take = help(i, tar-sq[i], sq) + 1;
        
        int notTake = help(i+1, tar, sq);
        
        return dp[i][tar] = min(take, notTake);
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof dp);
        vector<int> sq;
        
        for(int i=1; i<=sqrt(n); i++)
            sq.push_back(i*i);
        
        
        return help(0, n, sq);
    }
};