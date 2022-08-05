class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<set<int>> &graph)
    {
        vis[i]=1;
        for(auto &j:graph[i])
        {
            if(vis[j]==0)
            {
                dfs(j, vis, graph);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<set<int>> graph(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 and j==0)   continue;
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                    graph[i].insert(j);
            }
        }
        vector<int> vis(n, 0);
        int comp=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                comp++;
                dfs(i, vis, graph);
            }
        }
        return n-comp;
        
    }
};