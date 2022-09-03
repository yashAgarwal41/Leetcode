class Solution {
public:
    //DFS, TC-O(n^2)
    //call dfs from every node and store nodes which can reachable by startNode(source)..
    void dfs(int src, int i, vector<int> &vis, vector<vector<int>> &graph, vector<vector<int>> &ans)
    {
        vis[i] = 1;
        ans[i][src] = 1;
        for(auto &j:graph[i])
        {
            if(!vis[j])
                dfs(src, j, vis, graph, ans);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> ans(n, vector<int> (n, 0));
        // ans[i][j] = 1, if 'j' can reach 'i'..
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            ans[it[1]][it[0]] = 1;   //it1 is reachable by it0..
        }
        
        // start dfs from every node..
        for(int i=0; i<n; i++)
        {
            vector<int> vis(n, 0);
            dfs(i, i, vis, graph, ans);
        }
        
        vector<vector<int>> res(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)    continue;
                if(ans[i][j]==1)    res[i].push_back(j);
            }
        }
        
        return res;
    }
};