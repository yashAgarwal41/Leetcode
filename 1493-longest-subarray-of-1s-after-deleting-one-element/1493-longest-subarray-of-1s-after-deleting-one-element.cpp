class Solution {
public:
    //Sliding Windoe..TC-O(n)...
    int longestSubarray(vector<int>& v) {
        int n = v.size(), k=0;
        int maxi = 0, i=0, j=0;
        while(i<n and j<n)
        {
            if(v[j]==0) k++;
            while(k > 1)
            {
                k -= v[i]==0;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi-1;
    }
};