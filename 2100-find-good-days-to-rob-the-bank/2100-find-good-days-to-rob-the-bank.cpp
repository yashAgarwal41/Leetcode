class Solution {
public:
    //Increasing-Decreaing prefix..TC-O(n)
    vector<int> prefix(vector<int> &v, bool order)
    {
        vector<int> ps(v.size());
        ps[0] = 1;
        for(int i=1; i<v.size(); i++)
        {
            if(order == 0 and (v[i] <= v[i-1])) ps[i] += ps[i-1] + 1;   //decreasing prefix
            else if(order == 1 and (v[i] >= v[i-1])) ps[i] += ps[i-1] + 1;  //increasing prefix
            else ps[i] = 1;
        }
        return ps;
    }
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> dec = prefix(security, 0);
        vector<int> inc = prefix(security, 1);
        vector<int> res;
        for(int i = time; i<n-time; i++)
        {
            if(dec[i] >= time+1 and inc[i+time] >= time+1)
                res.push_back(i);
        }
        return res;
    }
};