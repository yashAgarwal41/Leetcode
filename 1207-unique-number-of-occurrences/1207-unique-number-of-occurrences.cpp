class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        int n=v.size();
        unordered_map<int, int> m1, m2;
        for(int i=0; i<n; i++)
        {
            m1[v[i]]++;
        }
        for(auto it:m1)
        {
            m2[it.second]++;
        }
        for(auto it:m2)
        {
            if(it.second>1) return 0;
        }
        return 1;
        
    }
};