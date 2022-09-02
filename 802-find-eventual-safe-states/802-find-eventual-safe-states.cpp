class Solution {
public:
    unordered_set<int> cylceNode;
    bool dfs(int i, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &graph)
    {
        vis[i] = 1;
        dfsVis[i] = 1;
        
        for(auto j: graph[i])
        {
            if(!vis[j])
            {
                bool chk = dfs(j, vis, dfsVis, graph);
                if(chk)
                {
                    cylceNode.insert(i);
                    // cylceNode.insert(j);
                    return true;
                }
            }
            else if(dfsVis[j] == 1)
            {
                cylceNode.insert(i);
                // cylceNode.insert(j);
                return true;
            }
        }
        
        dfsVis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, 0), dfsVis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                bool chk = dfs(i, vis, dfsVis, graph);
                // if(chk)    cylceNode.insert(i);
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            if(cylceNode.count(i) == 0)    
                res.push_back(i);
        }
        return res;
    }
};