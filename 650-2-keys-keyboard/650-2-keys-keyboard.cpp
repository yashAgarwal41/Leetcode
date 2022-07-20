class Solution {
public:
    //Memoization..TC-O(n*n)
    int dp[1001][1001];
    int help(int i, int prev, int &n)
    {
        if(i==n)    return 0;
        if(i>n) return 1e9;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int prevPaste = 1 + help(i+prev, prev, n);
        int newPaste = 2 + help(2*i, i, n);
        return dp[i][prev] = min(prevPaste, newPaste);
    }
    int minSteps(int n) {
        if(n==1)    return 0;
        if(n==2)    return 2;
        memset(dp, -1, sizeof dp);
        return 2 + help(2, 1, n);   //find for after "AA"
    }   
};