class Solution {
public:
    //Boundary DFS..
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or grid[i][j]==-1)   return;
        
        grid[i][j] = -1;    //set the 1's to -1 which are chained to boundary 1's..
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        //checking 1st and last row..
        for(int j=0; j<m; j++)
        {
            if(grid[0][j]==1)
                dfs(0, j, grid);
            if(grid[n-1][j]==1)
                dfs(n-1, j, grid);
        }
        //checking 1st and last column..
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==1)
                dfs(i, 0, grid);
            if(grid[i][m-1]==1)
                dfs(i, m-1, grid);
        }
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                ans += grid[i][j]==1;
        }
        return ans;
    }
};