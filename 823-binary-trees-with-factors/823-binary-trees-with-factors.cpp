#define ll long long
class Solution {
public:
    //Dp + Sorting,TC-O(n*2)..
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());   //sort the array so to avoid non-factors
        unordered_map<int,ll> dp;   //to store dp..
        unordered_set<int> set(arr.begin(), arr.end()); //to quickly find factors are present or not..
        
        for(int i=0; i<n; i++)
        {
            ll cnt=1;
            for(int j=0; j<i; j++)
            {
                int a=arr[j], b=arr[i]/arr[j];
                if(arr[i]%a==0 and set.find(b)!=set.end())
                {
                    cnt = (cnt + dp[a]*dp[b]) % mod;
                }
            }
            dp[arr[i]] = cnt%mod;
        }
        
        ll ans=0;
        for(auto &it:dp)   ans = (ans + it.second) % mod;
        return ans;
    }
};