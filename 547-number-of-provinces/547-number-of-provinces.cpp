class Solution {
public:
    //DFS..TC-(n*n)
    void dfs(int i, vector<int> &vis, vector<set<int>> &graph)
    {
        vis[i]=1;
        for(auto &j:graph[i])
        {
            if(vis[j]==0)
            {
                dfs(j, vis, graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<set<int>> graph(n+1);
        vector<int> vis(n+1);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j]==1)
                {
                    graph[i+1].insert(j+1);
                    graph[j+1].insert(i+1);
                }
            }
        }
        
        int cnt = 0;    //number of components in the graph..
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i, vis, graph);
            }
        }
        return cnt;
    }
};