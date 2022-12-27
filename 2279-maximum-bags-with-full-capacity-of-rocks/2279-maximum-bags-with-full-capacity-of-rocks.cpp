class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n, 0);
        for(int i=0; i<n; i++)
        {
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            additionalRocks -= diff[i];
            if(additionalRocks<0)   return i;
        }
        return n;
    }
};