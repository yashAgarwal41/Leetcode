class Solution {
public:
    //memoization..TC-O(365)
    int n;
    int dp[366];
    int help(int i, vector<int> &days, vector<int> &costs)
    {
        if(i>=n)    return 0;    
        if(dp[i]!=-1)   return dp[i];
        //1-day plan
        int a = help(i+1, days, costs) + costs[0];
        
        //7-day plan
        int j = upper_bound(days.begin(), days.end(), days[i]+7-1) - days.begin();
        int b = help(j, days, costs) + costs[1];
        
        //30-day plan
        int k = upper_bound(days.begin(), days.end(), days[i]+30-1) - days.begin();
        int c = help(k, days, costs) + costs[2];
        
        return dp[i] = min({a, b, c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(dp, -1, sizeof dp);
        return help(0, days, costs);
    }
};