class Solution {
public:
    //DFS, Longest cycle will be answer, TC-O(n)..
    //Elements in the same set will form a cycle.
    //in e.g, [5,4,0,3,1,6,2], there are 3 cycle
    // [5,6,0,2], [4,1],[3]-> longest =>4
    int dfs(int i, vector<int> &vis, vector<int> &nums)
    {
        vis[i] = 1;
        if(vis[nums[i]] == 1)   
            return 1;
        return 1 + dfs(nums[i], vis, nums);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), maxi=0;
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                maxi = max(maxi, dfs(i, vis, nums));
            }
        }
        return maxi;
    }
};