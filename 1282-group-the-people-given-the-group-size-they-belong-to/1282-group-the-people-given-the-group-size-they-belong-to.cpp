class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> res;
        unordered_map<int, vector<int>> map;
        for(int i=0; i<n; i++)
            map[v[i]].push_back(i);
        for(auto &it:map)
        {
            int cnt = it.first;
            vector<int> temp;
            for(auto &j:it.second)
            {
                temp.push_back(j);
                cnt--;
                if(cnt==0)
                {
                    cnt = it.first;
                    res.push_back(temp);
                    temp={};
                }
            }
        }
        return res;
    }
};