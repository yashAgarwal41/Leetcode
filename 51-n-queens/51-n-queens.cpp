class Solution {
public:
    bool canPlace(int r, int c, vector<string> &board)
    {
        //upperLeft Diagonal..
        int i=r, j=c;
        while(i>=0 and j>=0)
        {
            if(board[i--][j--] == 'Q')  return false;
        }
        
        //leftRow..
        i=r, j=c;
        while(j>=0)
        {
            if(board[i][j--] == 'Q')  return false;
        }
        
        //lowerLeft Diagonal..
        i=r, j=c;
        while(i<board.size() and j>=0)
        {
            if(board[i++][j--] == 'Q')  return false;
        }
        
        return true;
    }
    void help(int j, int n, vector<string> &board, vector<vector<string>> &res)
    {
        if(j==n)
        {
            res.push_back(board);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            if(canPlace(i, j, board))
            {
                board[i][j] = 'Q';
                help(j+1, n, board, res);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string level(n, '.');
        vector<string> board(n, level);
        vector<vector<string>> res;
        
        help(0, n, board, res);
        
        return res;
    }
};