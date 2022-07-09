#define ll long long
class Solution {
public:
    //Greedy, Sorting
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size(), sum=0, mod=1e9+7;
        vector<int> freq = nums1;
        sort(freq.begin(), freq.end());
        
        for(int i=0; i<n; i++)
            sum += abs(nums1[i]-nums2[i]);
        ll mini = sum, temp=sum;
        ll maxDiff = 0;
        for(int i=0; i<n; i++)
        {
            ll currDiff = abs(nums1[i]-nums2[i]);
            int ind = lower_bound(freq.begin(), freq.end(), nums2[i]) - freq.begin();
            if(ind>0)   
                maxDiff = max(maxDiff, currDiff - abs(freq[ind-1] - nums2[i]));
            
            if(ind!=n)
                maxDiff = max(maxDiff, currDiff - abs(freq[ind] - nums2[i]));
            
        }
        return (sum - maxDiff)%mod;
    }
};
