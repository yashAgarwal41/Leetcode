class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int i=find(nums.begin(), nums.end(), mini) - nums.begin();
        int j=find(nums.begin(), nums.end(), maxi) - nums.begin();
        int left = max(i, j) + 1;
        int right = max(n-i, n-j);
        int both = min(i, j)+1 + min(n-i, n-j);
        
        return min({left, right, both});
    }
};