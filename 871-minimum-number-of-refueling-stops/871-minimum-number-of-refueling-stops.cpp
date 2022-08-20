class Solution {
public:
    //not done..
    //	Priority Queue (Time - nlogn, space - O(n)) 
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {       
        int ans = 0;
        priority_queue<int> pq;
        
        for(auto s: stations) {
            
            while(startFuel < s[0] && pq.size()) {
                startFuel += pq.top();
                pq.pop();
                ans++;
            }      
            
            if(startFuel < s[0]) return -1;
            
            pq.push(s[1]);
        }
        
        while(startFuel < target && pq.size()) {
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        if(startFuel < target) return -1;
        
        return ans;
    }
};