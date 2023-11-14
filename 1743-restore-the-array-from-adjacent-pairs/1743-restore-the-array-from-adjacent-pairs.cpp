class Solution {
public:
    //hashmap, TC-O(n), SC-O(n)
    vector<int> restoreArray(vector<vector<int>>& vv) {
        int n = vv.size();
        unordered_map<int, vector<int>> map1;
        for(int i=0; i<n; i++)
        {
            map1[vv[i][0]].push_back(vv[i][1]);
            map1[vv[i][1]].push_back(vv[i][0]);
        }
        
        vector<int> res;
        for(auto &it:map1)
        {
            if(it.second.size() == 1)
            {
                res.push_back(it.first);
                res.push_back(it.second[0]);
                break;
            }
        }
        
        while(res.size() != n+1)
        {
            int prev = res.back(), prev2 = res[res.size()-2];
            auto next = map1[prev];
            if(prev2 == next[0])  res.push_back(next[1]);
            else res.push_back(next[0]);
        }
        return res;
    }
};
