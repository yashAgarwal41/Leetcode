class Solution {
public:
    //Kahn's Algo..BFS, TC-O(n*n)
    //que[a, b] is true if 'b' is reachable by 'a'..
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //Create Graph and store indegree..
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for(auto &it:prerequisites)
        {
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)  
        {
            if(indegree[i] == 0)    q.push(i);
        }
        
        
        //ans[j] will store nodes which can reach 'j'..
        vector<vector<int>> ans(n, vector<int> (n, 0));
        //Apply Bfs..
        while(!q.empty())
        {
            int node = q.front();   q.pop();
            
            for(auto &j:graph[node])
            {
                indegree[j]--;
                if(indegree[j] == 0)    q.push(j);
                
                ans[j][node] = 1;    //'node' can reach 'j'..
                //if 'j' is reachable by 'node', then 'j' is also reachable by 'ans[node]'..
                for(int x=0; x<n; x++)
                {
                    if(ans[node][x] == 1)
                        ans[j][x] = 1;
                }
            }
        }
        
        //que[a, b], check if 'b' is reachable by 'a'..
        vector<bool> res;
        for(auto it:queries)
        {
            if(ans[it[1]][it[0]]) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};