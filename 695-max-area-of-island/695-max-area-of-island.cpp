class Solution {
public:
    int n, m;
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or grid[i][j]==2)  
            return 0;
        
        grid[i][j] = 2;
        int ans = 0;
        ans += dfs(i-1, j, grid);
        ans += dfs(i+1, j, grid);
        ans += dfs(i, j-1, grid);
        ans += dfs(i, j+1, grid);
        
        return 1 + ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxi = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    maxi = max(maxi, dfs(i, j, grid));
                }   
            }
        }
        return maxi;
    }
};