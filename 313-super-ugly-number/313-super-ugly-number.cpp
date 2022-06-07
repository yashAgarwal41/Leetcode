class Solution {
public:
    //DP..refer pepcoding yt..
    //pointers will store the dp index of each element of given array..
    //in dp, we will keep inserting the min value first(so to have nums in sorted order)..
    int nthSuperUglyNumber(int n, vector<int>& v) {
        int m = v.size();
        vector<int> dp, pointers(m, 0);
        dp.push_back(1);
        while(dp.size()<n)
        {
            int mini = INT_MAX;
            for(int i=0; i<m; i++)
            {
                mini = min(mini, v[i]*dp[pointers[i]]);
            }
            dp.push_back(mini);
            for(int i=0; i<m; i++)
            {
                if(v[i]*dp[pointers[i]] == mini)    pointers[i]++;
            }
        }
        return dp[n-1];
    }
};