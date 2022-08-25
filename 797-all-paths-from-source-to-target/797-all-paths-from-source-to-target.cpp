class Solution {
public:
    //Dfs + Backtracking..TC-O(n*(2^n))
    int n;
    void dfs(int node, vector<int> &vis, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &res)
    {
        if(node == n-1) 
        {
            res.push_back(path);
            return;
        }
        
        vis[node] = 1;
        for(auto j:graph[node])
        {
            if(!vis[j])
            {
                path.push_back(j);
                dfs(j, vis, graph, path, res);
                path.pop_back();    //backtrack..
            }
        }
        vis[node] = 0;  //backtrack..
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> path;
        path.push_back(0);
        vector<int> vis(n, 0);
        vector<vector<int>> res;
        dfs(0, vis, graph, path, res);
        
        return res;
    }
};