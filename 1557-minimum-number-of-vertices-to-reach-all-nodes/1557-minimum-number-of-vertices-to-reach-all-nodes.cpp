class Solution {
public:
    //Nodes with '0' incoming nodes..TC-O(edges + n)
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(auto it:edges)
        {
            indegree[it[1]]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)  ans.push_back(i);
        }
        
        return ans;
    }
};