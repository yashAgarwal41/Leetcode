class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), cnt=0;
        vector<int> freq(26, 0);
        for(auto c:s)   freq[c-'a']++;
        for(auto c:t)
        {
            if(freq[c-'a']>0)   freq[c-'a']--, cnt++;
        }
        return n-cnt;
    }
};