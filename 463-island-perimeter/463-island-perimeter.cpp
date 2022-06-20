class Solution {
public:
    //DFS
    //mark every land as visited using '-1', so that it will not check for visited land again..
    int n, m;
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)  //Water location
            return 1;
        if(grid[i][j]==-1)  return 0; //Land - if already visited..
        
        grid[i][j]=-1;   //Land - mark as visited..
        
        return dfs(i, j-1, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i+1, j, grid);
            
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    ans = dfs(i, j, grid);
                    break;  //since there is only one island, so no need to move further..
                }
            }
        }
        return ans;
    }
};