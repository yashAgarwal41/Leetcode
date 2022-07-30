class Solution {
public:
    //Sliding Window..TC-O(n)..
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), maxi = 0;
        int i=0, j=0, cnt=0;
        while(i<n and j<n)
        {
            if(nums[j]==0)
            {
                k--;
                while(k<0)
                {
                    k += nums[i]==0; 
                    i++;
                }
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};