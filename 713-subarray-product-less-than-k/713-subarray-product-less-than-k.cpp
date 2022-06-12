class Solution {
public:
    //Sliding Window...
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        int n = v.size(), i=0, j=0;
        int ans = 0, prod=v[0];
        while(i<n and j<n)
        {
            if(prod<k)
            {
                ans += j-i+1;
                j++;
                if(j<n) prod *= v[j];
            }
            else 
            {
                prod /= v[i];
                i++;
            }
        }
        return ans;
    }
};