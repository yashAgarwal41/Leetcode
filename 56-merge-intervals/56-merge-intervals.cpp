class Solution {
public:
    //Sorting-O(n)...
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n=v.size();
        if(n==1)    return v;
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        res.push_back(v[0]);
        int j=0, l=v[0][0], r=v[0][1];
        
        for(int i=1; i<n; i++)
        {
            int x = v[i][0], y = v[i][1];
            if(r>=x)
            {
                res[j][0] = l;
                res[j][1] = max(r, y);
                r=max(r, y);
            }
            else 
            {
                j++;
                res.push_back(v[i]);
                l=v[i][0], r=v[i][1];
            }
        }
        
        return res;
    }
};