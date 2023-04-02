class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& prof, vector<int>& work) {
        int n = diff.size();
        vector<pair<int, int>> vp;
        for(int i=0; i<n; i++)  vp.push_back({diff[i], prof[i]});
        sort(vp.begin(), vp.end());
        vector<int> maxi(n);
        maxi[0] = vp[0].second;
        for(int i=1; i<n; i++)
        {
            maxi[i] = max(maxi[i-1], vp[i].second);
        }
        
        int sum = 0;
        for(int i=0; i<work.size(); i++)
        {
            pair<int, int> p = {work[i], 1e9};
            int ub = upper_bound(vp.begin(), vp.end(), p) - vp.begin();
            if(ub == 0) continue;
            else sum += maxi[ub-1];
        }
        return sum;
    }
};
