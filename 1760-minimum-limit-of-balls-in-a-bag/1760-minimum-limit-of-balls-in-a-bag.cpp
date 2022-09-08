class Solution {
public:
    //Binary Seacrh, TC-O(nlogn)..
    bool isPossible(int maxOperations, int mid, vector<int> &v)
    {
        int cnt=0;  // no of opertions needed to make every bag balls to <= mid..
        for(auto i:v)
        {
            cnt += i/mid;
            if(i%mid==0)    cnt--;  
            //e.g, v[i]=7, mid=2, so we need 3 operations to make all bags to have <='2' balls (2,2,2,1)
            //e.g, v[i]=8, mid=2, so we need 3 operations to make all bags to have <='2' balls (2,2,2,2)
        }
        if(cnt<=maxOperations)  return true;
        else return false;
    }
    int minimumSize(vector<int>& v, int maxOperations) {
        int n = v.size();
        int low=1, high = 1e9, ans;
        while(low<=high)
        {
            int mid = low+(high-low)/2; //possible penalty..
            if(isPossible(maxOperations, mid, v))   //check if 
            {
                ans = mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        
        return ans;
    }
};