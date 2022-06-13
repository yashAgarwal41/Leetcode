class Solution {
public:
    int dp[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> curr(triangle.size()), prev = triangle[0];
        
        for(int i=1; i<triangle.size(); i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(j==0)    curr[j] = prev[j] + triangle[i][j]; 
                else if(j==i) curr[j] = prev[j-1] + triangle[i][j];
                else curr[j] = min(prev[j], prev[j-1]) + triangle[i][j];
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};