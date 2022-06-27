class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> map;
        for(auto &i:tasks)
        {
            map[i]++;
        }
        int ans = 0;
        for(auto &it:map)
        {
            int freq = it.second;
            if(freq<=1) return -1;
            ans += ceil(freq/3.0);
        }
        return ans;
    }
};