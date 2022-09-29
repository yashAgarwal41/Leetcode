class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int n = v.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<n; i++)
        {
            pq.push({abs(x-v[i]), v[i]});
        }
        vector<int> res;
        for(int i=0; i<k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};