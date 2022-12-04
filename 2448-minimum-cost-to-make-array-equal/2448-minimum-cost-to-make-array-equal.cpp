class Solution {
public:
    
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
        int n = nums.size();
        long long ans = 0;
        
        int low = 1, high = 1e6, mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            long long cost1 = help(mid, nums, cost);
            long long cost2 = help(mid+1, nums, cost);
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
    