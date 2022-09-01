class Solution {
public:
    //BFS..start from node with value 0
    int dir[4] = {-1, 1, 0, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int xx = i + dir[k];
                int yy = j + dir[3-k];
                
                if(xx<0 or yy<0 or xx>=n or yy>=m)  continue;
                if(dist[xx][yy] > dist[i][j] + 1)
                {
                    dist[xx][yy] = dist[i][j] + 1;
                    q.push({xx, yy});
                }
            }
        }
        return dist;
    }
};