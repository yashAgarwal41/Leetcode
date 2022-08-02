class Solution {
public:
    //Sliding Window..TC-O(2n)..
    //ExactlyK = atMost(k)  -  atMost(k-1);
    //          (1,2,3...k) -  (1,2,3...k-1) = k;
    int atMost(int k, vector<int> &v)
    {
        int n = v.size(), i=0, j=0, ans=0;
        unordered_map<int, int> map;
        while(i<n and j<n)
        {
            map[v[j]]++;
            while(map.size()>k and i<n)
            {
                map[v[i]]--;
                if(map[v[i]]==0)    map.erase(v[i]);
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int exactlyK = atMost(k, nums)-atMost(k-1, nums);
        return exactlyK;
    }
};