class Solution {
public:
    //TC-O(m*n), SC-O(1)..
    //Set the elements of 0th row and 0th column as 0 if '0' exist in any row or column..
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int row0=1, col0=1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j])    continue;
                if(i==0)    row0=0;
                if(j==0)    col0=0;
                else if(i!=0 and j!=0)  
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //Traverse in 1st row..
        for(int j=1; j<m; j++)
        {
            if(matrix[0][j]==0)
            {
                for(int i=0; i<n; i++)
                    matrix[i][j] = 0;
            }
        }
        //traverse in 1st column..
        for(int i=1; i<n; i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0; j<m; j++)
                    matrix[i][j] = 0;       
            }
        }
        if(row0==0)
        {
            for(int j=0; j<m; j++)  matrix[0][j] = 0;
        }
        if(col0==0)
        {
            for(int i=0; i<n; i++)  matrix[i][0] = 0;
        }
        // if(leftTop==0 or row0==0 or col0==0)  matrix[0][0] = 0;
    }
};