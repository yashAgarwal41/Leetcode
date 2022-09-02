using vi = vector<int>;
class Solution {
public:
    //1.Create Directed Graph
    //2.Check Cycle in both graph..IfCycle, return {};
    //3.Create TopoSort for row and col..
    //4.Generate The Matrix..
    
    bool detectCycle(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0), dfsVis(n, 0);
        
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                if(cycleDfs(i, vis, dfsVis, graph)) //if cycle found in any component..
                return true;
            }
            
        }
        return false;   //no cycle found in the entire graph..
    }
    
    vector<int> topologicalSort(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vi vis(n, 0), topo;
        stack<int> st;
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                topoDfs(i, vis, st, graph);
            }
        }
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
    
    bool cycleDfs(int i, vi &vis, vi &dfsVis, vector<vi> &graph)
    {
        vis[i] = 1;
        dfsVis[i] = 1;
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                if(cycleDfs(j, vis, dfsVis, graph))
                    return true;
            }
            else if(dfsVis[j] == 1)
                return true;
        }
        dfsVis[i] = 0;
        return false;
    }
    
    void topoDfs(int i, vi &vis, stack<int> &st, vector<vi> &graph)
    {
        vis[i] = 1;
        for(auto &j:graph[i])
        {
            if(!vis[j]) 
                topoDfs(j, vis, st, graph);
        }
        st.push(i);
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        int n = k+1;
        
        //1. Creating Graph..
        vector<vi> graph1(n);
        vector<vi> graph2(n);
        for(auto it:rc)
            graph1[it[0]].push_back(it[1]);
        for(auto it:cc)
            graph2[it[0]].push_back(it[1]);
        
        
        //2. Detecting Cycle..
        if(detectCycle(graph1) or detectCycle(graph2))  return vector<vector<int>> ();
        
        
        //3. Create TopoSorting for both row and col Graph..
        vector<int> topoRow = topologicalSort(graph1);
        vector<int> topoCol = topologicalSort(graph2);
        
        
        //4. now Creating the Matrix;
        vector<vector<int>> res(k, vector<int> (k, 0));
        unordered_map<int, int> rowMap;
        //first fill the rowWise ordering in 1st column..
        for(int i=0; i<k; i++)
        {
            res[i][0] = topoRow[i];
            rowMap[topoRow[i]] = i;
        }
        
        //then swap columnWise for columnOrdering..
        for(int i=0; i<topoCol.size(); i++)
        {
            int j = rowMap[topoCol[i]]; 
            swap(res[j][i], res[j][0]);
        }

        
        return res;
    }
};