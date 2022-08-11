class Solution {
public:
    //BFS..TC-O(n)..
    //cannot be solved using DFS(difficult to solve)..
    //as we have to move at each next level simultaneously, prefer BFS..
    int n, m, maxTime = 0;
    int dRow[4] = {-1, 0, 0, 1};
    int dCol[4] = {0, -1, 1, 0};
    
    void bfs(queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        while(!q.empty())
        {
            int r = q.front().first.first;  //current row
            int c = q.front().first.second; //current col
            int t = q.front().second;       //current time
            maxTime = max(maxTime, t);      //update ans
            q.pop();
            
            for(int x=0; x<4; x++)
            {
                int nRow = r + dRow[x], nCol = c + dCol[x]; //all 4 direction..
                if(nRow>=0 and nRow<n and nCol>=0 and nCol<m and grid[nRow][nCol]==1 and vis[nRow][nCol]==0)
                {
                    q.push({{nRow, nCol}, t+1});    //push the node with t+1..(1 minute to rotten the fresh orange)..
                    grid[nRow][nCol] = 2;   //make it rotten
                    vis[nRow][nCol] = 1;    //visited
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q; //q-> ((i, j), time)
        
        //first push all the rotten oranges with time 0 as starting nodes..
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;  //mark as visited..
                }
            }
        }
        
        bfs(q, grid, vis);  //call BFS..
        
        //if some fresh orange renains, return -1..
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return maxTime;
    }
};