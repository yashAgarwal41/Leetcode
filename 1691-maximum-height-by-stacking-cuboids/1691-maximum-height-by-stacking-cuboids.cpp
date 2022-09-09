class Solution {
public:
    //memoization, TC-O(n*n)..
    int n;
    int dp[101][102];
    int help(int i, int prev, vector<vector<int>> &v)
    {
        if(i==n)    return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int pick=0, notPick=0;
        //pick..
        if(prev==101 or (v[prev][0] <= v[i][0] and v[prev][1]<=v[i][1] and v[prev][2]<=v[i][2]))
            pick = v[i][2] + help(i+1, i, v);
        
        //not pick..
        notPick = help(i+1, prev, v);
        
        return dp[i][prev] = max(pick, notPick);
    }
    int maxHeight(vector<vector<int>>& v) {
        n = v.size();
        //we can rotate the cuboid..
        //so first sort each cuboid(so that height will be maximum)
        for(auto &v1 : v)   sort(v1.begin(), v1.end());
        //now sort the complete vectors -> cub1 <= cub2 <= cub3 <= ...cubn...
        sort(v.begin(), v.end());
        
        memset(dp, -1, sizeof dp);
        return help(0, 101, v);
    }
};