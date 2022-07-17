class Solution {
public:
    //DP..TC-O(n)
    int longestSubsequence(vector<int>& v, int diff) {
        int n = v.size();
        unordered_map<int, int> map;
        for(int i=0; i<n; i++)
        {
            map[v[i]] = map[v[i]-diff] + 1;
        }
        int maxi = 1;
        for(auto &it:map)   maxi = max(maxi, it.second);
        return maxi;
    }
};