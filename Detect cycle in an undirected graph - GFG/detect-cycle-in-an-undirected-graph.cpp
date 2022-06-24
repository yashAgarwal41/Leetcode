// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool dfsCycle(int i, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[i]=1;
        for(auto j:adj[i])
        {
            if(vis[j]==1)
            {
                if(j != parent) return true;
            }
            else 
                if(dfsCycle(j, i, vis, adj))    return true;
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                if(dfsCycle(i, -1, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends