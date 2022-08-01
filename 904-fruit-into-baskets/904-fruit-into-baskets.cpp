class Solution {
public:
    //SLiding Window..TC-O(n)..
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> map;
        int i=0, j=0, maxi=0;
        while(i<n and j<n)
        {
            map[fruits[j]]++;
            while(map.size()>2)
            {
                map[fruits[i]]--;
                if(map[fruits[i]]==0)   map.erase(fruits[i]);
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};