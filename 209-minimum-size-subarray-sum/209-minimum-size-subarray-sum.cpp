class Solution {
public:
    //Sliding Window..TC-O(n)..
    int minSubArrayLen(int target, vector<int>& v) {
        int n=v.size(), l=0, r=0;
        int sum = 0, mini = INT_MAX;
        while(r<n)
        {
            sum+=v[r];
            while(sum>=target)
            {
                mini = min(mini, r-l+1);
                sum-=v[l];
                l++;
            }
            
            r++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};