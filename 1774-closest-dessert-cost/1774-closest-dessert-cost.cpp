class Solution {
public:
    //BackTracking..TC-O(n*(3^m))..
    int ans=INT_MAX, minDiff = INT_MAX;
    void help(int j, int curr, vector<int> &top, int target)    //TC-O(3^m)
    {
        if(abs(curr-target)<minDiff)
        {
            minDiff = abs(curr-target);
            ans = curr;
        }
        if(abs(curr-target) == minDiff)
            ans = min(ans, curr);
        
        if(j<0) return;
        
        help(j-1, curr + top[j], top, target);   //if taken 1 topping of 'j' type
        help(j-1, curr + 2*top[j], top, target); //if taken 2 topping of 'j' type 
        help(j-1, curr, top, target);    //if not taken topping of 'j' type
    }
    
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        int n=base.size(), m=top.size();
        for(int i=0; i<n; i++)  //TC-O(n)..
        {
            help(m-1, base[i], top, target);
        }
        
        return ans;
    }
};