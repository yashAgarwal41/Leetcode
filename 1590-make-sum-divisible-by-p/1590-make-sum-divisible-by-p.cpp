class Solution {
public:
    //Subarray sums equals 'k', TC-O(n)
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totSum = accumulate(nums.begin(), nums.end(), 0LL);
        int k = totSum%p;
        if(k == 0)  return 0;
        if(p>totSum)    return -1;
        
        //subarray to delete should have remainder 'k', so we have to find subarray with 
        //subarraySum%p = k, i.e, (currSum - prevSum)%p = k
        //prevSum%p = currSum%p - k;
        //here target is prevSum
        unordered_map<int, int> map;    //store -> (currSum%p, index);
        int mini = INT_MAX;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum%p == k)  mini = min(mini, i+1);
            int target = sum%p - k;
            if(target<0)    target += p;
            if(map.find(target) != map.end())   mini = min(mini, i - map[target]);
            map[sum%p] = i;
        }
        return mini == (INT_MAX) or mini == n ? -1 : mini;
    }
};