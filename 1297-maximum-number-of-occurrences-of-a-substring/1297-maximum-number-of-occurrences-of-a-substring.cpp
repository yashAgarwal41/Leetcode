class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), i=0, j=0, ans=0;
        unordered_map<string , int> mapFreq;
        unordered_map<int, int> map;
        while(i<n and j<n)
        {
            map[s[j]]++;
            while(map.size() > maxLetters or (j-i+1) > maxSize)
            {
                map[s[i]]--;
                if(map[s[i]]==0)    map.erase(s[i]);
                i++;
            }
            int windowSize = j-i+1;
            if(windowSize>=minSize and windowSize<=maxSize) 
            {
                for(int k=i; k<=j-minSize+1; k++)
                {
                    string temp="";
                    for(int x=k; x<=j; x++)
                        temp += s[x];
                    mapFreq[temp]++;
                }
            }
            j++;
        }
        for(auto it:mapFreq)    
        {
            // cout<<it.first<<" "<<it.second<<endl;
            ans = max(ans, it.second);
        }
        return ans;
    }
};