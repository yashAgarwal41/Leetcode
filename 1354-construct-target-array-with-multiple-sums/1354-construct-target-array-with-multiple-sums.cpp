class Solution {
public:
    //Using priority Queue..
    //Moving from target array to starting array..
    //if we can form starting array, return true.
    bool isPossible(vector<int>& target) {
        int n = target.size();
        long long totSum=0;
        priority_queue<int> pq;
        for(auto &it: target)
        {
            totSum += it;
            pq.push(it);
        }
        if(totSum == n)    return true;
        
        while(pq.top()>1)
        {
            long long maxi = pq.top();
            pq.pop();
            long long remSum = totSum - maxi;
            if(maxi<=remSum or remSum <= 0)   return false;
            if(remSum==1)   return true;    //when there will be only 2 elements, and 1 element is '1'..
            
            long long val = maxi % remSum;
            pq.push(val);
            totSum = remSum + val;
        }
        return n == totSum;
    }
};