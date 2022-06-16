class Solution {
public:
    //Using priority_queue(ascending order)..
    //Increement the min value always to have the maximum product(reason written in notes)..
    int maximumProduct(vector<int>& v, int k) {
        int n=v.size();
        long long prod = 1, mod = 1e9+7;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it:v)  pq.push(it);
        
        while(k--)
        {
            int mini = pq.top();
            pq.pop();
            pq.push(mini+1);
        }
        
        while(!pq.empty())
        {
            prod = (1LL*prod*pq.top())%mod ;
            pq.pop();
        }
        return prod;
    }
};