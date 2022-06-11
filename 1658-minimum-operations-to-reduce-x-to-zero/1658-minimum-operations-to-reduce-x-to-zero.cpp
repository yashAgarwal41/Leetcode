class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int n = v.size();
        //prefixSum and suffixSum..
        //If at any point, ps[i] + ss[j] = x, then update the minimum value...
        vector<int> ps(n+1, 0), ss(n+1, 0);
        for(int i=1; i<=n; i++)
            ps[i] = ps[i-1] + v[i-1];
        
        for(int i=n-1; i>=0; i--)
            ss[i] = ss[i+1] + v[i];
        reverse(ss.begin(), ss.end());
        
        int mini=INT_MAX;
        for(int i=0; i<=n; i++)
        {
            int sum2 = x - ps[i];
            if(sum2<0)  continue;
            
            int j = lower_bound(ss.begin(), ss.end(), sum2) - ss.begin();
            if(j <= n-i and ss[j] == sum2)
                mini = min(mini, i+j);
        }
        
        return mini == INT_MAX ? -1 : mini;
    }
};