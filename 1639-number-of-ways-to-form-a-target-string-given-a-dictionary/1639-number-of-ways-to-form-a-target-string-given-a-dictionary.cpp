class Solution {
public:
    //DP, TC-O(n*m)
    int n, m;
    int dp[1001][1001];
    int mod = 1e9+7;
    int help(int i, int col, string &target, vector<unordered_map<char, int>> &freq)
    {
        if(i>=target.size())    return 1;
        if(col>=n)  return 0;
        if(dp[i][col]!=-1)  return dp[i][col];
        long long pick=0, notPick=0;
        
        char c = target[i];
        if(freq[col].count(c))
        {
            pick = (pick + 1LL*freq[col][c]*help(i+1, col+1, target, freq))%mod;
        }
        
        notPick = help(i, col+1, target, freq)%mod;
        
        return dp[i][col] = (pick + notPick + 0LL)%mod;
    }
    int numWays(vector<string>& words, string target) {
        n = words[0].size(), m = target.size();
        memset(dp, -1, sizeof dp);
        
        vector<unordered_map<char, int>> freq(n);
        for(int j=0; j<words[0].size(); j++)
        {
            for(int i=0; i<words.size(); i++)
            {
                char c = words[i][j];
                freq[j][c]++;
            }
        }
        return help(0, 0, target, freq);
    }
};