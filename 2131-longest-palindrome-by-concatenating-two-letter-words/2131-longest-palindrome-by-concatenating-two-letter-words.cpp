class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size(), cntSame = 0;
        unordered_map<string, int> freq;
        for(int i=0; i<n; i++)
        {
            freq[words[i]]++;
        }
        // for(auto it:freq)   cout<<it.first<<" "<<it.second<<endl;
        int ans=0;
        for(auto &it: freq)
        {
            string str = it.first;
            if(str[0] == str[1])    
            {
                ans += 4*(it.second/2);
                cntSame += it.second%2;
            }
            else 
            {
                string rev = "";
                rev += str[1];
                rev += str[0];
                if(freq.find(rev) != freq.end())
                {
                    ans += 2*(min(freq[str], freq[rev]));
                }
            }
        }
        
        if(cntSame) ans+=2;
        return ans;
        
    }
};