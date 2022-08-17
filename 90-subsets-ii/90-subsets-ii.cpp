class Solution {
public:
    //BackTracking, TC-O(2^n)*n
    int n;
    void help(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &res)
    {
        res.push_back(subset);
        if(i==n)    return;
        
        for(int j=i; j<n; j++)
        {
            if(j>i and nums[j] == nums[j-1])    continue;
            subset.push_back(nums[j]);
            help(j+1, nums, subset, res);
            subset.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end()); //to make all the repeated no together..
        vector<vector<int>> res;
        vector<int> subset;
        help(0, nums, subset, res);
        return res;
    }
};