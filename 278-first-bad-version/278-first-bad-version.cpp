// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, ans = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)==true) 
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};