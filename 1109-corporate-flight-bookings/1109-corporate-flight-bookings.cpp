class Solution {
public:
    //Range Query..TC-O(n)..
    vector<int> corpFlightBookings(vector<vector<int>>& v, int n) {
        vector<int> pre(n+2, 0);
        for(auto it:v)
        {
            pre[it[0]] += it[2];
            pre[it[1]+1] -= it[2];
        }
        vector<int> res(n, 0);
        res[0] = pre[1];
        
        for(int i=1; i<n; i++)
        {
            res[i] += res[i-1] + pre[i+1];
        }
        return res;
    }
};