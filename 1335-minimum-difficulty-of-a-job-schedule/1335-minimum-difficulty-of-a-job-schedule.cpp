class Solution {
public:
    //Memoization..TC-O(n*d*n)
    int n;
    int dp[301][11];
    int help(int i, int d, vector<int> &v)
    {
        if(i>=n and d==0)   return 0;
        if(i>=n or d<0) return 1e9;
        if(dp[i][d]!=-1)    return dp[i][d];
        int ans = INT_MAX;
        int maxi = 0;
        for(int j=i; j<n; j++)
        {
            maxi = max(maxi, v[j]);
            ans = min(ans, help(j+1, d-1, v) + maxi);
        }
        return dp[i][d] = ans;
        return ans;
    }
    int minDifficulty(vector<int>& v, int d) {
        n = v.size();
        if(n<d) return -1;
        if(n==d)    return accumulate(v.begin(), v.end(), 0);
        memset(dp, -1, sizeof dp);
        return help(0, d, v);
    }
};