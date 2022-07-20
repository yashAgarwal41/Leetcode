class Solution {
public:
    //Memoization..TC-O(n*6*15)..
    int mod = 1e9+7;
    int dp[5001][8][16];
    int help(int i, int prev, int cnt, int &n, vector<int>& rollMax)
    {
        if(i==n)    return 1;   
        if(dp[i][prev][cnt] != -1)  return dp[i][prev][cnt];
        int ans = 0;
        
        for(int j=1; j<=6; j++)
        {
            if(j==prev)
            {
                if(rollMax[prev-1] > cnt)   //take same consectutive number..
                    ans = (ans%mod + help(i+1, j, cnt+1, n, rollMax)%mod)%mod;
            }
            else //take new number..
                ans = (ans%mod + help(i+1, j, 1, n, rollMax)%mod)%mod;
        }    
        
        return dp[i][prev][cnt] = ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof dp);
        return help(0, 7, 0, n, rollMax);
    }
};