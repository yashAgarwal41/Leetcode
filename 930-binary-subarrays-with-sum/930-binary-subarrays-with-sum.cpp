class Solution {
public:
    //hashmap...(Subarray sum eqauls 'k')
    int numSubarraysWithSum(vector<int>& v, int goal) {
        int n=v.size(), sum=0;  //sum is prefix sum
        int ans=0;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++)
        {
            sum += v[i];
            if(sum == goal) ans++;
            if(map.find(sum-goal)!=map.end())
            {
                ans += map[sum-goal];
            }
            map[sum]++;
        }
        return ans;
    }
};