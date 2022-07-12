class Solution {
public:
    //BackTracking + visited..
    int n;
    bool dfs(int ind, int oneSide, int target, int cnt, vector<int> &vis, vector<int> &v)
    {
        if(cnt==1)  return true;    //all 4 subsets formed
        if(oneSide == target)   //if one subset formed, now check for next subset
        {
            return dfs(0, 0, target, cnt-1, vis, v);
        }
        
        for(int j=ind; j<n; j++)
        {
            if(vis[j]==0 and oneSide + v[j] <=target)
            {
                vis[j] = 1;
                bool pick = dfs(j+1, oneSide+v[j], target, cnt, vis, v);
                if(pick)    return true;
                vis[j] = 0; //backtrack
            }
        }
        return false;
    }

    bool makesquare(vector<int>& v) {
        n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum%4)   return false;
        
        int target = sum/4; //length of 1 side..
        vector<int> vis(n, 0);
        return dfs(0, 0, target, 4, vis, v);
    }
};