class Solution {
public:
    //SLiding Window, TC-O(n).
    //check for max(consecutive valley or mountains)..
    bool mountain_OR_valley(int k, vector<int> &v)
    {
        if((v[k]>v[k-1] and v[k]>v[k+1]) or (v[k]<v[k-1] and v[k]<v[k+1]))
            return true;
        else 
            return false;
    }
    int maxTurbulenceSize(vector<int>& v) {
        int n = v.size();
        if(n<2) return n;
        int maxi=1, i=0, j=0;
        
        while(i+1<n)
        {
            if(v[i] == v[i+1])
            {
                i++;
                continue;
            }
            j = i+1;
            while(j+1<n and mountain_OR_valley(j, v))
            {
                j++;
            }
            maxi = max(maxi, j-i+1);
            i = j;
        }
        return maxi;
    }
};