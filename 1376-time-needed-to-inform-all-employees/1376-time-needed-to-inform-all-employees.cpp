class Solution {
public:
    //DFS..
    int dfs(int i, int n, vector<int> &man, vector<int> &time, vector<set<int>> &graph, vector<int> &vis)
    {
        vis[i]=1;
        int ans = INT_MIN;
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                ans = max(ans, dfs(j, n, man, time, graph, vis));
            }
        }
        if(ans==INT_MIN)    return time[i];
        else return ans + time[i];
    }
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& time) {
        vector<int> vis(n, 0);
        vector<set<int>> graph(n);
        //graph: manager which inform -> e1, e3, e5...(e-employee)
        for(int i=0; i<n; i++)
        {
            if(i==headID)   continue;
            graph[man[i]].insert(i);
        }
        
        return dfs(headID, n, man, time, graph, vis);
    }
};