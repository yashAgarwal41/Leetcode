class Solution {
public:
    int n;
    void dfs(int i, vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> ans)
    {
        ans.push_back(i);
        if(i == n-1)
        {
            res.push_back(ans);
            return;
        }
        
        for(auto &j:graph[i])
        {
            dfs(j, graph, res, ans);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& gr) {
        n = gr.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
        {
            for(auto &j:gr[i])
            {
                graph[i].push_back(j);
            }
        }
        
        vector<int> ans;
        vector<vector<int>> res;
        dfs(0, graph, res, ans);
        return res;
    }
};