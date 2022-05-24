class Solution {
public:
    //Sorting-O(n)...
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n=v.size();
        if(n==1)    return v;
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        res.push_back(v[0]);
        int j=0;
        
        for(int i=1; i<n; i++)
        {
            int x = v[i][0], y = v[i][1];
            if(res[j][1] >= v[i][0])
            {
                res[j][1] = max(res[j][1], v[i][1]);
            }
            else 
            {
                j++;
                res.push_back(v[i]);
            }
        }
        
        return res;
    }
};