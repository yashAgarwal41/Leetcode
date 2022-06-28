class Solution {
public:
    //DFS..TC-O(n*m), SC-stack spaceO(n*m)..
    int n, m;
    bool dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m)  return false;   //if island(0) is at boundary..
        if(grid[i][j]==1 or grid[i][j]==2)   return true;   //if surrounded by '1' or visited..
        
        grid[i][j]=2;   //marking as visited..
        
        /* IMPORTANT NOTE: 
        WHY we CANNOT USE `dfs(i-1,j,grid) && dfs(i+1,j,grid) && dfs(i,j-1,grid) && dfs(i,j+1,grid);`???
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 2s!!!
        */
        bool d1 = dfs(i-1, j, grid);
        bool d2 = dfs(i+1, j, grid);
        bool d3 = dfs(i, j-1, grid);
        bool d4 = dfs(i, j+1, grid);
        return d1 and d2 and d3 and d4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(i, j, grid))
                      ans++;
                }
            }
        }
        return ans;
    }
};