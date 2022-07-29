class Solution {
public:
    //TC-O(n)
    bool checkPattern(string &s1, string &s2)
    {
        vector<int> match1(26, -1), match2(26, -1);
        for(int i=0; i<s1.size(); i++)
        {
            if(match1[s1[i]-'a'] == -1)
                match1[s1[i]-'a'] = s2[i] -'a';
            else if(match1[s1[i]-'a'] != s2[i] - 'a') 
                return false;
            
            if(match2[s2[i]-'a'] == -1)
                match2[s2[i]-'a'] = s1[i] - 'a';
            else if(match2[s2[i]-'a'] != s1[i] - 'a')
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string> res;
        for(auto &str : words)
        {
            if(checkPattern(str, pattern))
                res.push_back(str);
        }
        return res;
    }
};