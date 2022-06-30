class Solution {
public:
    //Map..TC-O(n)..
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> map;
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            int tar = target-nums[i];
            if(map.count(tar))
            {
                res.push_back(i);
                res.push_back(map[tar]);
                break;
            }
            else map[nums[i]] = i;
        }
        return res;
    }
};