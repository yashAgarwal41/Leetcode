class Solution {
public:
    //Backtracking  + dp..
    int mini = INT_MAX, n;
    void help(int i, int maxTime, vector<int> &dp, vector<int> &tasks)
    {
        if(dp.size() >= mini)  return;
        if(i>=n)
        {
            int sz = dp.size();
            mini = min(mini, sz);
            return;
        }
        
        for(int j=0; j<dp.size(); j++)
        {
            if(dp[j] + tasks[i] <= maxTime)
            {
                dp[j] += tasks[i];
                help(i+1, maxTime, dp, tasks);
                dp[j] -= tasks[i];
            }
        }
        dp.push_back(tasks[i]);
        help(i+1, maxTime, dp, tasks);
        dp.pop_back();
    }
    int minSessions(vector<int>& tasks, int maxTime) {
        n = tasks.size();
        mini = n;
        vector<int> dp;
        help(0, maxTime, dp, tasks);
        return mini;
    }
};