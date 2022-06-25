class Solution {
public:
    //TC-O(n+e), SC-O(n+e)..
    bool dfs(int i, vector<int> &color, vector<vector<int>> &graph)
    {
        if(color[i]==-1)    color[i]=0; //starting with color 0..
        for(auto &j:graph[i])
        {
            if(color[j] == -1)  //if not visited
            {
                color[j] = 1^color[i];  //coloring non-visited adjacents with oppposite color
                if(!dfs(j, color, graph))
                    return false;
            }
            else //if already visited(colored)..
            {
                if(color[i] == color[j])    //if have same color, return false..
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i, color, graph) == false)   
                    return false;
            }
        }
        return true;
    }
};