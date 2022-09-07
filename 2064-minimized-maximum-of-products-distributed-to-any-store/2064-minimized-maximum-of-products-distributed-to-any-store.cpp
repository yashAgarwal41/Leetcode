class Solution {
public:
    //Binary Search, TC-O(nlogn)..
    //high = 1e5, because e.g, n=1, m=1, v=[1e5], then we need to distribute all '1e5' products to the only shop..
    bool canDistribute(int n, int mid, vector<int> &v)
    {
        
        for(auto &i : v)
        {
            n -= ceil((1.0*i)/mid);
            if(n<0) return false;   //means 'n' is not sufficient to distribute the quantity 'mid'..
            // means it requires more than n shops to distribute all products
        }
        return true;    // distributed all products
    }
    
    int minimizedMaximum(int n, vector<int>& v) {
        int m = v.size();
        int low = 1, high = 1e5, ans;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(canDistribute(n, mid, v))
            {
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;   //we can not hold 'mid' amount each in 'n' shops, so increase quantity 'mid'..
        }
        
        return ans;
    }
};