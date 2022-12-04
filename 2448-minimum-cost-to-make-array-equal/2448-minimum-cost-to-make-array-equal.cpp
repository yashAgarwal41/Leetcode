class Solution {
public:
    //Apply Binary-Search, TC-O(nlogn)
    //Compare between mid and mid+1, and then decide where to move in binary search..
    long long help(int mid, vector<int> &nums, vector<int> &cost)
    {
        long long totCost = 0;
        for(int i=0; i<nums.size(); i++)
        {
            totCost += 1LL*cost[i]*abs(nums[i] - mid);
        }
        return totCost;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = 0;
        int n = nums.size(), low = 1, high = 1e6, mid;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            long long cost1 = help(mid, nums, cost);    //cost at value = mid...
            long long cost2 = help(mid+1, nums, cost);  //cost at value = mid+1...
            if(cost1 <= cost2)
            {
                ans = cost1;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
    