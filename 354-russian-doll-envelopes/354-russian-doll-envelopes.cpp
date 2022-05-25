class Solution {
public:
    //using binary search TC-O(nlogn)..
    //Solve LIS leetcode 300 first before this..
    static bool compare(vector<int> &v1, vector<int> &v2)
    {
        if(v1[0] == v2[0])  return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(), v.end(), compare);  
//sort according to first value..If first value same, then sort according to second value in decreasing order..
// e.g. [[5,4],[6,4],[6,7],[2,3]]
// after sorting [[2,3],[5,4],[6,7],[6,4]]  
// now only take care of 1st value of every index..
// so now we can apply the LIS binary search approach on first value..
    

        vector<int> lis;
        lis.push_back(v[0][1]);
        
        for(int i=1; i<n; i++)
        {
            int val = v[i][1];
            int ind = lower_bound(lis.begin(), lis.end(), val) - lis.begin();
            if(ind>=lis.size()) lis.push_back(val); 
            else lis[ind] = val;
        }
        return lis.size();
    }
};