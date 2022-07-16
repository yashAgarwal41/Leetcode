class Solution {
public:
    //BruteForce..TC-O(n*n*26)
    int beautySum(string s) {
        int n = s.size();
        int ans=0;
        
        for(int i=0; i<n-1; i++)
        {
            int freq[26] = {0};
            freq[s[i]-'a']++;
            for(int j=i+1; j<n; j++)
            {
                freq[s[j]-'a']++;
                int mini = INT_MAX, maxi = INT_MIN;
                for(int k=0; k<26; k++)
                {
                    if(freq[k]) mini = min(mini, freq[k]);
                    if(freq[k]) maxi = max(maxi, freq[k]);
                }
                ans += maxi-mini;
            }
        }
        return ans;
    }
};