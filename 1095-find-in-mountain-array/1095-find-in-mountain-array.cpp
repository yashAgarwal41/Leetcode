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
    int findPeak(int n, MountainArray &mountainArr)
    {
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
        return peak;
    }
    int findInLeft(int low, int high, int target, MountainArray &mountainArr)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val == target)   return mid;
            if(val>target)  high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    int findInRight(int low, int high, int target, MountainArray &mountainArr)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val == target)   return mid;
            if(val>target)  low = mid+1;
            else high= mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), mini=INT_MAX;
        
        int peak = findPeak(n, mountainArr);
        if(mountainArr.get(peak) == target) return peak;
        int left = findInLeft(0, peak-1, target, mountainArr);
        if(left!=-1)  return left;
        int right = findInRight(peak+1, n-1, target, mountainArr);
        return right;
        
    }
};