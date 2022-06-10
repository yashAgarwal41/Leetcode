class Solution {
public:
    //Memoization..TC-O(n*n)
    int dp[1001][1001];
    int help(int i, int prev, int &n, vector<vector<int>> &v)
    {
        if(i>=n)    return 0;
        if(prev!=-1 and dp[i][prev]!=-1)    return dp[i][prev];
        
        int pick=0;
        if(prev == -1 or v[i][0]>v[prev][1])
            pick = 1 + help(i+1, i, n, v);
        int notPick = help(i+1, prev, n, v);
        
        if(prev!=-1)    return dp[i][prev] = max(pick, notPick);
        else return max(pick, notPick);
    }
    int findLongestChain(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        memset(dp, -1, sizeof dp);
        return help(0, -1, n, v);
    }
};