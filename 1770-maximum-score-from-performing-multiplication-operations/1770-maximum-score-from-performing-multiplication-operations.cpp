class Solution {
public:
    //Memoization, TC-(m*m)..
    //iterate in both i->v and j->multipliers array.. 
    //where both 'i' and 'j' are from front of the array..
    //'i' at max will be equals to size of multipliers array..
    //set dp values to INT_MIN, not -1, because '-1' can be our answer..
    int n, m;
    int dp[1001][1001];
    int help(int i, int j, vector<int> &v, vector<int> &multipliers)
    {
        if(j >= m) return 0;
        if(dp[i][j] != INT_MIN)  return dp[i][j];
        
        int backIndex = n-(j-i)-1;  //if selecting from back of the array..
        
        int front = v[i]*multipliers[j] + help(i+1, j+1, v, multipliers);
        int back = v[backIndex]*multipliers[j] + help(i, j+1, v, multipliers);
        
        return dp[i][j] = max(front, back);
    }
    int maximumScore(vector<int>& v, vector<int>& multipliers) {
        n = v.size(), m = multipliers.size();
        // memset(dp, INT_MIN, sizeof dp);  //memset will not work for INT_MIN;
        for(int i=0; i<=1000; i++)
        {
            for(int j=0; j<=1000; j++)
                dp[i][j] = INT_MIN;
        }
        return help(0, 0, v, multipliers);
    }
};