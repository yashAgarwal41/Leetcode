class Solution {
public:
    int n;
    unordered_map<string, vector<pair<string, double>>> graph;
    
    bool dfs(string &p, string &q, unordered_map<string, int> &vis, double &ans)
    {
        for(auto &v:graph[p])
        {
            string s = v.first;
            double val = v.second;
            if(vis.find(s) == vis.end())
            {
                vis[s] = 1;
                ans*=val;
                
                if(s == q)  
                {
                    // ans *= val;
                    return true;
                }
                else 
                {
                    if(dfs(s, q, vis, ans))
                        return true;
                    else ans /= val;
                }
            }
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& que) {
        n = eq.size();
        
        for(int i=0; i<n; i++)
        {
            graph[eq[i][0]].push_back({eq[i][1], values[i]});
            graph[eq[i][1]].push_back({eq[i][0], 1.0/values[i]});
        }
        
//         for(auto it:graph)
//         {
//             cout<<it.first<<"->";
//             for(auto j:it.second)
//             {
//                 cout<<"("<<j.first<<","<<j.second<<"), ";
//             }
//             cout<<endl;
//         }
        
        vector<double> res;
        for(int i=0; i<que.size(); i++)
        {
            double ans = 1;
            if(que[i][0] == que[i][1] and graph.find(que[i][0])!=graph.end())
            {
                res.push_back(ans);
                continue;
            }
            unordered_map<string, int> vis;
            vis[que[i][0]] = 1;
            bool chk = dfs(que[i][0], que[i][1], vis, ans);
            if(chk) res.push_back(ans);
            else res.push_back((double)-1);
        }
        return res;
    }
};