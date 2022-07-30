class Solution {
public:
    //TC-O(n*26), SC-O(26)
    void countMaxFreq(string &str2, vector<int> &freq)
    {
        vector<int> individFreq(26, 0);
        for(auto &c : str2)
        {
            individFreq[c-'a']++;
        }
        for(int i=0; i<26; i++)
            freq[i] = max(freq[i], individFreq[i]);
        
    }
    bool isSubset(string &str1, vector<int> freq)
    {
        for(auto &c : str1)
        {
            if(freq[c-'a']) //if that character exist in str, then decrease its freq..
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
        for(auto &str2 : words2)    //first calculate the maxFreq of letters in words2..
        {
            countMaxFreq(str2, freq);   
        }
        
        vector<string> res;
        for(auto &str1 : words1)
        {
            if(isSubset(str1, freq))
                res.push_back(str1);
        }
        return res;
    }
};