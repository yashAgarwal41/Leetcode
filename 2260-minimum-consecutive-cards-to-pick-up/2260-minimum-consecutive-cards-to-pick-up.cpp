class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int, int> map;
        
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(map.count(cards[i]))
            {
                mini = min(mini, i - map[cards[i]] + 1);
            }
            map[cards[i]] = i;
        }
        
        return mini == INT_MAX ? -1 : mini;
    }
};