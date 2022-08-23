class Solution {
public:
    //Backtracking
    int n;
    bool ans = false;
    bool help(int i, int curr_sum, int target, int k, vector<int> &v, vector<int> &vis)
    {
        if(k==1)    return true;
        if(i>=n)    return false;
        if(curr_sum == target)
        {
            return help(0, 0, target, k-1, v, vis);
        }
        
        for(int j=i; j<n; j++)
        {
            if(vis[j] == 0 and curr_sum + v[j] <= target)
            {
                vis[j] = 1;
                if(help(j+1, curr_sum + v[j], target, k, v, vis))
                    return true;
                else vis[j] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& v, int k) {
        n = v.size();
        int total = accumulate(v.begin(), v.end(), 0);
        if(total%k) return false;
        
        sort(v.begin(), v.end());
        if(v[n-1] > total/k)    return false;
        
        vector<int> vis(n, 0);
        return help(0, 0, total/k, k, v, vis);
    }
};