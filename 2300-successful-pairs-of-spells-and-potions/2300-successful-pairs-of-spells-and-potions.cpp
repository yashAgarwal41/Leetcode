class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res;
    
        for(int i=0; i<n; i++)
        {
            long long temp = ceil((success*1.0)/spells[i]);
            int ind = lower_bound(potions.begin(), potions.end(), temp) - potions.begin();
            res.push_back(m - ind);
        }
        return res;
    }
};