class Solution {
public:
    //Binary Search..
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low = 1, high = 1e9, mini = INT_MAX;  //high = *max_element(piles)..
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            long long cnt = 0;
            for(auto &it : piles)
            {
                cnt += ceil((it*1.0)/mid);
            }
            
            if(cnt <= h)
            {
                mini = min(mini, mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return mini;
    }
};