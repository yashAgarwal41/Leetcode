class Solution {
public:
    //DFS..TC-O(n*m)
    int n, m;
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid2[i][j]==0 or vis[i][j]==1)
            return true;
        if(grid1[i][j] == 0)
            return false;
        vis[i][j] = 1;
        bool found = dfs(i-1, j, grid1, grid2, vis);
        found &= dfs(i+1, j, grid1, grid2, vis);
        found &= dfs(i, j-1, grid1, grid2, vis);
        found &= dfs(i, j+1, grid1, grid2, vis);
        
        return found;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid2[i][j])
                {
                    if(dfs(i, j, grid1, grid2, vis))
                    ans++;
                }   
            }
        }
        
        return ans;
    }
};