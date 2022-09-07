#define ll long long
class Solution {
public:
    //Binary Search..TC-O(nlogn)
    bool canDistribute(long long k, int mid, vector<int> &v)
    {
        long long child=0;
        for(auto &i:v)
        {
            child += (i*1LL)/mid; //cnt no of child which can be distributed 'mid' candies..
        }
        if(child>=k)    return true;
        else return false;
    }
    int maximumCandies(vector<int>& v, long long k) {
        int n = v.size();
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        if(sum < k) return 0;
        if(sum == k)    return 1;
        
        int low = 1, high = 1e7, ans = 0;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2; 
            //can we distribute exactly 'mid' candies to each child..
            if(canDistribute(k, mid, v))
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
    }
};