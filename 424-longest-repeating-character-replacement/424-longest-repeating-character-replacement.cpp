class Solution {
public:
    //SLiding Window..Tc-O(26*n)
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxi = 0;
        int i=0, j=0;
        freq[s[0]-'A']++;
        while(j<n)
        {
            int windowSize = j-i+1, maxFreq = 0;
            for(auto &x:freq)
                maxFreq = max(maxFreq, x);
            
            if(windowSize - maxFreq <= k)
            {
                maxi = max(maxi, windowSize);
                j++;
                if(j<n) 
                    freq[s[j]-'A']++;
            }
            else 
            {
                freq[s[i]-'A']--;
                i++;
            }
        }
        return maxi;
    }
};