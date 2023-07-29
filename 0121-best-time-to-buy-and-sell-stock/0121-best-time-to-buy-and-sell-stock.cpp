class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0], maxi = 0;
        for(int i=0; i<n; i++)
        {
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }
        return maxi;
    }
};