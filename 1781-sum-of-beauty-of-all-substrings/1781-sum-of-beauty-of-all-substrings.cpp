class Solution {
public:
    //BruteForce..TC-O(n*n*26)
    int beautySum(string s) {
        int n = s.size();
        int ans=0;
        
        for(int i=0; i<n-1; i++)
        {
            unordered_map<char, int> freq;
            freq[s[i]]++;
            for(int j=i+1; j<n; j++)
            {
                freq[s[j]]++;
                if(freq.size()>=2)
                {
                    int mini=INT_MAX, maxi=INT_MIN;
                    for(auto &it:freq)
                    {
                        mini = min(mini, it.second);
                        maxi = max(maxi, it.second);
                    }
                    ans += maxi-mini;
                }
            }
        }
        return ans;
    }
};