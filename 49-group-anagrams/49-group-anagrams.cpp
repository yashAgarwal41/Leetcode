class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, string>> dupc;
        // dupc contains-> {sorted, actual} string[i] as a pair..
        for(int i=0; i<n; i++)
        {
            string orig = strs[i];  //original
            sort(strs[i].begin(), strs[i].end());   //sorted
            dupc.push_back({strs[i], orig});    
        }
        sort(dupc.begin(), dupc.end()); //now sort the 'dupc' and store all anagram groups..
        vector<vector<string>> res;
        string prev = "-";
        vector<string> ans;
        for(int i=0; i<n; i++)
        {
            if(dupc[i].first == prev or prev == "-")
            {
                prev = dupc[i].first;
                ans.push_back(dupc[i].second);  //store the actual string..
            }
            else 
            {
                res.push_back(ans);
                ans.clear();
                prev = dupc[i].first;
                ans.push_back(dupc[i].second);  //store the actual string..
            }
        }
        if(ans.size())  res.push_back(ans);
        return res;
    }
};