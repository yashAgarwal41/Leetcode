class Solution {
public:
    //Detect a Cycle Alog Using DFS..
    //If graph is DAG, then true, else false;
    bool isCycleDfs(int i, vector<int> &vis, vector<int> &dfsVis, vector<set<int>> &graph)
    {
        vis[i]=1;
        dfsVis[i]=1;
        for(auto &j:graph[i])
        {
            if(vis[j]==0)
            {
                if(isCycleDfs(j, vis, dfsVis, graph))  
                    return true;
            }
            else if(dfsVis[j]==1)
                return true;
        }
        dfsVis[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<set<int>> graph(n);
        vector<int> vis(n, 0), dfsVis(n, 0);
        for(auto &v:prerequisites)
        {
            graph[v[0]].insert(v[1]);
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(isCycleDfs(i, vis, dfsVis, graph)==true)
                    return false;
            }
        }
        return true;
    }
};