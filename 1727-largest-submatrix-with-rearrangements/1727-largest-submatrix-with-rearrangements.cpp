class Solution {
public:
    //PrefixSum + Sorting..TC-O(n*m*log(m))..
    void calculatePrefixSum(vector<vector<int>> &v, vector<vector<int>> &ps)
    {
        int n = v.size(), m = v[0].size();
        //Calculate no of consecutive 1's in every column.. 
        for(int j=0; j<m; j++)
        {
            int sum=0;
            for(int i=n-1; i>=0; i--)
            {
                sum += v[i][j];
                if(v[i][j]==0)  sum=0;
                ps[i][j] = sum;
            }
        }
    }
    
    int largestSubmatrix(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> ps(n, vector<int>(m, 0));
        calculatePrefixSum(v, ps);
        
        int maxi=0;
        for(int i=0; i<n; i++)
        {
            sort(ps[i].begin(), ps[i].end());   //sorting every row..
            for(int j=0; j<m; j++)
            {
                int area = ps[i][j]*(m-j);
                maxi = max(maxi, area);
            }
        }
        return maxi;
    }
};