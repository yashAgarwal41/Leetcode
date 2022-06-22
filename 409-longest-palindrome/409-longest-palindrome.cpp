class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(), ans=0;
        bool oddFreq = 0;
        unordered_map<char, int> map;
        for(auto &c : s)    map[c]++;
        for(auto &it : map)
        {
            if(it.second % 2 == 0 )
                ans += it.second;
            else 
            {
                ans += (it.second/2)*2;
                oddFreq = 1;
            }
        }
        
        return ans += (oddFreq == 1);
    }
};