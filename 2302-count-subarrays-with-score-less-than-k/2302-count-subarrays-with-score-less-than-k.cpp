class Solution {
public:
    //Sliding Window..(Standard Problem)..
    long long countSubarrays(vector<int>& v, long long k) {
        int n=v.size();
        int i=0, j=0;
        long long ans = 0, sum=0;
        while(j<n)
        {
            sum+=v[j];
            long long prod = 1LL * sum * (j-i+1);
            while(prod>=k)
            {
                sum -= v[i];
                i++;
                prod = 1LL * sum * (j-i+1);
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};