typedef tuple<int, int, int> ti;
class Solution {
public:
    //BFS..
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), mini = INT_MAX;
        if(grid[0][0] == 1 or grid[n-1][n-1]==1)    return -1;
        if(n==1)    return 1; 
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        queue<ti> q;
        q.push({0, 0, 1});
        while(!q.empty())
        {
            auto [i, j, k] = q.front();
            q.pop();
            for(int di = -1; di<=1; di++)
            {
                for(int dj = -1; dj<=1; dj++)
                {
                    int r = i+di, c = j+dj;
                    if(r<0 or c<0 or r>n-1 or c>n-1 or vis[r][c] == 1 or grid[r][c] == 1)  continue;
                    q.push({r, c, k+1});
                    vis[r][c]=1;
                    if(r == n-1 and c == n-1)   mini = min(mini, k+1);
                }
            }
        }
        
        return mini == INT_MAX ? -1 : mini;
    }
};