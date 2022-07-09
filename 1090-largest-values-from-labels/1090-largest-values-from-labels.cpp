class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> vp;
        for(int i=0; i<n; i++)
            vp.push_back({values[i], labels[i]});
        
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        
        unordered_map<int, int> map;
        int ans=0;
        for(auto &it : vp)
        {
            if(map.count(it.second))
            {
                if(map[it.second]<useLimit)
                {
                    ans += it.first;
                    map[it.second]++;
                    numWanted--;
                }
            }
            else 
            {
                ans += it.first;
                map[it.second]++;
                numWanted--;
            }
            if(numWanted==0)    break;
        }
        return ans;
    }
};