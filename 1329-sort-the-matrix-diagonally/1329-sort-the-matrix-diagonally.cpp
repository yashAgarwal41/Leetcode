class Solution {
public:
    //TC-O(m*n*log(min(n, m)))...
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                map[i-j].push(mat[i][j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mat[i][j] = map[i-j].top();
                map[i-j].pop();
            }
        }
        return mat;
    }
};