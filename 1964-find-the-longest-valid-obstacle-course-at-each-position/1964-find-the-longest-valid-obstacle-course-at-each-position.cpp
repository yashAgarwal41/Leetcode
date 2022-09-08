class Solution {
public:
    //LIS(Binary Search), TC_O(nlogn)..
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        int n = v.size();
        vector<int> res, lis;
        for(int i=0; i<n; i++)
        {
            int ind = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            
            if(ind == lis.size())
            {
                res.push_back(lis.size()+1);
                lis.push_back(v[i]);
            }
            else
            {
                res.push_back(ind+1);
                lis[ind] = v[i];
            }
        }
        return res;
    }
};