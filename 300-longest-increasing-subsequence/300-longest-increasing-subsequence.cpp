class Solution {
public:
//Tabulation..TC-O(n^2), SC-O(n)
//here dp[i] means, length of longest increasing subsequence(where v[i] is greatest ele of subsequence)    
//     e.g- [5, 4, 11, 1, 16, 8]
//           1  1  1   1   1  1     ->inital dp values
//           1  1  2   1   3  2     ->final dp values
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 1);
        
        for(int i=1; i<n; i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if(v[prev]<v[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};