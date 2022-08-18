class Solution {
public:
    //Calculate degree, then elements that have degree and the starting and ending point of those..TC-O(n)
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), degree=0;
        unordered_map<int, vector<int>> mmap;
        for(int i=0; i<n; i++)
        {
            mmap[nums[i]].push_back(i);
            int sz = mmap[nums[i]].size();
            degree = max(degree, sz);
        }
        
        int shortest = INT_MAX;
        for(auto &it:mmap)
        {
            if(it.second.size() == degree)
            {
                shortest = min(shortest, it.second.back() - it.second[0] + 1);
            }
        }
        return shortest;
    }
};