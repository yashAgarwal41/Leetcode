class Solution {
public:
    //Binary Search, TC-O(nlogn)
    bool canSplit(int mid, int m, vector<int> &v)
    {
        int subSum=0;
        m--;
        for(auto &i:v)
        {
            if(i>mid)   return false;
            subSum += i;
            if(subSum>mid)
            {
                subSum = i;
                m--;
            }
        }
        if(m<0) return false;
        return true;
    }
    int splitArray(vector<int>& v, int m) {
        int n = v.size();
        int low=0, high = 1e9, ans;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(canSplit(mid, m, v))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};