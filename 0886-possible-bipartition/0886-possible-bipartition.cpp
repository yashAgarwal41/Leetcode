class Solution {
public:
    bool dfs(int i, int col, vector<int> &color, vector<vector<int>> &graph)
    {
        color[i] = col;
        for(auto &j : graph[i])
        {
            if(color[j] == -1)
            {
                bool chk = dfs(j, 1^color[i], color, graph);
                if(!chk)    return false;
            }
            else if(color[j] == color[i])    
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       vector<vector<int>> graph(n+1);
        for(auto &it : dislikes)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++)
        {
            if(color[i] == -1)
            {
                bool chk = dfs(i, 0, color, graph);
                if(!chk)    return false;
            }
        }
        return true;
    }
};