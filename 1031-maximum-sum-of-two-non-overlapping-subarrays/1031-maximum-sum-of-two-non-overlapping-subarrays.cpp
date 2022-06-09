class Solution {
public:
    //PrefixSum algo..TC-O(n*n)
    int nextSum(int i, int &len, vector<int> &ps)   //return the maxSum for the after subarray.. 
    {
        int n=ps.size(), maxi=0;
        for(int j=i+len; j<n; j++)
        {
            int sum = ps[j] - ps[j-len];
            maxi=max(maxi, sum);
        }
        return maxi;
    }
    int maxSumTwoNoOverlap(vector<int>& v, int l1, int l2) {
        int n=v.size();
        //calculating prefixSum(1 based index)..
        vector<int> ps(n+1);
        for(int i=0; i<n; i++)  ps[i+1] = ps[i] + v[i];
        
        //taking l1 size subarray before, l2 size subarray after..
        int maxi=0;
        for(int i=l1; i<=n-l2; i++)
        {
            int sum1 = ps[i]-ps[i-l1];
            int sum2 = nextSum(i, l2, ps);
            maxi=max(maxi, sum1+sum2);
        }
        
        //taking l2 size subarray before, l1 size subarray after..
        for(int i=l2; i<=n-l1; i++)
        {
            int sum1 = ps[i]-ps[i-l2];
            int sum2 = nextSum(i, l1, ps);
            maxi=max(maxi, sum1+sum2);
        }
        
        return maxi;
    }
};