class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        unordered_map<int, int> map;
        for(auto i:changed) map[i]++;
        sort(changed.begin(), changed.end());
        int cnt=0;
        vector<int> res;
        for(int i=n-1; i>=0; i--)
        {
            if(map[changed[i]] > 0)
            {
                if(changed[i]%2==1) res.push_back(changed[i]);
                else 
                {
                    if(map[changed[i]/2] > 0)
                    {
                        res.push_back(changed[i]/2);
                        map[changed[i]/2]--;
                        if(map[changed[i]/2]==0)    map.erase(changed[i]/2);
                    }
                    else res.push_back(changed[i]);
                }
            }
            map[changed[i]]--;
            if(map[changed[i]]==0)  map.erase(changed[i]);
        }
        if(res.size()>n/2)  return vector<int> {};
        else return res;
    }
};