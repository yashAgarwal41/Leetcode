class Solution {
public:
    //Calculate degree, then elements that have degree and the starting and ending point of those..TC-O(n)
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), degree=0;
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> freqmap;
        for(auto &it:nums)
        {
            freqmap[it]++;
            degree = max(degree, freqmap[it]);
        }
        
        vector<int> degreeNums(maxi+1, 0);
        for(auto &it:freqmap)
        {
            if(it.second==degree)
                degreeNums[it.first] = 1;
        }
        
        vector<int> start(maxi+1, -1), end(maxi+1, -1);
        for(int i=0; i<n; i++)
        {
            if(degreeNums[nums[i]] == 1 and start[nums[i]] == -1)
                start[nums[i]] = i;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(degreeNums[nums[i]] == 1 and end[nums[i]] == -1)
                end[nums[i]] = i;
        }
        
        int shortest = INT_MAX;
        for(int i=0; i<=maxi; i++)
        {
            if(start[i] != -1)
            {
                shortest = min(shortest, end[i]-start[i]+1);
            }
        }
        return shortest;
    }
};