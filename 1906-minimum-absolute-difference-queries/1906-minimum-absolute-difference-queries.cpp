class Solution {
public:
    //TC-O(q*100*log(n))
    void markPresentValues(int l, int r, vector<int> &freq, unordered_map<int, set<int>> &map)
    {
        for(int j=1; j<=100; j++)
        {
            auto lb = map[j].lower_bound(l);
            if(lb == map[j].end())  continue;
            if(*lb <=r )    freq.push_back(j);
        }
    }
    vector<int> minDifference(vector<int>& v, vector<vector<int>>& que) {
        unordered_map<int , set<int>> map;
        for(int i=0; i<v.size(); i++)   map[v[i]].insert(i);
        
        vector<int> res;
        for(auto &q:que)
        {
            vector<int> freq;
            markPresentValues(q[0], q[1], freq, map);
            
            //check minimum absolute difference..
            int mini = 101;
            for(int j=1; j<freq.size(); j++)
            {
                mini = min(mini, freq[j] - freq[j-1]);
            }
            mini = mini==101 ? -1 : mini;   
            res.push_back(mini);
        }
        
        return res;
    }
};