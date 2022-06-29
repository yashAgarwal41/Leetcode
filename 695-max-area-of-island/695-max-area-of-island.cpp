class Solution {
public:
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &grid, int &count)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or grid[i][j]==2)  return;
        
        count++;
        grid[i][j] = 2;
        dfs(i-1, j, grid, count);
        dfs(i+1, j, grid, count);
        dfs(i, j-1, grid, count);
        dfs(i, j+1, grid, count);
        
        // return d1 + d2 + d3 + d4;
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
                    int count=0;
                    dfs(i, j, grid, count);
                    maxi = max(maxi, count);
                }   
            }
        }
        return maxi;
    }
};