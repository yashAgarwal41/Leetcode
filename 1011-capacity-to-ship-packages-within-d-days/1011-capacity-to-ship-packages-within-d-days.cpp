class Solution {
public:
    //Binary Search, TC-O(nlogn)..
    bool isPossible(int days, int mid, vector<int> &v)
    {
        int sum=0;
        days--;
        for(int i=0; i<v.size(); i++)
        {
            if(sum + v[i] > mid)
            {
                days--;
                if(days<0)  return false;   //cannot be shipped in 'days' days in 'mid' capacity ship..
                sum=v[i];
            }
            else sum += v[i];
        }
        return true;
    }
    int shipWithinDays(vector<int>& v, int days) {
        int n = v.size();
        int low=*max_element(v.begin(), v.end()), high = 1e8, ans;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(days, mid, v))
            {
                ans = mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};