class Solution {
public:
    //Priority_queue..
    //Refer https://www.youtube.com/watch?v=7MIXlgBfr_U&ab_channel=CodewithAlisha
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> res(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({v[n-1], n-1});
        res[n-1] = 0;
        
        for(int i=n-2; i>=0; i--)
        {
            while(!pq.empty() and v[i] >= pq.top().first)
            {
                pq.pop();
            }
            if(pq.empty())
            {
                res[i] = 0;
            }
            else 
            {
                res[i] = pq.top().second-i;
            }
            pq.push({v[i], i});
        }
        return res;
    }
};