class Solution {
public:
    //m->no of edges(cables), n->no of nodes(computers)..
    //to connect all computers in a network, [min no of cables = no of computers - 1]
    //so first find no of components in the network(i.e, no of disconnected graphs)..
    //then min no of cables extract will be needed to connect those disconnected networks..
    //ans = NumberOfComponents - 1;
    void dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        vis[i]=1;
        for(auto j:adj[i])
        {
            if(vis[j]==0)
            {
                dfs(j, adj, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1)   return -1;
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for(int i=0; i<m; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int NumberOfComponents = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                NumberOfComponents++;
                dfs(i, adj, vis);
            }
        }
        return NumberOfComponents-1;
    }
};