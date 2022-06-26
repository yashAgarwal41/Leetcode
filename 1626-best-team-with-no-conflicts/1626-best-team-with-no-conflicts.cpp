class Solution {
public:
    //LIS..(sort the scores a/c to ages of people..Now do LIS on scores)..
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> vp;
        for(int i=0; i<n; i++)
        {
            vp.push_back({ages[i], scores[i]});
        }
        sort(vp.begin(), vp.end());
        for(int i=0; i<n; i++)
            scores[i] = vp[i].second;
        
        vector<pair<int, int>> lis;
        for(int i=0; i<n; i++)
        {
            lis.push_back({1, scores[i]});
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(scores[i]>=scores[j])
                {
                    lis[i].first = max(lis[i].first, lis[j].first+1);
                    lis[i].second = max(lis[i].second, lis[j].second+scores[i]);
                }
            }
        }
        int maxi=0;
        for(auto it:lis)
            maxi = max(maxi, it.second);
        return maxi;
    }
};