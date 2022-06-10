class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char, int> map;
        int i=0, j=0, maxi=0;
        while(j<n)
        {
            if(map.find(s[j])!=map.end())
            {
                if(i<=map[s[j]])
                    i=map[s[j]]+1;
            }
            map[s[j]] = j;
            j++;
            maxi=max(maxi, j-i);
        }
        return maxi;
    }
};