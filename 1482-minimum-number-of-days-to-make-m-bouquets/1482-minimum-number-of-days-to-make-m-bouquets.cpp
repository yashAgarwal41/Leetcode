class Solution {
public:
    //Binary Search..TC-O(nlogn)..
    int minDays(vector<int>& bday, int m, int k) {
        int n = bday.size();
        if(n < m*k) return -1;
        
        int low = 1, high = *max_element(bday.begin(), bday.end());
        int mini = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int cntK=0, cntB=0;
            for(int i=0; i<n; i++)
            {
                if(bday[i]>mid)
                {
                    cntK=0;
                }
                else
                {
                    cntK++;
                    if(cntK == k)
                    {
                        cntK=0;
                        cntB++;
                        if(cntB==m) break;
                    }
                }
            }
            
            if(cntB==m)
            {
                mini = min(mini, mid);
                high = mid-1;
            }
            else low=mid+1;
        }
        
        return mini;
    }
};