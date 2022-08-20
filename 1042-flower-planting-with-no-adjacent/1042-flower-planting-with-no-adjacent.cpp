class Solution {
public:
    //M-coloring Problem, TC-O(4*n)..
    bool isSafe(int node, int col, vector<int> &color, vector<set<int>> &graph)
    {
        for(auto &j:graph[node])
        {
            if(color[j] == col) return false;
        }
        return true;
    }
    bool dfs(int node, vector<int> &color, vector<set<int>> &graph)
    {
        if(node==graph.size())
            return true;
        
        for(int col = 1; col <= 4; col++)
        {
            if(isSafe(node, col, color, graph))
            {
                color[node] = col;
                if(dfs(node+1, color, graph))
                    return true;
                else color[node] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n, 0);
        vector<set<int>> graph(n);
        for(auto &it:paths)
        {
            graph[it[0]-1].insert(it[1]-1);
            graph[it[1]-1].insert(it[0]-1);
        }
        
        bool ans = dfs(0, color, graph);
        return color;
    }
};