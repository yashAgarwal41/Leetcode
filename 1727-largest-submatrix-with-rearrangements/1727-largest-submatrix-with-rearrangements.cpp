class Solution {
public:
    //PrefixSum + Sorting..TC-O(n*m*log(m)), SC-O(1)...
    void calculatePrefixSum(vector<vector<int>> &v)
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
                v[i][j] = sum;  //storing prefixSum in given vector itself..
            }
        }
    }
    
    int largestSubmatrix(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        calculatePrefixSum(v);
        
        int maxi=0;
        for(int i=0; i<n; i++)
        {
            sort(v[i].begin(), v[i].end());   //sorting every row..
            for(int j=0; j<m; j++)
            {
                int area = v[i][j]*(m-j);
                maxi = max(maxi, area);
            }
        }
        return maxi;
    }
};