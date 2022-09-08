class Solution {
public:
    //PrefixSum, TC-O(n*m*min(n, m))..
    void calculatePrefix(vector<vector<int>> &ps, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + mat[i-1][j-1];
            }
        }
    }
    int squareSum(int i, int j, int n, int m, int threshold, vector<vector<int>> &ps)
    {
        int x=i, y=j, maxLength = 0;
        while(x<=n and y<=m)
        {
            int sum = ps[x][y] - ps[i-1][y] - ps[x][j-1] + ps[i-1][j-1];
            if(sum > threshold)  break;
            maxLength = max(maxLength, x-i+1);
            x++;    y++;
        }
        return maxLength;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size(), maxi = 0;
        vector<vector<int>> ps(n+1, vector<int> (m+1, 0));
        calculatePrefix(ps, mat);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                maxi = max(maxi, squareSum(i, j, n, m, threshold, ps));
            }
        }
        return maxi;
    }
};