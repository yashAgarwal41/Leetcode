class Solution {
public:
    //Using BFS..
    bool bfs(int i, vector<int> &color, vector<vector<int>> &graph)
    {
        color[i] = 0;   //starting with color 0..
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto j : graph[node])
            {
                if(color[j]==-1)
                {
                    color[j] = color[node]^1;   //giving the node adjacents the opposite color..
                    q.push(j);
                }
                else 
                {
                    if(color[j] == color[node])    //else if already visited, then check their colors..
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i, color, graph)) 
                    return false;
            }
        }
        return true;
    }
};