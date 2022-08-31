class Solution {
public:
    //TC-O(m*n)..
    //BFS, Start from boundaries, and check if other cells can be reached.
    //if cells can be reached, then mark them as 1..
    //at last check if both atl[i][j] and pac[i][j] are reachable..
    int n, m;
    int dir[4] = {-1, 1, 0, 0};
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j}); //push the starting node into queue..
        vis[i][j] = 1;
        while(!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int x = i + dir[k];
                int y = j + dir[3-k];
                if(x<0 or y<0 or x>=n or y>=m or vis[x][y] == 1) continue;
                if(grid[x][y] < grid[i][j]) continue;
                
                vis[x][y] = 1;
                q.push({x, y});
            }
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        //visited array -> if (i, j) is, reachable mark it as '1'
        vector<vector<int>> pac(n, vector<int>(m, 0));  
        vector<vector<int>> atl(n, vector<int>(m, 0));
        
        //Left and Right Boundary..
        for(int i=0; i<n; i++)
        {
            bfs(i, 0, pac, grid);
            bfs(i, m-1, atl, grid);
        }
        
        //Top and Bottom Boundary..
        for(int j=0; j<m; j++)
        {
            bfs(0, j, pac, grid);
            bfs(n-1, j, atl, grid);
        }
        
        vector<vector<int>> res;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(atl[i][j] and pac[i][j]) //if both are reachable from (i, j)..
                    res.push_back({i, j});
            }
        }
        return res;
    }
};