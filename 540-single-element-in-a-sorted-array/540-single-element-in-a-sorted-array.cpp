class Solution {
public:
    //Binary Search..TC-O(nlogn)
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int low=0, high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(mid>0 and v[mid] == v[mid-1])
            {
                if((mid+1)%2==0)    low = mid+1;
                else high = mid-1;
            }
            else if(mid<n-1 and v[mid] == v[mid+1])
            {
                if((n-mid)%2==0)    high = mid-1;
                else low = mid+1;
            }
            else return v[mid];
        }
        return v[low];
        
    }
};