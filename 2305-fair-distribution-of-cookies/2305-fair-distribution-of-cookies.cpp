class Solution {
public:
    //Backtracking + dp..
    int maxi=INT_MAX;
    void help(int i, int &k, int n, vector<int> &dp, vector<int> &v)
    {
        if(i>=n)
        {
            int temp = *max_element(dp.begin(), dp.begin()+k);
            maxi = min(maxi, temp);
            return;
        }
        for(int j=0; j<k; j++)
        {
            dp[j] += v[i];
            help(i+1, k, n, dp, v);
            dp[j] -= v[i];  //backtrack
        }
    }
    int distributeCookies(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(10, 0);
        help(0, k, n, dp, v);
        return maxi;
    }
};