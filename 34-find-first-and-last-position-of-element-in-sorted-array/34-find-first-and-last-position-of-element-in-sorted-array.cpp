class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lb==n or nums[lb]!=target)
            return vector<int> {-1,-1};
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return vector<int> {lb, ub-1};
    }
};