/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    //Binary Search, TC-(logn)..
    //find peak element and then search for target in 2 different regions..
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), mini=INT_MAX;
        int low = 0, high = n-1, peak;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int a, b = mountainArr.get(mid), c;
            if(mid > 0) a = mountainArr.get(mid-1);
            if(mid<n-1) c = mountainArr.get(mid+1);
            
            if(mid>0 and mid<n-1 and a<b and b>c)
            {
                peak=mid;
                break;
            }
            if(mid>0 and a<b)   low = mid+1;
            else if(mid<n-1 and b>c)    high = mid-1;
            else if(mid==0) low++;
            else high--;    //if(mid==n-1)
        }
        cout<<peak<<endl;
        if(mountainArr.get(peak) == target) return peak;
        
        low = 0, high = peak-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val == target)   return mid;
            if(val>target)  high = mid-1;
            else low = mid+1;
        }
        low = peak+1, high = n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val == target)   return mid;
            if(val>target)  low = mid+1;
            else high = mid-1;
        }
    
        return -1;
    }
};