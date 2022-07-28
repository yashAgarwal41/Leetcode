class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, string>> dupc;
        for(int i=0; i<n; i++)
        {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            dupc.push_back({strs[i], temp});
        }
        // sort(strs.begin(), strs.end());
        sort(dupc.begin(), dupc.end());
        vector<vector<string>> res;
        string prev = "-";
        vector<string> ans;
        for(int i=0; i<n; i++)
        {
            if(dupc[i].first==prev or prev == "-")
            {
                // cout<<"hel";
                prev = dupc[i].first;
                ans.push_back(dupc[i].second);
            }
            else 
            {
                // cout<<"byr";
                res.push_back(ans);
                ans.clear();
                prev = dupc[i].first;
                ans.push_back(dupc[i].second);
            }
        }
        if(ans.size())  res.push_back(ans);
        return res;
    }
};