class Solution {
public:
    //Sliding window...(Standard solution)
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        if(k<=1)    return 0;
        int n=v.size();
        int l=0, r=0;
        int ans=0, prod=1;
        while(r<n)
        {
            prod *= v[r];
            while(prod>=k)
            {
                prod /= v[l];
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};