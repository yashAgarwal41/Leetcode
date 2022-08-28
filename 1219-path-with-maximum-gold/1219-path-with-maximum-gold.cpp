class Solution {
public:
    //TC-O(k*(4^k)), but here.. O(k*(3^k)).., where k->total no of gold cells
    //as except the starting node, the directions possible for other nodes will be 3..
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0 or vis[i][j]==1)
            return 0;
        
        vis[i][j] = 1;
        int l = dfs(i, j-1, grid, vis);
        int r = dfs(i, j+1, grid, vis);
        int u = dfs(i-1, j, grid, vis);
        int d = dfs(i+1, j, grid, vis);
        vis[i][j] = 0;  //backtrack..
        return grid[i][j] + max({l, r, u, d});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxi=0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0)   continue;
                maxi = max(maxi, dfs(i, j, grid, vis));
            }
        }
        return maxi;
    }
};