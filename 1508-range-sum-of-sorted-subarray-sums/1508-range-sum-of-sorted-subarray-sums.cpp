class Solution {
public:
    //TC-O(n*n)..
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<long long> v;
        for(int i=0; i<n; i++)
        {
            long long sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += (long long)nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        long long tsum = 0;
        for(int i=left-1; i<right; i++)
            tsum = (tsum%mod + v[i]%mod)%mod;
        return tsum;
    }
};