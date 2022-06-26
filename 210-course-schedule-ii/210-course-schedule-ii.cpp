class Solution {
public:
    //DFS..TC-O(n+e)
    //if detect cycle, return empty array
    //else return topological sort in reverse order..
    bool isCycleDfs(int i, vector<int> &vis, vector<int> &dfsVis, stack<int> &st, vector<set<int>> &graph)
    {
        vis[i]=1;
        dfsVis[i]=1;
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                if(isCycleDfs(j, vis, dfsVis, st, graph))   //if detect cycle
                    return true;
            }
            else if(dfsVis[j])  //if detect cycle
                return true;
        }
        st.push(i); //topological sort
        dfsVis[i]=0;
        return false;   //no cycle detected
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<set<int>> graph(n);
        vector<int> vis(n, 0), dfsVis(n, 0);
        vector<int> res;
        stack<int> st;
        for(auto &v:prerequisites)
        {
            graph[v[0]].insert(v[1]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(isCycleDfs(i, vis, dfsVis, st, graph))
                    return res;
            }
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};