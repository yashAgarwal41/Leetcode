class Solution {
public:
    //prefixSum.TC-O(n), SC-O(n)..
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int> maxFromLeft(n), maxFromRight(n);
        int maxi=v[0];
        for(int i=0; i<n; i++)
        {
            maxi=max(maxi, v[i]);
            maxFromLeft[i]=maxi;
        }
        maxi = v[n-1];
        for(int i=n-1; i>=0; i--)
        {
            maxi=max(maxi, v[i]);
            maxFromRight[i]=maxi;
        }
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans += min(maxFromLeft[i], maxFromRight[i]) - v[i];
        }
        
        return ans;
    }
};