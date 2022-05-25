class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int k) {
        int n=v.size();
        if(k==0)    return true;
        if(n==1)
        {
            if(v[0]==1) return false;
            if(k==1)    return true;
        }
        
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                if(v[i]+v[i+1] == 0)
                {
                    v[i]=1; k--;
                }
            }
            else if(i==n-1)
            {
                if(v[i]+v[i-1] == 0)
                {
                    v[i]=1; k--;
                }
            }
            else if(v[i-1]+v[i]+v[i+1]==0)  
            {
                v[i]=1; k--;
            }
            if(k==0)    return 1;
        }
        
        if(k>0) return 0;
        return 1;
        
    }
};