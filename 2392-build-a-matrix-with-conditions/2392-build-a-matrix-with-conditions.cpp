using vi = vector<int>;
class Solution {
public:
    //1.Create Directed Graph
    //2.Check Cycle in both graph..IfCycle, return {};
    //3.Create TopoSort for row and col..
    //4.Generate The Matrix..
    
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
        vector<vi> ans;
        
        //Creating Graph..
        vector<vi> rowGraph(n);
        vector<vi> colGraph(n);
        
        for(auto it:rc)
        {
            rowGraph[it[0]].push_back(it[1]);
        }
        for(auto it:cc)
        {
            colGraph[it[0]].push_back(it[1]);
        }
        
        //Detecting Cycle..
        vector<int> vis(n, 0), dfsVis(n, 0);
        //In RowGraph..
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                if(cycleDfs(i, vis, dfsVis, rowGraph))  
                    return ans;
            }
        }
        //In colGraph..
        fill(vis.begin(), vis.end(), 0);
        fill(dfsVis.begin(), dfsVis.end(), 0);
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                if(cycleDfs(i, vis, dfsVis, colGraph))  
                    return ans;
            }
        }
        
        //Create TopoSorting for both row and col Graph..
        vector<int> topoRow, topoCol;
        stack<int> st;
        
        //row toposort
        fill(vis.begin(), vis.end(), 0);
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                topoDfs(i, vis, st, rowGraph);
            }
        }
        while(!st.empty())
        {
            topoRow.push_back(st.top());
            st.pop();
        }
        
        //column toposort
        fill(vis.begin(), vis.end(), 0);
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                topoDfs(i, vis, st, colGraph);
            }
        }
        while(!st.empty())
        {
            topoCol.push_back(st.top());
            st.pop();
        }
        
        //now Creating the Matrix;
        vector<vector<int>> res(k, vector<int> (k, 0));
        unordered_map<int, int> rowMap;
        for(int i=0; i<k; i++)
        {
            res[i][0] = topoRow[i];
            rowMap[topoRow[i]] = i;
        }
        for(int i=0; i<topoCol.size(); i++)
        {
            int j = rowMap[topoCol[i]]; 
            swap(res[j][i], res[j][0]);
        }

        
        return res;
    }
};