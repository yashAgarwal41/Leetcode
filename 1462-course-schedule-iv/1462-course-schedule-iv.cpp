class Solution {
public:
    //DFS, TC-O(n*n)
    //que[a, b] is true if 'b' is reachable by 'a'..
    void dfs(int src, int i, vector<int> &vis, vector<vector<int>> &graph, vector<vector<int>> &ans)
    {
        vis[i] = 1;
        ans[i][src] = 1;    //'src' can reach 'i'..
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                dfs(src, j, vis, graph, ans);
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<vector<int>> ans(n, vector<int> (n, 0));
        for(auto &it:prerequisites) 
        {
            graph[it[0]].push_back(it[1]);
            ans[it[1]][it[0]] = 1;
        }
        
        //ans[j][i] = 1 if 'j' can be reachable by 'i'..
        
        for(int i=0; i<n; i++)
        {
            vector<int> vis(n, 0);
            dfs(i, i, vis, graph, ans);
        }
        
        //que[a, b], check if 'b' is reachable by 'a'..
        vector<bool> res;
        for(auto it:queries)
        {
            if(ans[it[1]][it[0]]) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};