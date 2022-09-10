class Solution {
public:
    int n;
    int dp[1001][101][2];
    int help(int i, int k, bool buy, vector<int> &v)
    {
        if(k<0)     return -1e6;
        if(k==0 or i>=n)    return 0;
        if(dp[i][k][buy]!=-1)   return dp[i][k][buy];
        
        int pick=0, notPick=0;
        if(buy == 1)    //canBuy
        {
            pick = help(i+1, k, 0, v) - v[i]; //if buy
            notPick = help(i+1, k, 1, v);   //if not buy
        }
        else
        {
            pick = help(i+1, k-1, 1, v) + v[i];   //if sell
            notPick = help(i+1, k, 0, v);   //if not sell
        }
        
        return dp[i][k][buy] = max(pick, notPick);
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof dp);
        return help(0, k, 1, prices);
    }
};