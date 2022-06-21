class Solution {
public:
    //Using Priority_queue(Min heap)
    //first use all the ladders for initial jumps and push the jump in 'pq'.
    //After all ladders gets exhausted, then we have 2 options:
    // 1. If pq.top() > nextJump, then use bricks 
    // 2. else use ladder for this jump, and bricks for previous min jump(of 'pq') and update your 'pq'.
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = h.size();
        priority_queue<int, vector<int>, greater<int>> pq;  //min heap
        for(int i=0; i<n-1; i++)
        {
            if(h[i] >= h[i+1])    continue;
            
            int diff = h[i+1]-h[i];
            if(pq.size() < ladders)
                pq.push(diff);
            else
            {
                if(pq.size()==0)    //that means ladders given in ques are 0..
                {
                    if(diff>bricks) return i;
                    else bricks -= diff;
                }
                else if(diff<=pq.top())     //use bricks to jump on next building..
                {
                    if(diff>bricks) return i;
                    else bricks -= diff;
                }
                else    //replace bricks for previous jump and ladder to this jump (if possible).. 
                {
                    if(pq.top()>bricks) return i;
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(diff);
                }
            }
        }
        return n-1;
    }
};