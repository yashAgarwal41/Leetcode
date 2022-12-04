class Solution {
public:
    int minimumAverageDifference(vector<int>& v) {
        int n = v.size();
        int ans, mini = INT_MAX;
        long curSum = 0, totSum = accumulate(v.begin(), v.end(), 0LL);
        for(int i=0; i<n; i++)
        {
            curSum += v[i];
            long avg1 = curSum/(i+1);
            long avg2 = (i<n-1) ? (totSum - curSum)/(n-i-1) : 0;
            long diff = abs(avg1-avg2);
            if(diff == 0)   return i;
            if(mini > diff)
            {
                ans = i;
                mini = diff;
            }
        }
        return ans;
    }
};