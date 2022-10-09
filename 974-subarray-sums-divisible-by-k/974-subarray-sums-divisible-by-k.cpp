class Solution {
public:
    //Subarray Sums Equals 'k' algo
    //TC - O(n)..
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans=0, sum=0;
        unordered_map<int, int> map;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(abs(sum%k)==0)    ans++;
            //subarraySum % k = 0;  means (currSum - prefSum)%k = 0, so 
            //currSum%k - prefSum%k = 0 -> prefSum % k = currSum % k;
            //here prefSum%k is 'tar'.. 
            int tar = sum%k;
            if(tar<0)   tar += k;
            ans += map[tar];
            map[tar]++;
        }
        return ans;
    }
};