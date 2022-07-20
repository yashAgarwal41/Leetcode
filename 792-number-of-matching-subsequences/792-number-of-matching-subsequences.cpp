class Solution {
public:
    //Map-TC-O(5000*50*logn)
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), ans=0;
        unordered_map<char, set<int>> map;
        for(int i=0; i<n; i++)
            map[s[i]].insert(i);
        
        for(auto &str : words)
        {
            int j=-1;
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