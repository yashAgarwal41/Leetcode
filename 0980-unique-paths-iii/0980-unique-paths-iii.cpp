class Solution {
public:
    //DFS + Backtracking, TC-O(m*n + 4*3^(X-2)) = TC-O(3^(m*n))..
    //here X -> empty cells(0)..
    //3 is there instead of 4 in TC, bcoz 1 direction is the one from which we came at (i,j)..
    
    int m, n, ans=0, empty=0;
    void dfs(int i, int j, vector<vector<int>> &grid, int cnt)
    {
        
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j] == -1)  return;
        if(grid[i][j] == 2)
        {
            //1 cnt is extra because of starting node..
            if(empty == cnt-1)
                ans++;
            return;
        }
        
        grid[i][j] = -1;    //visited
        
        //TC -> from these 1 direction will return false(bcoz we visited that before)..
        dfs(i-1, j, grid, cnt+1);
        dfs(i+1, j, grid, cnt+1);
        dfs(i, j-1, grid, cnt+1);
        dfs(i, j+1, grid, cnt+1);
        
        grid[i][j] = 0;    //backtrack
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int startI, startJ;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    startI = i, startJ = j;
                else if(grid[i][j] == 0)
                    empty++;
            } 
        }
        dfs(startI, startJ, grid, 0);
        return ans;
    }
};
/* Time Complexity:
 * X = Number of non-obstacle squares.
 * O(m*n) ==> To find the start, end, & number of non-obstacle squares.
 * O(4 * 3^(X-2)) ==> DFS Helper will explore all possible paths. At each square
 * (except start & end) we will explore at most 3 directions. At start we will
 * explore 4 directions and at end we will stop the further exploration of that
 * path. Here X is bounded by m*n.
 *
 * Total time complexity: O(m*n + 4 * 3^(X-2)) = O(3^(m*n))
 *
 * Space Complexity: O(X) --> For recursion stack. Here X is bounded by m*n.
 *
 */