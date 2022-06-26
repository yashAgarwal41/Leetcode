class Solution {
public:
    //DFS..
    int n, m, fix;
    void dfs(int i, int j, int &color, vector<vector<int>> &vis, vector<vector<int>> &image)
    {
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j]==1 or image[i][j]!=fix)
            return;
        
        vis[i][j] = 1;
        image[i][j] = color;
        dfs(i-1, j, color, vis, image);
        dfs(i+1, j, color, vis, image);
        dfs(i, j-1, color, vis, image);
        dfs(i, j+1, color, vis, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size(), fix = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(sr, sc, color, vis, image);
        return image;
    }
};