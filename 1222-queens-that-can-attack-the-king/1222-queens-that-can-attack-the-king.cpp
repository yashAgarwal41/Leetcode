class Solution {
public:
    void checkInRow(int x, int y, vector<vector<char>> &board, vector<vector<int>> &res){
        int i = x, j = y;
        while(j>=0){
            if(board[x][j] == 'Q'){
                res.push_back({x, j});
                break;
            }
            j--;
        }
        j = y;
        while(j<8){
            if(board[x][j] == 'Q'){
                res.push_back({x, j});
                break;
            }
            j++;
        }
    }
    void checkInCol(int x, int y, vector<vector<char>> &board, vector<vector<int>> &res){
        int i = x, j = y;
        while(i>=0){
            if(board[i][y] == 'Q'){
                res.push_back({i, y});
                break;
            }
            i--;
        }
        i = x;
        while(i<8){
            if(board[i][y] == 'Q'){
                res.push_back({i, y});
                break;
            }
            i++;
        }
    }
    void checkInMainDiagonal(int x, int y, vector<vector<char>> &board, vector<vector<int>> &res){
        int i = x, j = y;
        while(i>=0 and j>=0){
            if(board[i][j] == 'Q'){
                res.push_back({i, j});  
                break;
            }
            i--, j--;
        }
        i = x, j = y;
        while(i<8 and j<8){
            if(board[i][j] == 'Q'){
                res.push_back({i, j});  
                break;
            }
            i++, j++;
        }
    }
    void checkInAntiDiagonal(int x, int y, vector<vector<char>> &board, vector<vector<int>> &res){
        int i = x, j = y;
        while(i>=0 and j<8){
            if(board[i][j] == 'Q'){
                res.push_back({i, j});  
                break;
            }
            i--, j++;
        }
        i = x, j = y;
        while(i<8 and j>=0){
            if(board[i][j] == 'Q'){
                res.push_back({i, j});  
                break;
            }
            i++, j--;
        }
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = queens.size();
        vector<vector<char>> board(8, vector<char> (8, '.'));
        board[king[0]][king[1]] = 'K';
        for(auto q : queens)    board[q[0]][q[1]] = 'Q';
        
        vector<vector<int>> res;
        int x = king[0], y = king[1];
        checkInRow(x, y, board, res);
        checkInCol(x, y, board, res);
        checkInMainDiagonal(x, y, board, res);
        checkInAntiDiagonal(x, y, board, res);
        return res;
    }
};