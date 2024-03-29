class Solution {
public:
    //Memoization, TC-O(n)..
    int n;
    int dp[100001][2];
    int help(int i, bool swaped, vector<int> &v1, vector<int> &v2)
    {
        if(i==n)    return 0;
        if(dp[i][swaped]!=-1)   return dp[i][swaped];
        
        int ans = 1e6;
        if(i==0)
        {
            ans = min(help(i+1, 0, v1, v2), 1 + help(i+1, 1, v1, v2));
            return dp[i][swaped] = ans;
        }
        
        int prev1 = v1[i-1], prev2 = v2[i-1];
        int curr1 = v1[i], curr2 = v2[i];
        if(swaped == true)   swap(prev1, prev2);    //if previous indices are swaped..
        
        //if already increasing, then no need to swap current indices..
        if(prev1 < curr1 and prev2 < curr2)
        {
            ans = min(ans, help(i+1, 0, v1, v2));
        }
        //if also increasing on swapping current indices, then swap currents and check if it give minimum..
        if(prev1 < curr2 and prev2 < curr1)
        {
            ans = min(ans, 1 + help(i+1, 1, v1, v2));
        }
        
        return dp[i][swaped] = ans;
    }
    int minSwap(vector<int>& v1, vector<int>& v2) {
        n = v1.size();
        memset(dp, -1, sizeof dp);
        return help(0, 0, v1, v2);
    }
};