class Solution {
public:
    //BOUNDARY DFS..
    int n, m;
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='X' or board[i][j]=='#')  return;
        board[i][j] = '#';
        dfs(i-1, j, board);
        dfs(i+1, j, board);
        dfs(i, j-1, board);
        dfs(i, j+1, board);
    }
    void solve(vector<vector<char>>& board) {
        n=board.size(), m=board[0].size();
        //checking 1st and last row..
        for(int j=0; j<m; j++)
        {
            if(board[0][j]=='O')
                dfs(0, j, board);
            if(board[n-1][j]=='O')
                dfs(n-1, j, board);
        }
        //checking 1st and last column..
        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O')
                dfs(i, 0, board);
            if(board[i][m-1]=='O')
                dfs(i, m-1, board);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};