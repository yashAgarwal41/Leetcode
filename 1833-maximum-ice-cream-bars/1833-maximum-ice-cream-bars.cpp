class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sum=0, n=costs.size();
        sort(costs.begin(), costs.end());
        for(int i=0; i<n; i++)
        {
            sum += costs[i];
            if(sum > coins) return i;
        }
        return n;
    }
};