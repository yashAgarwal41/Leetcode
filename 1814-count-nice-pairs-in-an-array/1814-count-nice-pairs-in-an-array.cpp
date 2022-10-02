class Solution {
public:
    int mod = 1e9+7;
    int rev(int num)
    {
        int reverse = 0;
        while(num!=0 and num%10==0)    num/=10;
        while(num>0)
        {
            reverse = reverse*10 + num%10;
            num /= 10;
        }
        return reverse;
    }
    int countNicePairs(vector<int>& v) {
        int n = v.size(), ans = 0;
        unordered_map<int, int> map;
        
        for(int i=0; i<n; i++)
        {
            int x = v[i] - rev(v[i]);
            ans = (0LL + ans%mod + map[x]%mod)%mod;
            map[x]++;
        }
        return ans;
    }
};