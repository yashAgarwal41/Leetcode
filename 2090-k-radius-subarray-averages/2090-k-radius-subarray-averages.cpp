class Solution {
public:
    //PrefixSum..TC-O(n)
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ps(n+1);
        vector<int> res(n);
        for(int i=0; i<n; i++)
        {
            ps[i+1] = ps[i] + nums[i];
        }
        
        long long l, r, sum, avg;
        for(int i=0; i<n; i++)
        {
            l = i-k, r = i+k;
            if(l<0 or r>=n) 
            {
                res[i] = -1;
            }
            else 
            {
                sum = ps[r+1] - ps[l];
                avg = sum/(r-l+1);
                res[i] = avg;
            }
        }
        return res;
    }
};