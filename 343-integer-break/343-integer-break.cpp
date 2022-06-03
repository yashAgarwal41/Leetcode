class Solution {
public:
    //Memoization..TC-O(n*n)
    int dp[60][60];
    int help(int i, int tar)
    {
        if(tar==0)    return 1;
        if(i<=0 or tar<0) return 0;
        if(dp[i][tar]!=-1)  return dp[i][tar];
        
        int take = 1, notTake = 1;
        
        if(tar>=i)    take = i*help(i, tar-i);
        notTake = help(i-1, tar);
        
        return dp[i][tar] = max(take, notTake);
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof dp);
        return help(n-1, n);    //we have to pass i=n-1, because we need k>=2.
    }
};