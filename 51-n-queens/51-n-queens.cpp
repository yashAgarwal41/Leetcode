class Solution {
public:
    //BackTracking..
    bool isSafe(int r, int c, int n, vector<string> &ans)
    {
        //checking in row...
        for(int i=0; i<c; i++)
        {
            if(ans[r][i] == 'Q')    return false;
        }
        //upperleft diagonal...
        int i=r-1, j=c-1;
        while(i>=0 and j>=0)
        {
            if(ans[i--][j--]=='Q')  return false;
        }
        //lowerleft diagonal...
        i=r+1, j=c-1;
        while(i<n and j>=0)
        {
            if(ans[i++][j--]=='Q')  return false;
        }
        return true;
    }
    void help(int c, int n, vector<string> &ans, vector<vector<string>> &res)
    {
        if(c>=n)
        {
            res.push_back(ans);
            return ;
        }
        for(int r=0; r<n; r++)
        {
            if(isSafe(r, c, n, ans))
            {
                ans[r][c] = 'Q';
                help(c+1, n, ans, res);
                ans[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> ans(n, s);
        vector<vector<string>> res;
        help(0, n, ans, res);
        return res;
    }
};