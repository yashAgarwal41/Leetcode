class Solution {
public:
    //Binary Search, TC-O(nlog(1e9))
    bool canDistribute(int mid, int m, vector<int> &v)
    {
        int cntBalls = 1;
        int i=0, n = v.size(), prev = 0;
        while(prev<n and cntBalls<m)
        {
            auto it = lower_bound(v.begin(), v.end(), v[prev] + mid);
            if(it == v.end())   break;
            else 
            {
                cntBalls++;
                prev = it-v.begin();
            }
        }
        if(cntBalls<m)  return false;
        else return true;
    }
    int maxDistance(vector<int>& v, int m) {
        int n = v.size();
        sort(v.begin(), v.end());
        int low=1, high=1e9, ans;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(canDistribute(mid, m, v))
            {
                ans = mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};