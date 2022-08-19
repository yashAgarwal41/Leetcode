class Solution {
public:
//DFS + Backtracking, TC-O(n*m * min(4^L, m*n))..
//min(4^L, m*n)-> if string length is 12 but the table is 2x2 then it will stop lookup after visiting 4 cells
// so the time complexity is N*M * min(4^L , N*M)
    int n, m, l;
    bool dfs(int i, int j, int k, string &word, vector<vector<char>>& board)
    {
        if(k==word.size())  return true;    
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[k])  return false;
        
        char c = board[i][j];
        board[i][j] = '*';  //mark as visited..
        bool found = false;
        found |= dfs(i-1, j, k+1, word, board);
        found |= dfs(i+1, j, k+1, word, board);
        found |= dfs(i, j-1, k+1, word, board);
        found |= dfs(i, j+1, k+1, word, board);
        board[i][j] = c;    //backtrack..
        
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), l = word.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == word[0])
                {
                    bool found = dfs(i, j, 0, word, board);
                    if(found)   return true;
                }
            }
        }
        return false;
    }
};