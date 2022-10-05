class Solution {
public:
    //Dp Memoization, TC-O(max(n, m)*2)
    int n, m, mod = 1e9+7;
    long long dp[100001][3];
    unordered_map<int, int> map1, map2;
    int maxi = 0;
    long long help(int i, int path, vector<int> &v1, vector<int> &v2)
    {
        // if(i>=n and i>=m)    return 0;
        if(path == 1 and i>=n)   return 0;
        if(path == 2 and i>=m)  return 0;
        if(dp[i][path]!=-1) return dp[i][path];
        
        long long samePath = 0, differentPath = 0;
        
        //continue with current path/array..
        if(path == 1)   samePath = (v1[i] + help(i+1, path, v1, v2) + 0LL);
        if(path == 2)   samePath = (v2[i] + help(i+1, path, v1, v2) + 0LL);
        
        //change the path/array..
        if(path == 1)
        {
            int val = v1[i];
            if(map2.find(val) != map2.end())   
                differentPath = (val + help(map2[val]+1, 2, v1, v2) + 0LL);
        }
        else if(path == 2)
        {
            int val = v2[i];
            if(map1.find(val) != map1.end())
                differentPath = (val + help(map1[val]+1, 1, v1, v2) + 0LL);
        }
        
        return dp[i][path] = max(samePath, differentPath);
    }
    int maxSum(vector<int>& v1, vector<int>& v2) {
        n = v1.size(), m = v2.size();
        
        for(int i=0; i<n; i++)  map1[v1[i]] = i;
        for(int i=0; i<m; i++)  map2[v2[i]] = i;
        memset(dp, -1, sizeof dp);
        
        long long path1 = help(0, 1, v1, v2); //start from 1st array..
        memset(dp, -1, sizeof dp);
        long long path2 = help(0, 2, v1, v2); //start from 2nd array..
        long long ans =  max(path1, path2);
        return ans%mod;
    }
};