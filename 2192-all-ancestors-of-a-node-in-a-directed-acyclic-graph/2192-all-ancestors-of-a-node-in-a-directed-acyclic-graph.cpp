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
        
        vector<set<int>> ans(n);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &j : graph[node])
            {
                indegree[j]--;
                if(indegree[j] == 0)    q.push(j);
                
                //insert all the incoming nodes of 'node' in ans[j]..
                ans[j].insert(node);
                for(auto it:ans[node])
                {
                    ans[j].insert(it);
                }
            }
        }
        
        vector<vector<int>> res;
        for(auto it:ans)
        {
            vector<int> v;
            for(auto it2:it)    v.push_back(it2);
            res.push_back(v);
        }
        
        return res;
    }
};