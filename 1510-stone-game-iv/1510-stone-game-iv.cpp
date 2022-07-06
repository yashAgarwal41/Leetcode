class Solution {
public:
    //Memoization..TC-O(n)
    int dp[100001];
    bool help(int n)
    {
        if(n<=0) return 0;  // Alice can not pick any coins, so he lost..
        if(n==1)    return 1;   // Alice can pick one coin(as 1 is a square no.)..
        //if 'n' is perfect square, alice pick all coins..
        long long temp = sqrt(n);
        if(temp*temp==n)    return true;
        
        if(dp[n]!=-1)   return dp[n];
        
        for(int i=1; i<=sqrt(n); i++)
        {
            bool bob = help(n-i*i);
            if(bob==false)      //if in any case, bob loose.. alice will win 
                return dp[n] = true;
        }
        return dp[n] = false;  //if bob never losses, then
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof dp);
        return help(n);
    }
};