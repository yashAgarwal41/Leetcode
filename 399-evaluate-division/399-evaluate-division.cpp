class Solution {
public:
    //DFS + Backtracking..
    unordered_map<string, vector<pair<string, double>>> graph;
    
    bool dfs(string &p, string &q, unordered_map<string, int> &vis, double &ans)
    {
        vis[p] = 1;
        //check all children nodes..
        for(auto &v:graph[p])
        {
            string node = v.first;
            double val = v.second;
            if(vis.find(node) == vis.end())
            {
                ans *= val;
                
                if(node == q)  //if found..
                {
                    return true;
                }
                else 
                {
                    if(dfs(node, q, vis, ans))
                        return true;
                    else ans /= val;    //backtrack
                }
            }
        }
        return false;   //if they are not mapped in the same graph component..
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& que) 
    {
        int n = eq.size();
        
        for(int i=0; i<n; i++)
        {
            graph[eq[i][0]].push_back({eq[i][1], values[i]});
            graph[eq[i][1]].push_back({eq[i][0], 1.0/values[i]});
        }
        
        vector<double> res;
        for(int i=0; i<que.size(); i++)
        {
            if(graph.find(que[i][0]) == graph.end() or graph.find(que[i][1]) == graph.end())
            {
                res.push_back(-1);
                continue;
            }
            else if(que[i][0] == que[i][1])
            {
                res.push_back(1);
                continue;
            }
            else 
            {
                double ans = 1;
                unordered_map<string, int> vis;
                bool found = dfs(que[i][0], que[i][1], vis, ans);   //call dfs..
                if(found) res.push_back(ans);
                else res.push_back(-1);
            }
            
        }
        return res;
    }
};