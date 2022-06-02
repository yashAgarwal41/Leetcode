class Solution {
public:
    //Memoization..TC-O(l1*l2*l3)
    int l1, l2, l3;
    int dp[101][101];
    bool help(int i, int j, int k, string &s1, string &s2, string &s3)
    {
        if(i==l1 and j==l2 and k==l3) return true;
        if(i==l1 and j==l2) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool a = 0, b=0;
        if(i<l1 and s1[i] == s3[k])  a = help(i+1, j, k+1, s1, s2, s3);
        if(j<l2 and s2[j] == s3[k])  b = help(i, j+1, k+1, s1, s2, s3);
    
        return dp[i][j] = (a or b);
    }
    bool isInterleave(string s1, string s2, string s3) {
        l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        memset(dp, -1, sizeof dp);
        return help(0, 0, 0, s1, s2, s3);
    }
};
