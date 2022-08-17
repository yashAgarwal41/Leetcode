class Solution {
public:
    //BackTracking, TC-O(2^9)
    int n;
    string ans="999999999";
    
    void help(int i, string &pattern, string curr)
    {
        if(i>=n)
        {
            if(curr.size()==n+1)
                ans = min(ans, curr);
            return;
        }
        
        for(char j='1'; j<='9'; j++)
        {
            auto it = find(curr.begin(), curr.end(), j);
            if(it!=curr.end())  continue;
            if(pattern[i]=='I')
            {
                if(curr[i]<j)
                {
                    curr += j;
                    help(i+1, pattern, curr);
                    curr.pop_back();
                }
            }
            else 
            {
                if(curr[i]>j)
                {
                    curr += j;
                    help(i+1, pattern, curr);
                    curr.pop_back();
                }
            }
        }
    }
    
    string smallestNumber(string pattern) {
        n = pattern.size();
        for(char c='1'; c<='9'; c++)
        {
            string x = "";
            x+=c;
            help(0, pattern, x);
        }
        return ans;
    }
};