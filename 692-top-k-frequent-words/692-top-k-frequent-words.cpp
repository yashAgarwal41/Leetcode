class Solution {
public:
    static bool compare(pair<string, int> p1, pair<string, int> p2)
    {
        if(p1.second==p2.second)    return p1.first<p2.first;
        else return p1.second>p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<string> res;
        
        map<string, int> map;
        for(auto &str:words)    map[str]++;
        
        vector<pair<string, int>> vp;
        for(auto &it:map)   vp.push_back({it.first, it.second});
        sort(vp.begin(), vp.end(), compare);
        
        for(int i=0; i<k; i++)
            res.push_back(vp[i].first);
        
        return res;
    }
};