class Solution {
public:
    //Recursion-Backtracking, TC-O(2^n)*n
    int n;
    void help(int i, vector<int> &nums, vector<int> &subseq, vector<vector<int>> &res)
    {
        if(subseq.size()>1) res.push_back(subseq);
        if(i==n)    return;
        
        unordered_set<int> set; //to avoid duplicates subsequences..
        for(int j=i; j<n; j++)
        {
            if(set.find(nums[j]) != set.end())  continue;   //if same num is already taken..
            if(subseq.size()==0 or subseq.back() <= nums[j])
            {
                set.insert(nums[j]);
                subseq.push_back(nums[j]);  //push
                help(j+1, nums, subseq, res);
                subseq.pop_back();  //backtrack
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> subseq;
        vector<vector<int>> res;
        help(0, nums, subseq, res);
        return res;
    }
};