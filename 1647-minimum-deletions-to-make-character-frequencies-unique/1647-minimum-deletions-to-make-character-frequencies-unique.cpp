class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        map<char, int> freq;
        for(auto &c:s)
            freq[c]++;
        map<int, int, greater<int>> freqCnt;
        for(auto &it: freq)
        {
            freqCnt[it.second]++;
        }
        
        int ans=0;
        for(auto &it:freqCnt)
        {
            if(it.first==0) break;
            if(it.second>1)
            {
                ans+=it.second-1;
                freqCnt[it.first-1]+=it.second-1;
            }
        }
        return ans;
    }
};