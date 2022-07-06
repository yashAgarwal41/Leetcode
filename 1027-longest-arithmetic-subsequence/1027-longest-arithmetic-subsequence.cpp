class Solution {
public:
    //TC-O(n*n)..LIS
    int longestArithSeqLength(vector<int>& v) {
        int n =v.size(), maxi=0;
        //stores the freq of all the differences with the previous indices..
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int diff = v[j] - v[i] + 500;   //to avoid negative diff = 0-500 = -500..
                dp[i][diff] = 1;
                dp[i][diff] += dp[j][diff];
                maxi = max(maxi, dp[i][diff]);
            }
        }
        return maxi+1;
    }
};