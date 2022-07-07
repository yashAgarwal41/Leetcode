class Solution {
public:
    //Using deque..TC-O(nlogn)..
    vector<int> advantageCount(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        deque<pair<int, int>> dq;
        for(int i=0; i<n; i++) dq.push_back({v2[i], i});
        sort(dq.begin(), dq.end());
        sort(v1.begin(), v1.end());
        
        vector<int> res(n);
        for(int i=0; i<n; i++)
        {
            if(v1[i]>dq.front().first)
            {
                res[dq.front().second] = v1[i];
                dq.pop_front(); //TC-O(1)..
            }
            else 
            {
                res[dq.back().second] = v1[i];
                dq.pop_back(); //TC-O(1)..
            }
        }
        return res;
    }
};