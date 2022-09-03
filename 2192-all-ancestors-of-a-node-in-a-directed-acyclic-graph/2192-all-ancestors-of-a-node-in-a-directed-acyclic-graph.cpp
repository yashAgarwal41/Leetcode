class Solution {
public:
    //BFS, TopoSort
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)  
        {
            if(indegree[i]==0)  q.push(i);
        }
        
        
        vector<vector<int>> ans(n, vector<int> (n, 0));
        // ans[i][j] = 1, if 'j' can reach 'i'..
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &j : graph[node])
            {
                indegree[j]--;
                if(indegree[j] == 0)    q.push(j);
                
                ans[j][node] = 1;   //'j' is reachable by 'node'
                //insert all the incoming nodes of 'node' in ans[j]..
                for(int x=0; x<n; x++)
                {
                    if(ans[node][x] == 1)   
                        ans[j][x] = 1;
                }
                
            }
        }
        
        vector<vector<int>> res(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ans[i][j]==1)    res[i].push_back(j);
            }
        }
        
        return res;
    }
};