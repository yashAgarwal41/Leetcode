class Solution {
public:
    void dfs(char parent, char node, unordered_map<char, set<char>> &equal, vector<int> &vis)
    {
        vis[node - 'a'] = 1;
        for(auto &j:equal[node])
        {
            if(!vis[j-'a'])
            {
                equal[parent].insert(j);
                dfs(parent, j, equal, vis);
            }
        }
    }
    bool equationsPossible(vector<string>& v) {
        unordered_map<char, set<char>> equal;
        for(auto &str:v)
        {
            if(str[1]=='=')
            {
                equal[str[0]].insert(str[3]);
                equal[str[3]].insert(str[0]);
                equal[str[0]].insert(str[0]);
                equal[str[3]].insert(str[3]);
            }
            else if(str[0] == str[3])   return false;
        }
        
        for(auto it:equal)
        {
            vector<int> vis(26, 0);
            dfs(it.first, it.first, equal, vis);
        }
        // for(auto it:equal)
        // {
        //     cout<<it.first<<"->";                 
        //     for(auto j:it.second)   cout<<j<<" ";
        //     cout<<endl;
        // }
        for(auto &str:v)
        {
            if(str[1]=='!')
            {
                if(equal[str[0]].count(str[3])) return false;
            }
        }
        
        return true;
    }
};