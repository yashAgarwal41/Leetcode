class Solution {
public:
    //Sliding window..TC-O(n)
    //We have to find the max size subarray that sums = totalSum-x;
    //So use sliding window to calculate that subarray and update maxi
    //e.g v = [2, 3, 1, {2, 4}, 3]  x = 9, totSum = 15
    // so new target = 15-9=6..Find maximumSize subarray with sum 6
    //So it become standard problem- Subarray Sums Equals 'k' (v[i]>0, so use sliding window)..
                    
    int minOperations(vector<int>& v, int x) {
        long long n=v.size(), tot=0;
        for(auto &i:v)  tot+=i;
        long long target = tot-x, i=0, j=0;
        long long maxi = -1, sum=0;
        while(i<n and j<n)
        {
            sum += v[j];
            while(i<n and sum > target)
            {
                sum-=v[i];
                i++;
            }
            if(sum==target)
            {
                maxi = max(maxi, j-i+1);
            }
            j++;
        }
        if(maxi == -1)  return -1;
        else return n-maxi;
    }
};