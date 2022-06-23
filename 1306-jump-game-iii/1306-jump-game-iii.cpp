class Solution {
public:
//DFS..
//start from index=start, and mark the visited cells. After dfs completes, check if element with value 0 is visited or not.. 
    void dfs(int i, vector<int> &vis, vector<set<int>> &adj, vector<int> &v)
    {
        if(vis[i]==1)   return;
        vis[i]=1;
        for(auto &j: adj[i])
        {
            if(!vis[j])
            {
                dfs(j, vis, adj, v);
            }
        }
    }
    bool canReach(vector<int>& v, int start) {
        int n = v.size();
        vector<int> vis(n, 0);
        vector<set<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            int l = i-v[i];
            int r = i+v[i];
            if(l>=0) adj[i].insert(l);
            if(r<n) adj[i].insert(r);
        }

        dfs(start, vis, adj, v);
        for(int i=0; i<n; i++)
        {
            if(v[i]==0 and vis[i]==1)   return true; 
        }
        return false;
    }
};