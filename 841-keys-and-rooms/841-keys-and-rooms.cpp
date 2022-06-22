class Solution {
public:
    //DFS...
    void dfs(int i, vector<int> &vis, vector<vector<int>> &rooms)
    {
        vis[i]=1;
        for(int j=0; j<rooms[i].size(); j++)
        {
            if(!vis[rooms[i][j]])
            {
                dfs(rooms[i][j], vis, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, vis, rooms);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)   return false;
        }
        return true;
    }
};