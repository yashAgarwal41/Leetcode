class Solution {
public:
    //LCS-> TC-O(n*m)
    int dp[1001][1001];
    int help(int i, int j, string &s1, string &s2)
    {
        if(i<0 or j<0)
        {
            int sum=0;
            for(int x=0; x<=i; x++)  sum += s1[x];
            for(int y=0; y<=j; y++)  sum += s2[y];
            return sum;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i] == s2[j])  
            return dp[i][j] = help(i-1, j-1, s1, s2);
        else
            return dp[i][j] = min(s1[i] + help(i-1, j, s1, s2), s2[j] + help(i, j-1, s1, s2));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        memset(dp, -1, sizeof dp);
        return help(n-1, m-1, s1, s2);
    }
};