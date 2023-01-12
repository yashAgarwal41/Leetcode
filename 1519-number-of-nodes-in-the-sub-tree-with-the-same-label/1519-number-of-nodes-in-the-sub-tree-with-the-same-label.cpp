class Solution {
public:
    //dfs
    vector<int> res;
    vector<int> dfs(int i, string &labels, vector<int> &vis, vector<vector<int>> &graph)
    {
        vis[i] = 1;
        vector<int> freq(26, 0);
        freq[labels[i] - 'a'] = 1;
        for(auto &j:graph[i])
        {
            if(!vis[j])
            {
                vector<int> temp = dfs(j, labels, vis, graph);
                for(int k = 0; k<26; k++)
                    freq[k] += temp[k];
            }
        }
        res[i] += freq[labels[i] - 'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for(auto &v:edges)
        {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> vis(n, 0);
        res.resize(n, 0);
        dfs(0, labels, vis, graph);
        return res;
    }
};