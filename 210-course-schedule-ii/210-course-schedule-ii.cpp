class Solution {
public:
    //BFS, topo sort, TC-(n+e)..
    //[u, v]-> to finsih 'u' we should perform 'v' first, that means v->u
    //so in topo sort.. 'v' comes before 'u'..
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(auto &it:prerequisites)
        {
            //v->u, 'v' shoould be perform before 'u'..
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)  
        {
            if(indegree[i]==0)  q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto &j:graph[node])
            {
                indegree[j]--;
                if(indegree[j]==0)  q.push(j);
            }
        }
        
        if(topo.size()==n)  return topo;
        else return {};
    }
};