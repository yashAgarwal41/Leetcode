class Solution {
public:
    int findPoisonedDuration(vector<int>& v, int d) {
        if(d==0)    return 0;
        int ans=0;
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i]+d<=v[i+1])  ans+=d;
            else ans+=v[i+1]-v[i];
        }
        return ans+d;
    }
};