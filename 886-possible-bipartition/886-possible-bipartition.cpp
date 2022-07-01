class Solution {
public:
    //BFS..TC-O(n+e)..
    //Graph Bipartite (Coloring Algo)..
    bool bfs(int i, vector<int> &color, vector<set<int>> &graph)
    {
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto &j:graph[node])
            {
                 if(color[j]==-1)
                 {
                     color[j] = 1^color[node];
                     q.push(j);
                 }
                 else if(color[j]==color[node])
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
                if(bfs(i, color, graph)==false)
                    return false;
            }
        }
        return true;
    }
};