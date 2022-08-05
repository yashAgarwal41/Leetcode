class Solution {
public:
    //BinarySerach..TC-O(log(n*m))..SC-O(1)..
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low=0, high = m*n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int r=mid/m, c=mid%m;
            if(matrix[r][c] == target)    return true;
            if(matrix[r][c] < target)
                low = mid+1;
            else high = mid-1;
        }
        return false;
        
    }
};