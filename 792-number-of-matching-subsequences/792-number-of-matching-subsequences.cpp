class Solution {
public:
    //
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), ans=0;
        map<char, set<int>> map;
        for(int i=0; i<n; i++)
        {
            map[s[i]].insert(i);
        }
        // for(auto &it:map)
        // {
        //     cout<<it.first<<"-> ";
        //     for(auto it2:it.second) cout<<it2<<" ";
        //     cout<<endl;
        // }
        for(auto &str : words)
        {
            int m = str.size(), j=-1;
            bool found = true;
            for(int i=0; i<str.size(); i++)
            {
                if(!map.count(str[i]))
                {
                    found = false;  
                    break;
                }
                auto ub = map[str[i]].upper_bound(j);
                j = *ub;
                if(ub == map[str[i]].end())
                {
                    found = false;
                    break;
                }
            }
            if(found)   ans++;
        }
        return ans;
    }
};