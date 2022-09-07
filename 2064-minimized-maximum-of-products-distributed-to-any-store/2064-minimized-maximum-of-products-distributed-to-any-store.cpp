class Solution {
public:
    //Binary Search, TC-O(nlogn)..
    //high = 1e10, because e.g, n=1, m=1e5, v=[1e5, 1e5, ....1e5], then we need to distribute all '1e10' products to the only shop..
    int minimizedMaximum(int n, vector<int>& v) {
        int m = v.size();
        long low = 1, high = 1e10, ans;
        
        while(low<=high)
        {
            long mid = low + (high-low)/2;
            long totalShops = 0;    //totalShops that can hold the quantity 'mid'..
            for(auto &i : v)
            {
                totalShops += ceil((1.0*i)/mid);
            }
            
            if(totalShops <= n)
            {
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;   //we can not hold 'mid' amount each in 'n' shops, so increase quantity 'mid'..
        }
        
        return ans;
    }
};