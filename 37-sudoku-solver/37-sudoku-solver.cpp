class Solution {
public:
    //TC-O(4^9)..
    bool canPlace(int i, int j, char c, vector<vector<char>> &board)
    {
        for(int x=0; x<9; x++)
        {
            //in row
            if(board[i][x] == c)    return false;
            //in column
            if(board[x][j] == c)    return false;
        }
        //sub-matrix..
        int row = 3*(i/3), col = 3*(j/3);
        for(int x = row; x<row+3; x++)
        {
            for(int y = col; y<col+3; y++)
            {
                if(board[x][y] == c)    return false;
            }
        }
        return true;
            
        
    }
    bool help(vector<vector<char>> &board)
    {
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')  continue;
                for(char c = '1'; c<='9'; c++)
                {
                    if(canPlace(i, j, c, board))
                    {
                        board[i][j] = c;
                        if(help(board) == true)    return true;
                        else board[i][j] = '.';
                    }
                }
                return false;   //no letter can put at that place;
            }
        }
        //means no empty cell remaining, so we get our answer..
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        help(board);
    }
};