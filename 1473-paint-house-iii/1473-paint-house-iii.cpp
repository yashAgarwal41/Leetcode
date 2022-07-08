class Solution {
public:
    //Memoization..TC-O(m*n*target)...
    int dp[101][21][101];
    int help(int i, int prev, int target, vector<int> &houses, vector<vector<int>> &cost, int &m, int &n)
    {
        if(i==m and target==0)  return 0;
        if(target<0 or i>=m)   return 1e9;
        if(dp[i][prev][target]!=-1) return dp[i][prev][target];
        
        if(houses[i]!=0)    //if already colored..
        {
            if(i==0 or houses[i]==prev) //if previous color is same as current 
                return dp[i][prev][target] = help(i+1, houses[i], target, houses, cost, m, n);
            else
                return dp[i][prev][target] = help(i+1, houses[i], target-1, houses, cost, m, n);
        }
        
        //if not colored..
        int ans = INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(i==0 or j+1==prev)   //if previous color is same as current 
                ans = min(ans, cost[i][j] + help(i+1, j+1, target, houses, cost, m, n));
            else 
                ans = min(ans, cost[i][j] + help(i+1, j+1, target-1, houses, cost, m, n));
        }
        return dp[i][prev][target] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        memset(dp, -1, sizeof dp);
        int ans = help(0, 0, target-1, houses, cost, m, n);
        return ans >= 1e9 ? -1 : ans;
    }
};