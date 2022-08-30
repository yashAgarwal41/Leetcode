class Solution {
public:
    //priority_queue..TC-O(nlogn + klogn)..
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size(), sum=0;
        priority_queue<int> pq;
        for(auto &it:piles)
        {
            sum += it;
            pq.push(it);
        }
        
        while(k>0)
        {
            int x = pq.top();
            int y = ceil(x/2.0);
            sum -= (x-y);
            pq.pop();
            pq.push(y);
            k--;
        }
        return sum;
    }
};