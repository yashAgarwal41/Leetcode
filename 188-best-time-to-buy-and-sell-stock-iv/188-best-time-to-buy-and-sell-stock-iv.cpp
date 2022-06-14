class Solution {
public:
    //memoization...TC-O(n*k)
    int dp[1001][101][2];
    int help(int i, int k, bool buy, int &n, vector<int> &v)
    {
        if(i>=n or k<=0) return 0;
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        
        int take = 0, notTake = 0;
        if(buy == 0)
        {
            take = help(i+1, k, 1, n, v) - v[i];
            notTake = help(i+1, k, 0, n, v);
        }
        else 
        {
            take = help(i+1, k-1, 0, n, v) + v[i];
            notTake = help(i+1, k, 1, n, v);
        }
        
        return dp[i][k][buy] = max(take, notTake);
    }
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        memset(dp, -1, sizeof dp);
        return help(0, k, false, n, v);
    }
};