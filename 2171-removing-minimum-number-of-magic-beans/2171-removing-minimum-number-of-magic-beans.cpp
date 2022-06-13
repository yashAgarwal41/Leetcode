class Solution {
public:
    #define ll long long 
    //prefixSum and suffixSum..TC-O(n)...
    long long minimumRemoval(vector<int>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        if(n==1 or v[0]==v[n-1])    return 0;
        
        ll ps[n], ss[n];
        ps[0] = v[0], ss[n-1] = v[n-1];
        for(int i=1; i<n; i++)  ps[i] = ps[i-1] + v[i];
        for(int i=n-2; i>=0; i--)   ss[i] = ss[i+1] + v[i];
        
        ll mini = LONG_LONG_MAX;
        for(int i=0; i<n; i++)
        {
            ll oper;
            if(i==0) oper = ss[i+1] - 1LL*(n-i-1)*v[i];
            else if(i==n-1)   oper = ps[i-1];
            else oper = ps[i-1] + (ss[i+1] - 1LL*(n-i-1)*v[i]);
            
            mini = min(mini, oper);
        }
    
        return mini;
    }
};