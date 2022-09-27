class Solution {
public:
    //LIS(Binary search) from front and end, TC-O(n*logn)
    void calculateLIS(int n, vector<int> &v, vector<int> &lisStore)
    {
        vector<int> lis;
        for(int i=0; i<n; i++)
        {
            auto lb = lower_bound(lis.begin(), lis.end(), v[i]);
            if(lb == lis.end()) lis.push_back(v[i]);
            else *lb = v[i];
            
            lisStore[i] = lis.size();
        }
    }
    int minimumMountainRemovals(vector<int>& v) {
        int n = v.size();
        vector<int> lisFromStart(n, 1);
        vector<int> lisFromEnd(n, 1);
        
        calculateLIS(n, v, lisFromStart);
        reverse(v.begin(), v.end());
        calculateLIS(n, v, lisFromEnd);
        reverse(lisFromEnd.begin(), lisFromEnd.end());
        
        int mini = INT_MAX;
        //check min when v[i] will be mountain peak..
        for(int i=1; i<n-1; i++)
        {
        //atleast 1 element should be at left and right both for v[i] to be peak
            if(lisFromStart[i]>1 and lisFromEnd[i]>1)   
            {
                int rm1 = i+1-lisFromStart[i];  //remove elements from start
                int rm2 = n-i-lisFromEnd[i];    //remove elements from end
                mini = min(mini, rm1+rm2);
            }
            
        }
        return mini;
    }
};
