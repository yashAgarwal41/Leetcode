class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string> res;
        unordered_map<char, char> mmap1, mmap2;
        for(auto &str : words)
        {
            mmap1.clear();
            mmap2.clear();
            bool found=1;
            for(int i=0; i<n; i++)
            {
                if(!mmap1.count(str[i]))
                {
                    mmap1[str[i]] = pattern[i];
                }
                else if(mmap1[str[i]]!=pattern[i])
                {
                    found=0;    break;
                }
                
                if(!mmap2.count(pattern[i]))
                    mmap2[pattern[i]] = str[i];
                else if(mmap2[pattern[i]]!=str[i])
                {
                    found=0;    break;
                }
            }
            if(found)   res.push_back(str);
        }
        return res;
    }
};