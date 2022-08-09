class Solution {
public:
    bool help(string &s1, string &s2)
    {
        for(int i=0; i<s1.size(); i++)
        {
            if(s2[i]>s1[i]) return false;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return help(s1, s2) or help(s2, s1);
    }
};