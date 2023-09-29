class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)    return true;
        bool inc = true, dec = true;
        for(int i=1; i<n; i++)
        {
            if(nums[i-1]>nums[i])   inc = false;
            if(nums[i-1]<nums[i])   dec = false;
            if(inc==false and dec==false)   return false;
        }
        return true;
    }
};