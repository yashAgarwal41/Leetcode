class Solution {
public:
    //Memoization..TC-O(n*n)..
    int n;
    int dp[1001][1001];
    
    //sort according to length of the string..
    static bool compare(string &s1, string &s2)
    {
        return s1.size()<s2.size();
    }
    
    //check 2 string are predecessor or not..
    bool isPredecessor(string &prevStr, string &currStr)
    {
        int a = prevStr.length(), b = currStr.length();
        if(b-a != 1)  return false;
        int cnt=0, i=0, j=0;
        
        while(i<a and j<b)
        {
            if(prevStr[i] == currStr[j])
            {
                i++;
                j++;
            }
            else 
            {
                j++;
                cnt++;
            }
        }
        return cnt<=1 ? true : false;
    }
    
    //recursion function
    int help(int i, int prev, vector<string> &words)
    {
        if(i>=n)    return 0;
        if(prev!=-1 and dp[i][prev]!=-1)    return dp[i][prev];
        
        //pick..
        int pick = 0;
        if(prev==-1 or isPredecessor(words[prev], words[i]))
            pick = 1 + help(i+1, i, words);
        
        //notPick..
        int notPick = help(i+1, prev, words);
        
        if(prev!=-1)    return dp[i][prev] = max(pick, notPick);
        else return max(pick, notPick);
    }
    
    //main function..
    int longestStrChain(vector<string>& words) {
        n=words.size();
        sort(words.begin(), words.end(), compare);
        memset(dp, -1, sizeof dp);
        return help(0, -1, words);
    }
};