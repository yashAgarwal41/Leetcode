class Solution {
public:
    //Remove Integers with max Frequency, TC-O(nlogn), SC-O(n)
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> pq;
        unordered_map<int, int> map;
        for(auto it:arr)    map[it]++;
        for(auto it:map)    pq.push(it.second);
        
        int ans=0, cnt=0;
        while(!pq.empty())
        {
            cnt += pq.top();
            ans++;
            if(cnt>=n/2)    break;
            pq.pop();
        }
        return ans;
    }
};