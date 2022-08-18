class Solution {
public:
    //Remove Integers with max Frequency, TC-O(nlogn), SC-O(n)
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        for(auto it:arr)    map[it]++;
        vector<int> freq;
        for(auto &it:map)
            freq.push_back(it.second);
        sort(freq.begin(), freq.end());
        
        int cnt=0, ans=0;
        for(int i=freq.size()-1; i>=0; i--)
        {
            ans++;
            cnt += freq[i];
            if(cnt>=n/2)    break;
        }
        return ans;
    }
};