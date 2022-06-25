class Solution {
public:
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or vis[i][j]==1)  return;
        vis[i][j]=1;
        dfs(i-1, j, vis, grid);
        dfs(i+1, j, vis, grid);
        dfs(i, j-1, vis, grid);
        dfs(i, j+1, vis, grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='0') continue;
                else if(vis[i][j]==0)
                {
                    dfs(i, j, vis, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};