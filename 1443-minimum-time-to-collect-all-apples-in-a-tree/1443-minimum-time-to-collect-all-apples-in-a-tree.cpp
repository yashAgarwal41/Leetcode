class Solution {
public:
    int cnt = 0;
    vector<int> subset;
    int help(int i, vector<int> &vis, vector<set<int>> &graph, vector<bool> &hasApple)
    {
        int cnt = hasApple[i];
        vis[i] = 1;
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                cnt += help(j, vis, graph, hasApple);
            }
        }
        return subset[i]=cnt;
    }
    void dfs(int i, vector<set<int>> &graph, vector<int> &vis)
    {
        vis[i] = 1;
        for(auto &j:graph[i])
        {
            if(!vis[j] and subset[j])
            {
                dfs(j, graph, vis);
                cnt++;
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<set<int>> graph(n);
        for(int i=0; i<n-1; i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> vis(n, 0);
        subset.resize(n,0);
        
        for(int i=0; i<n; i++)
        {
            
        }
        help(0,vis,graph,hasApple);
        //for(auto &i:subset) cout<<i<<" ";
        //cout<<endl;
        fill(vis.begin(),vis.end(),0);
        dfs(0, graph, vis);
        return cnt*2;
    }
};