class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        int n = v.size();
        vector<int> res, lis;
        for(int i=0; i<n; i++)
        {
            auto lb = lower_bound(lis.begin(), lis.end(), v[i]);
            
            if(lb == lis.end())
            {
                res.push_back(lis.size()+1);
                lis.push_back(v[i]);
            }
            else
            {
                if(*lb == v[i])
                {
                    auto ub = upper_bound(lis.begin(), lis.end(), v[i]);
                    res.push_back(ub-lis.begin()+1);
                    if(ub!=lis.end())   *ub = v[i];
                    else lis.push_back(v[i]);
                }
                else 
                {
                    res.push_back(lb-lis.begin()+1);
                    *lb = v[i];
                }
            }
            // for(auto j:lis) cout<<j<<" ";
            // cout<<endl;
        }
        return res;
    }
};