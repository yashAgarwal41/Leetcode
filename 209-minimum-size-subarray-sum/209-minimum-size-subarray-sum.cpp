class Solution {
public:
    //Sliding Window..TC-O(n)..
    int minSubArrayLen(int target, vector<int>& v) {
        int n=v.size(), l=0, r=0;
        int sum = 0, mini = INT_MAX;
        while(r<n)
        {
            sum+=v[r];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    sum-=v[l];
                    l++;
                }
                mini = min(mini, r-l+2);
            }
            r++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};