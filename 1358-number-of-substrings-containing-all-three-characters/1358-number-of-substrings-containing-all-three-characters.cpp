class Solution {
public:
    //Sliding Window..TC-O(n)..
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, 0);
        int i=0, j=0, ans=0;
        while(i<n and j<n)
        {
            freq[s[j]-'a']++;
            bool good=1;
            while(i<n and good)
            {
                for(int c=0; c<3; c++)
                {
                    if(freq[c]==0)  good=0;
                }
                if(good)
                { 
                    ans += n-j;
                    freq[s[i]-'a']--;
                    i++;
                }
            }
            
            j++;
        }
        return ans;
    }
};