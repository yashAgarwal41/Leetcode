class NumMatrix {
public:
    //Using prefixSum..TC-O(n*m)
    vector<vector<int>> pS; //prefixSum array
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        
        //Calculating PrefixSum
        for(int i=0; i<n; i++)
        {
            vector<int> temp(m);
            for(int j=0; j<m; j++)
            {
                if(i==0 and j==0)   temp[j] = matrix[0][0];
                else if(i==0)   temp[j] = temp[j-1] + matrix[i][j];
                else if(j==0)   temp[j] = pS[i-1][j] + matrix[i][j];
                else temp[j] = pS[i-1][j] + temp[j-1] - pS[i-1][j-1] + matrix[i][j];
            }
            pS.push_back(temp);
        }
        for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<pS[i][j]<<" ";
        cout<<endl;
    }
    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = pS[row2][col2] - ((row1>0) ? pS[row1-1][col2] : 0) - ((col1>0) ? pS[row2][col1-1] : 0) + ((row1>0 and col1>0 ) ? pS[row1-1][col1-1] : 0);
        return ans;
    
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */