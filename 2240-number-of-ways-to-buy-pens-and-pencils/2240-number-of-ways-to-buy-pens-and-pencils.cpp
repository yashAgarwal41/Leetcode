class Solution {
public:
    #define ll long long
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int maxPen = total/cost1;
        ll ans=0;
        for(int i=0; i<=maxPen; i++)
        {
            ll rem = total - 1ll*i*cost1;
            ll pencil = rem/cost2;
            ans += pencil+1;
        }
        
        return ans;
    }
};