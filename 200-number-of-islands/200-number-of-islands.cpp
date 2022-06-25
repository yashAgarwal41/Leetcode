class Solution {
public:
    //TC-O(n*m), SC-O(1)..Mark visited land as '2' in grid itself..
    int n, m;
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or grid[i][j]=='0' or grid[i][j]=='2')  return;
        grid[i][j]='2';
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1') //if land is not visited..
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};