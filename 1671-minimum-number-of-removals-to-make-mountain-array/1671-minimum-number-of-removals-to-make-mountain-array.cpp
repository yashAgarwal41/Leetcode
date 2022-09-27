class Solution {
public:
    //LIS from front and end, TC-O(n*n)
    void calculateLIS(int n, vector<int> &v, vector<int> &lis)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(v[i]>v[j])
                    lis[i] = max(lis[i], lis[j]+1);
            }
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
