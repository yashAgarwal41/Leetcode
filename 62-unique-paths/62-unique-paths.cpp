class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 or j==0)    curr[j] = 1;
                else curr[j] = curr[j-1] + prev[j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};