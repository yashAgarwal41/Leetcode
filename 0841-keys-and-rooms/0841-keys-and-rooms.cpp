class Solution {
public:
    //DFS..
    void dfs(int i, int n, vector<vector<int>> &rooms, vector<int> &vis)
    {
        vis[i] = 1;
        for(auto &j:rooms[i])
        {
            if(!vis[j]) dfs(j, n, rooms, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, n, rooms, vis);
        for(auto &i: vis)   
        {
            if(i==0)    return false;
        }
        return true;
    }
};