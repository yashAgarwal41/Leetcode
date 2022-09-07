class Solution {
public:
    //Binary search..TC-O(nlogn)
    int smallestDivisor(vector<int>& v, int threshold) {
        int n = v.size();
        int low = 1, high = 1e6, ans;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int div=0;
            for(auto &i:v)  div += ceil((i*1.0)/mid);
            
            if(div<=threshold)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return ans;
    }
};