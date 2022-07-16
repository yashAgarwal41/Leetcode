class Solution {
public:
    //Memoization..TC-O(n)..
    int dp[100001][4];
    int mod = 1e9+7, n;
    int help(int i, int seats, string &s)
    {
        if(i==n and seats==2) return 1;   //i.e, last partition also have 2 seats, return 1, else 0..
        if(i>=n)    return 0;
        if(seats>=3)  return 0;
        if(dp[i][seats]!=-1)  return dp[i][seats]%mod;
        
        int put = 0, notPut = 0;
        seats += s[i]=='S';
        if(seats==2)
        {
            put = help(i+1, 0, s)%mod;  //divide section
            notPut = help(i+1, seats, s)%mod; //not divide
        }
        else notPut = help(i+1, seats, s)%mod;    //cannot divide(seats should be 2)
        
        return dp[i][seats] = (0LL + put + notPut)%mod;
    }
    int numberOfWays(string s) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        return help(0, 0, s);
    }
};