class Solution {
public:
    //BackTracking, TC-O(2^n)*n
    //Note- since in ques, all the values are distinct, so we can also use pick/notPick method..
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
            if(j>i and candidates[j] == candidates[j-1])    continue;   //skip duplicates..
            if(target < candidates[j])  return; //no need to check further(data is sorted)..
            
            combination.push_back(candidates[j]);   //store..
            help(j, target-candidates[j], candidates, combination, res);
            combination.pop_back(); //backtrack..
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());//to make all the repeating no together..
        vector<int> combination;
        vector<vector<int>> res;
        help(0, target, candidates, combination, res);
        
        return res;
    }
};