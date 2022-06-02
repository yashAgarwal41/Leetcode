class Solution {
public:
    //Tabulation..TC-O(n*amount)..
    
    //Recursion for reference...
//     int help(int i, int tar, vector<int> &v)
//     {
//         if(tar==0)  return 1;
//         if(i==0) return 0;
        
//         int take = 0;
//         if(tar >= v[i-1]) take = help(i, tar-v[i-1], v);
//         int notTake = help(i-1, tar, v);
        
//         return take + notTake;
//     }
    
    int change(int tar, vector<int>& v) {
        int n=v.size();
        // return help(n, tar, v);
        int dp[301][5001];
        
        //Recursion base cases..
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int j=0; j<=tar; j++)
            dp[0][j] = 0;
        
        //Recursion Body
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=tar; j++)
            {
                int take = 0;
                if(j >=v[i-1]) take = dp[i][j-v[i-1]];
                int notTake = dp[i-1][j];
                
                dp[i][j] = take + notTake;
            }
        }
        return dp[n][tar];
    }
};