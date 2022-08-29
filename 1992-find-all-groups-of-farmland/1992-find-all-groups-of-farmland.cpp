class Solution {
public:
    //DFS..TC-O(n*m)
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &land, vector<int> &v)
    {
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j]==1 or land[i][j]==0)
            return;
        
        vis[i][j]=1;
        if(i==n-1)
        {
            if(j==m-1 or land[i][j+1]==0)
            {
                v.push_back(i), v.push_back(j);
                return;
            }   
        }
        else if(j==m-1)
        {
            if(i==n-1 or land[i+1][j]==0)
            {
                v.push_back(i), v.push_back(j);
                return;
            }
        }
        else if(land[i+1][j]==0 and land[i][j+1]==0)
        {
            v.push_back(i), v.push_back(j);
            return;
        }
        
        dfs(i-1, j, vis, land, v);
        dfs(i+1, j, vis, land, v);
        dfs(i, j-1, vis, land, v);
        dfs(i, j+1, vis, land, v);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and land[i][j])
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    dfs(i, j, vis, land, v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};