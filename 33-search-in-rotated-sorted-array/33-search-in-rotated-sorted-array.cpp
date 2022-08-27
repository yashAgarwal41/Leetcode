class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        int low=0, high = n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(target==v[mid])  return mid;
            if(v[mid]>=v[0])
            {
                if(target>=v[0] and target<=v[mid])
                    high = mid-1;
                else low=mid+1;
            }
            else 
            {
                if(v[mid]<=v[n-1])
                {
                    if(target>v[mid] and target<=v[n-1])
                        low=mid+1;
                    else high=mid-1;
                }
                else 
                {
                    if(target>v[mid])   high=mid-1;
                    else low=mid+1;
                }
                    
            }
        }
        return -1;
    }
};