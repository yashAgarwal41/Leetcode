class Solution {
public:
    //TC-O(n*26), SC-O(26)
    bool isSubset(string &str, vector<int> freq)
    {
        for(auto &c : str)
        {
            if(freq[c-'a']) 
                freq[c-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(freq[i]!=0)  return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        for(auto &str : words2)
        {
            vector<int> individFreq(26, 0);
            for(auto &c : str)
            {
                individFreq[c-'a']++;
            }
            for(int i=0; i<26; i++)
                freq[i] = max(freq[i], individFreq[i]);
        }
        vector<string> res;
        for(auto &str : words1)
        {
            if(isSubset(str, freq))
                res.push_back(str);
        }
        return res;
    }
};