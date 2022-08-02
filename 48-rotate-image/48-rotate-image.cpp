class Solution {
public:
    //TC-O(n*n), SC-O(1)..
    //first transpose the matrix, then reverse the columns..
    void transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
                swap(matrix[i][j], matrix[j][i]); 
        }
    }
    void reverseColumns(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n/2; j++)
                swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseColumns(matrix);
    }
};