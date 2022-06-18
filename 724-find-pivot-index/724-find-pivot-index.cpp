class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size(), totSum=0;
        if(n==1)    return 0;
        for(auto it: nums)  totSum+=it;
        int left=0;
        for(int i=0; i<n; i++)
        {
            if(i>0) left += nums[i-1];
            int right = totSum-left-nums[i];
            if(left==right) return i;
        }
        return -1;
    }
};