class Solution {
public:
    bool equal(vector<int> &freq1, vector<int> &freq2)
    {
        for(int i=0; i<26; i++)
        {
            if(freq1[i]!=freq2[i])  return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m<n) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        for(auto c:s1)  freq1[c-'a']++;
        
        int i=0, j=0;
        while(j<m)
        {
            freq2[s2[j]-'a']++;
            if(j-i+1 == n)
            {
                if(equal(freq1, freq2)) return true;
                else
                {
                    freq2[s2[i]-'a']--;
                    i++;
                    j++;
                }
            }
            else if(j-i+1 < n)   j++;
            
        }
        return false;
    }
};