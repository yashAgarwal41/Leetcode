class Solution {
public:
    //Recursion-BackTracking, TC-O(2^n)*n
    bool isPalindrome(string &s)
    {
        int n = s.size();
        for(int i=0; i<n/2; i++)
            if(s[i]!=s[n-i-1])  return false;
        return true;
    }
    
    void help(int i, string &s, vector<string> &partition, vector<vector<string>> &res)
    {
        if(i==s.size())
        {
            res.push_back(partition);
            return;
        }
        
        string pali = "";
        for(int j=i; j<s.size(); j++)
        {
            pali += s[j];
            if(isPalindrome(pali))
            {
                partition.push_back(pali);
                help(j+1, s, partition, res);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> partition;
        vector<vector<string>> res;
        help(0, s, partition, res);
        return res;
    }
};