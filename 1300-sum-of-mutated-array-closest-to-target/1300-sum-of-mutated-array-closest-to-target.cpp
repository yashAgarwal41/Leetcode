class Solution {
public:
    //Binary Seacrh  + find peak element, TC-O(nlog(target))..
    int calculateDiff(int mid, int target, vector<int> &arr)
    {
        int sum=0;
        for(auto &i:arr)
        {
            if(i>mid)   sum+=mid;
            else sum+=i;
        }
        return abs(sum - target);
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int low=0, high=1e5, ans;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int diff1 = calculateDiff(mid, target, arr);
            int diff2 = calculateDiff(mid+1, target, arr);
            
            //mid & mid+1 sums greater than target, so take 'mid'
            //e,g, sum[mid]=11, sum[mid+1]=13, and target=10
            if(diff1 <= diff2)  
            {
                ans = mid;
                high = mid-1;
            }
            //mid & mid+1 sums lesser than target, so take 'mid+1'..
            //e,g, sum[mid]=7, sum[mid+1]=9, and target=10
            else low = mid+1;   
        }
        return ans;
    }
};