class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0, n=s.size(), m=t.size();
        if(n>m) return false;
        while(i<n and j<m)
        {
            if(s[i] == t[j])    i++;
            j++;
        }
        if(i==n)    return 1;
        return 0;
    }
};