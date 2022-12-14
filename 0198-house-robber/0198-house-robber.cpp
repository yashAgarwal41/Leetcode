class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);
        if(n == 3)  return max(nums[0] + nums[2], nums[1]);
        int prev2 = max(nums[0], nums[1]);
        int prev1 = max(nums[0]+nums[2], prev2);
        for(int i=3; i<n; i++)
        {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return max(prev1, prev2);
    }
};