class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mapp;
        for(int i=0; i<n; i++)
        {
            int y = target-nums[i];
            if(mapp.find(y)!=mapp.end())
            {
                return {i, mapp[y]};
            }
            mapp[nums[i]] = i;
        }
        return {0,1};
    }
};