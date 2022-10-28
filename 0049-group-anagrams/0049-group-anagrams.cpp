class Solution {
public:
    //TC-O(n*100)
    string countAndSort(string &str)
    {
        vector<int> freq(26, 0);
        for(auto &c:str)    freq[c-'a']++;
        
        string s = "";
        for(int i=0; i<26; i++)
        {
            while(freq[i]--)    s += (i+'a');
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mmap;
        
        for(auto &str:strs)
        {
            string s = countAndSort(str);
            mmap[s].push_back(str);
        }
        for(auto &v:mmap)    res.push_back(v.second);
        return res;
    }
};