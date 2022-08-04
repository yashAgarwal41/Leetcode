class Solution {
public:
    //Binary Search..TC-O(nlogn), SC-O(1), without modifying
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=1, high=n-1;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            int cnt=0;
            for(auto &it:nums)  cnt += it<=mid;
            if(cnt<=mid)    
            {
                low=mid+1;
            }
            else high=mid;
        }
        return low;
    }
};