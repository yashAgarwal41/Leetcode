class Solution {
public:
    //Priority Queue..TC-O(10^5)
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans=0;
        while(pq.top()>0)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(y<=0)    break;
            
            pq.push(x-1);
            pq.push(y-1);
            ans++;
        }
        return ans;
    }
};