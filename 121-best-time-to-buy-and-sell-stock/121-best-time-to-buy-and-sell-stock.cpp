class Solution {
public:
    int maxProfit(vector<int>& v) {
        int maxi = 0, miniBuy = INT_MAX;
        for(int i=0; i<v.size(); i++)
        {
            miniBuy = min(miniBuy, v[i]);
            maxi = max(maxi, v[i]-miniBuy);
        }
        return maxi;
    }
};