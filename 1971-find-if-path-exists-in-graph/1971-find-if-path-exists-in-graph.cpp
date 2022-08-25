class Solution {
public:
    void dfs(int node, int target, vector<int> &vis, vector<vector<int>> &graph, bool &found)
    {
        if(node == target)
        {
            found = true;
            return;
        }    
            
        vis[node] = 1;
        for(auto &j:graph[node])
        {
            if(!vis[j])
            {
                dfs(j, target, vis, graph, found);
            }
        }
        // vis[node] = 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto &it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        bool found = false;
        vector<int> vis(n, 0);  
        dfs(source, destination, vis, graph, found);
        return found;
    }
};