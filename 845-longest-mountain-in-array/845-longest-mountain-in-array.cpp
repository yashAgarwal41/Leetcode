class Solution {
public:
    //TC-O(n)..
    int longestMountain(vector<int>& v) {
        int n = v.size();
        int maxi = 0;
        int i=0, j=0, inc=0, dec=0;
        while(j<n-1)
        {
            int inc = 0 , dec = 0;
            while(j<n-1 and v[j]<v[j+1])    j++, inc++;    //increasing
            while(j<n-1 and v[j]>v[j+1])    j++, dec++;    //decreasing
            if(inc>0 and dec>0)    maxi = max(maxi, j-i+1);
            
            while(j<n-1 and v[j] == v[j+1]) j++;    //skip equal elements
            i=j;    //start new subarray from now..
        }
        return maxi;
    }
};