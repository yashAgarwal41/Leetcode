class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1)    return 1;
        queue<int> q;
        for(int i=1; i<=n; i++) q.push(i);
        
        int start_ind = 0;
        while(q.size()>1)
        {
            int step = k;
            while(step>1)
            {
                int curr = q.front();   //the 1st friend of circle..
                q.pop();    //remove it and shift to last of circle..
                q.push(curr);   //shifted..
                step--;
            }
            q.pop();    //remove the kth step friend from game..
        }
        
        return q.front();
    }
};