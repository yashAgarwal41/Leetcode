class Solution {
public:
    //LIS(Binary Search), TC_O(nlogn)..
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        int n = v.size();
        vector<int> res, lis;
        for(int i=0; i<n; i++)
        {
            auto ub = upper_bound(lis.begin(), lis.end(), v[i]);
            
            if(ub == lis.end())
            {
                res.push_back(lis.size()+1);
                lis.push_back(v[i]);
            }
            else
            {
                res.push_back(ub-lis.begin()+1);
                *ub = v[i];
            }
        }
        return res;
    }
};