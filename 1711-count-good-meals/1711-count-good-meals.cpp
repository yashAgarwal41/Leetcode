#define ll long long
class Solution {
public:
    //TC-O(n*21)
    int mod = 1e9+7;
    int checkAllPowers(int a, unordered_map<int, int> &map)
    {
        ll ans=0, j;
        if(a == 0)  j = 0;
        else j = ceil(log2(2*a));    //check for b>=a
        while(j<22)
        {
            int powerOf2 = 1<<j;
            ll b = powerOf2 - a;
            if(b==a)
            {
                ans = (ans + 1LL*map[a]*(map[a]-1)/2)%mod;
            }
            else if(map.count(b))
            {
                ans = (ans + map[a]*map[b]*1LL)%mod;
            }
            j++;
        }
        return ans;
    }
    int countPairs(vector<int>& v) {
        int n = v.size();
        unordered_map<int, int> map;
        for(auto i:v)   map[i]++;
        
        //count pairs for a+b = 2^j..
        ll ans = 0;
        for(auto it : map)
        {
            int a = it.first;
            ans = (ans + checkAllPowers(a, map))%mod;
        }
        
        return ans;
    }
};