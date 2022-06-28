class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int left=0, right=0, both=0, cnt=0;
        for(int i=0; i<n; i++)
        {
            left++;
            if(nums[i]==mini or nums[i]==maxi)
                cnt++;
            if(cnt==2)  break;
        }
        cnt=0;
        for(int i=n-1; i>=0; i--)
        {
            right++;
            if(nums[i]==mini or nums[i]==maxi)
                cnt++;
            if(cnt==2)  break;
        }
        for(int i=0; i<n; i++)
        {
            both++;
            if(nums[i]==mini or nums[i]==maxi)
                break;
        }
        for(int i=n-1; i>=0; i--)
        {
            both++;
            if(nums[i]==mini or nums[i]==maxi)
                break;
        }
        return min({left, right, both});
    }
};