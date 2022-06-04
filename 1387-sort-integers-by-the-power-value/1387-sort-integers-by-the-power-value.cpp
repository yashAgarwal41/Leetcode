class Solution {
public:
    //Memoization + Map..TC-O(1000*1000)    //for recursion + for loop..
    int dp[1000001];
    int help(int i)
    {
        if(i<=1)    return 0;
        if(dp[i]!=-1)   return dp[i];
        if(i%2==0)  return dp[i] = help(i/2) + 1;
        else return dp[i] = help(i*3+1) + 1;
    }
    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof dp);
        
        multimap<int, int> mmap;
        
        for(int i=lo; i<=hi; i++)
        {
            mmap.insert({help(i), i});
        }
        auto it = mmap.begin();
        for(int i=1; i<k; i++)  it++;
        return it->second;
    }
};