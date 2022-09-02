class Solution {
public:
    //TC-O(n+e)..
    //Check for the cycle in DAG..
    //The algorithm used here is to detect the cyclic graph but the additional things is the nodes which are involved in the cycle are marked and are discarded while returning the answer
    using vi = vector<int>;
    bool dfs(int i, vi &vis, vi &dfsVis, vi &cycleNode, vector<vi> &graph)
    {
        vis[i] = 1;
        dfsVis[i] = 1;
        
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                bool isCycle = dfs(j, vis, dfsVis, cycleNode, graph);   
                if(isCycle)  //cycle found in the path..
                {
                    cycleNode[i] = 1;
                    return true;   
                }
            }
            else if(dfsVis[j] == 1) //cycle found here..
            {
                cycleNode[i] = 1;
                return true;
            }
        }
        
        dfsVis[i] = 0;  //path is finished..
        return false;   //no cylce found..
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), dfsVis(n, 0), cycleNode(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                dfs(i, vis, dfsVis, cycleNode, graph);
        }
        
        vi res;
        for(int i=0; i<n; i++)
        {
            if(cycleNode[i] == 0)   res.push_back(i);   //nodes which are not in the cycle..
        }
        return res;
    }
};