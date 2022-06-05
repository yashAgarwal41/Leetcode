class Solution {
public:
    //memoization..TC_O(n)
    #define ll long long
    ll dp[100001];
    ll help(int i, int n, vector<vector<int>> &v)
    {
        if(i>=n)    return 0;
        if(dp[i]!=-1)   return dp[i];
        ll take = v[i][0] + help(v[i][1]+i+1, n, v);
        ll notTake = help(i+1, n, v);
        return dp[i] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& v) {
        int n=v.size();
        memset(dp, -1, sizeof dp);
        return help(0, n, v);
    }
};