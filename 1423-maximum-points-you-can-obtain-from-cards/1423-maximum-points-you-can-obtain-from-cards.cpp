class Solution {
public:
    //TC-O(n)..
    //Find minimum sum subarray of size n-k, so our ans will be totalSum-miniSumSubarray..
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);    //totalSum..
        k = n-k;
        if(k==0)    return sum;
        
        int subarraySum = 0;
        for(int i=0; i<k; i++)  subarraySum += v[i];
        int mini = subarraySum;
        int i=0, j=k-1;
        while(j<n)
        {
            subarraySum -= v[i];
            i++;
            j++;
            if(j>=n)    break;
            subarraySum += v[j];
            mini = min(mini, subarraySum);
        }
        return sum-mini;
    }
};