class Solution {
public:
    //Memoization(0-1 knapsack)..
    int dp[1001][1001];
    int help(int i, int prev, vector<int> &scores)
    {
        if(i>=scores.size())    return 0;   
        if(prev!=-1 and dp[i][prev]!=-1)    return dp[i][prev];
        
        //pick..
        int pick = 0;
        if(prev==-1 or scores[i]>=scores[prev])
            pick = scores[i] + help(i+1, i, scores);
        
        //notPick..
        int notPick = help(i+1, prev, scores);
        
        if(prev!=-1)    return dp[i][prev] = max(pick, notPick);
        else    return max(pick, notPick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        //sorting scores a/c to age of people..Now focus only on increasing scores..
        vector<pair<int, int>> vp;
        for(int i=0; i<n; i++)
        {
            vp.push_back({ages[i], scores[i]});
        }
        sort(vp.begin(), vp.end());
        for(int i=0; i<n; i++)
            scores[i] = vp[i].second;
        
        memset(dp, -1, sizeof dp);
        return help(0, -1, scores);
    }
};