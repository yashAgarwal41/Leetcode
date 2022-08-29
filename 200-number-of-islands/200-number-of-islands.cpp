class Solution {
public:
    //BFS..
    int arr[4] = {-1, 1, 0, 0};
    int n, m; 
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j}); //starting node..
        vis[i][j] = 1;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int l = x+arr[k], r = y+arr[3-k];
                if(l<0 or r<0 or l>=n or r>=m or vis[l][r]==1 or grid[l][r]=='0') continue;
                else
                {
                    vis[l][r] = 1;
                    q.push({l, r});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    ans++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return ans;
    }
};