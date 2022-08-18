class Solution {
public:
    //Recursion-Backtracking, TC-O(2^n)*n
    int n;
    void help(int i, vector<int> &nums, vector<vector<int>> &res)
    {
        if(i==n)
        {
            res.push_back(nums);
            return;
        }
        
        for(int j=i; j<n; j++)
        {
            swap(nums[i], nums[j]);
            help(i+1, nums, res);
            swap(nums[i], nums[j]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        help(0, nums, res);
        return res;
    }
};