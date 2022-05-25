class Solution {
public:
    //Dp-Memoization
    int dp[2501][2501];
    int help(int i, int j, int &n, vector<int> &v)
    {
        if(i>=n)
            return 0;
        
        if(j!=-1 and dp[i][j]!=-1)   return dp[i][j];
        
        int take = 0;
        if(j==-1 or v[j]<v[i])    
            take = help(i+1, i, n, v) + 1;
        
        int notTake = help(i+1, j, n, v);
        
        if(j==-1)   return max(take, notTake);
        else
            return dp[i][j] = max(take, notTake);
        
    }
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        memset(dp, -1, sizeof dp);
        return help(0, -1, n, v);
    }
};



