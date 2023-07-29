class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), totSum = 0, currSum = 0;
        for(auto i:nums)    totSum += i;
        for(int i=0; i<n; i++)
        {
            if(totSum - nums[i] - currSum == currSum) return i;
            currSum += nums[i];
        }
        return -1;
    }
};