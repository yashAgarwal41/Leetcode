class Solution {
public:
    //BackTracking, TC-O(2^n)*n
    int n;
    void help(int i, int target, vector<int> &candidates, vector<int> &combination, vector<vector<int>> &res)
    {
        if(target==0)
        {
            res.push_back(combination);
            return;
        }
        if(target<0 or i==n)    return;
        
        for(int j=i; j<n; j++)
        {
            if(j>i and candidates[j]==candidates[j-1])  continue; //if repeated num arrives..
            if(target < candidates[j])  return;
            combination.push_back(candidates[j]);
            help(j+1, target-candidates[j], candidates, combination, res);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end()); //to make all repeated no together..
        vector<int> combination;
        vector<vector<int>> res;
        help(0, target, candidates, combination, res);
        return res;
    }
};