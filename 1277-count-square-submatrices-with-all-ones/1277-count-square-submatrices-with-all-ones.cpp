class Solution {
public:
    //Dp..TC-O(m*n)
    int countSquares(vector<vector<int>>& v) {
        int n = v.size(), m=v[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i>0 and j>0 and v[i][j]==1)
                {
                    v[i][j] = 1 + min({v[i-1][j-1], v[i-1][j], v[i][j-1]});
                }
                ans+=v[i][j];
            }
        }
        return ans;
    }
};