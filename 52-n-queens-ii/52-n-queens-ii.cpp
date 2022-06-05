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
    int help(int c, int n, vector<string> &ans)
    {
        if(c>=n)
        {
            return 1;
        }
        int cnt=0;
        for(int r=0; r<n; r++)
        {
            if(isSafe(r, c, n, ans))
            {
                ans[r][c] = 'Q';
                cnt += help(c+1, n, ans);
                ans[r][c] = '.';
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> ans(n, s);
        return help(0, n, ans);
    }
};