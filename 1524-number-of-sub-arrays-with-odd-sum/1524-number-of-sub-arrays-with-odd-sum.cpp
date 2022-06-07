class Solution {
public:
    // Dp, TC-O(n)..
    // odd[i] stores the no. of subarray ending at arr[i] that has odd sum.
    // even[i] stores the no. of subarray ending at arr[i] that has even sum.
    int numOfSubarrays(vector<int>& v) {
        int n=v.size(), mod=1e9+7;
        int odd[n], even[n];
        if(v[0]&1)  odd[0] = 1, even[0]=0;
        else even[0] = 1, odd[0]=0;
        
        int ans = odd[0];
        for(int i=1; i<n; i++)
        {
            if(v[i]&1)  //if current num is odd
            {
                //so sum will be odd if we add it with even sum.
                odd[i] = even[i-1]+1;   
                even[i] = odd[i-1]; 
            }
            else //if current num is even
            {
                //so sum will be odd if we add it with odd sum.
                odd[i] = odd[i-1];
                even[i] = even[i-1]+1;
            }
            ans=(ans + odd[i]) % mod;
        }
        return ans;
    }
};