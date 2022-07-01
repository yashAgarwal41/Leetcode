class Solution {
public:
    //DFS..TC-O(n+e)..
    //Graph Bipartite (Coloring Algo)..
    bool dfs(int i, vector<int> &color, vector<set<int>> &graph)
    {
        if(color[i]==-1)    color[i]=0;
        
        for(auto &j:graph[i])
        {
            if(color[j]==-1)
            {
                color[j] = 1^color[i];
                if(dfs(j, color, graph)==false)
                    return false;
            }
            else 
            {
                if(color[j]==color[i])
                    return false;
            }
        }
        return true;
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<set<int>> graph(n+1);
        vector<int> color(n+1, -1);
        for(auto &v:dislikes)
        {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }
        
        for(int i=1; i<n; i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i, color, graph)==false)
                    return false;
            }
        }
        return true;
    }
};