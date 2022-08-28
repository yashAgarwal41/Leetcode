class Solution {
public:
    //Tc-O(m*k*logk) + O(n*k*logk).. where k->max(n, m)..
    //Sc-O(k)..
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        //from 1st row..
        for(int j=m-1; j>=0; j--)
        {
            int r=0, c=j;
            priority_queue<int, vector<int>, greater<int>> pq;
            while(r<n and c<m)
            {
                pq.push(mat[r++][c++]);
            }
            r=0, c=j;
            while(r<n and c<m)
            {
                mat[r++][c++] = pq.top();
                pq.pop();
            }
        }
        
        //from 1st column.
        for(int i=1; i<n; i++)
        {
            int r=i, c=0;
            priority_queue<int, vector<int>, greater<int>> pq;
            while(r<n and c<m)
            {
                pq.push(mat[r++][c++]);
            }
            r=i, c=0;
            while(r<n and c<m)
            {
                mat[r++][c++] = pq.top();
                pq.pop();
            }
        }
        return mat;
    }
};