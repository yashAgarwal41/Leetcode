class Solution {
public:
    //TC-O(n*100)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        map<map<char, int>, vector<string>> mmap;
        
        for(auto &str:strs)
        {
            map<char, int> freq;
            for(auto &c:str)
            {
                freq[c]++;
            }
            mmap[freq].push_back(str);
        }
        for(auto &v:mmap)    res.push_back(v.second);
        return res;
    }
};