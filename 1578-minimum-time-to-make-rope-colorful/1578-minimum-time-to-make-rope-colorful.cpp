class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int n = s.size(), ans=0;
        
        int i=1;
        while(i<n)
        {
            if(s[i] != s[i-1])
            {
                i++;    continue;
            }
            
            int maxi = time[i-1]; 
            ans += time[i-1];
            while(i<n and s[i] == s[i-1])
            {
                maxi = max(maxi, time[i]);
                ans += time[i++];
            }
            ans -= maxi;
        }
        return ans;
    }
};