class Solution {
public:
    vector<int> prefix(vector<int> &v, bool order)
    {
        vector<int> ps(v.size());
        ps[0] = 1;
        for(int i=1; i<v.size(); i++)
        {   
            if(order == 0 and (v[i] <= v[i-1]))  ps[i] += ps[i-1] + 1;   //for decreasing order..
            else if(order == 1 and (v[i] >= v[i-1]))  ps[i] += ps[i-1] + 1;    //for increasing order..
            else ps[i] = 1;
        }
        return ps;
    }
    vector<int> goodIndices(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dec = prefix(v, 0);
        vector<int> inc = prefix(v, 1);
        vector<int> res;
        for(int i=k; i<n-k; i++)
        {
            if(dec[i-1] >= k and inc[i+k]>=k)   res.push_back(i);
        }
        
        
        return res;
    }
};