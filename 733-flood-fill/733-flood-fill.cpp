class Solution {
public:
    //DFS..
    int n, m, fix;
    void dfs(int i, int j, int &color, vector<vector<int>> &image)
    {
        if(i<0 or j<0 or i>=n or j>=m or image[i][j]!=fix)
            return;
        
        image[i][j] = color;
        dfs(i-1, j, color, image);
        dfs(i+1, j, color, image);
        dfs(i, j-1, color, image);
        dfs(i, j+1, color, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size(), fix = image[sr][sc];
        
        if(image[sr][sc]!=color)
            dfs(sr, sc, color, image);
        return image;
    }
};