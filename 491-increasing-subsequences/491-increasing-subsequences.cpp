class Solution {
public:
    //Recursion-Backtracking, TC-O(2^n)*n
    int n;
    set<vector<int>> set;
    void help(int i, vector<int> &nums, vector<int> &subseq, vector<vector<int>> &res)
    {
        if(subseq.size()>1) 
            set.insert(subseq);
            // res.push_back(subseq);
        if(i==n)    return;
        
        for(int j=i; j<n; j++)
        {
            if(subseq.size()==0 or subseq.back() <= nums[j])
            {
                subseq.push_back(nums[j]);
                help(j+1, nums, subseq, res);
                subseq.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> subseq;
        vector<vector<int>> res;
        help(0, nums, subseq, res);
        for(auto &v:set)    res.push_back(v);
        return res;
    }
};