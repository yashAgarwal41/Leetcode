class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), chk = 0;
        if(n<=2)    return true;
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] == nums[i])    continue;
            else if(chk == 0)
            {
                if(nums[i-1] < nums[i]) chk = 1;
                else chk = 2;
            }
            else 
            {
                if((nums[i-1]<nums[i] and chk==2) or (nums[i-1]>nums[i] and chk==1)) 
                    return false; 
            }
        }
        return true;
    }
};