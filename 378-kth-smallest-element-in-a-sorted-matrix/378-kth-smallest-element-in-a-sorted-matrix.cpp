class Solution {
public:
    //Binary Search..TC-O(2n*log(max))..
    int calcRank(int mid, vector<vector<int>>& matrix, int n)
    {
        int r=0, c=n-1, cnt=0;
        while(r<n and c>=0)
        {
            if(matrix[r][c] <= mid)
            {
                cnt += c+1;
                r++;
            }
            else c--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1], ans;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int rank = calcRank(mid, matrix, n);
            // if(rank == k)
            // {
            //     ans = mid;  break;
            // }
            if(rank < k)   low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};