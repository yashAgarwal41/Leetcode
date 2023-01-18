class Solution {
public:
    int maxSumKadane(vector<int> &v)
    {
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<v.size(); i++)
        {
            sum += v[i];
            if(sum<v[i])   sum = v[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
    int minSumKadane(vector<int> &v)
    {
       int sum = 0, mini = INT_MAX;
        for(int i=0; i<v.size(); i++)
        {
            sum += v[i];
            if(sum>v[i])    sum = v[i];
            mini = min(mini, sum);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& v) {
        int n = v.size();
        int totSum = accumulate(v.begin(), v.end(), 0);
        int minSum = minSumKadane(v);
        int maxSum = maxSumKadane(v);
        if(maxSum<0)    return *max_element(v.begin(), v.end());
        return max(totSum - minSum, maxSum);
    }
};
