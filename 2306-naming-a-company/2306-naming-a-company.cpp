class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> map;
        for(auto &str:ideas)
        {
            char pref = str[0];
            string suff = str.substr(1, str.size()-1);
            map[pref].insert(suff);
        }
        
        long long ans = 0;
        for(char i = 'a'; i<='z'; i++)
        {
            for(char j=i+1; j<='z'; j++)
            {
                int same = 0; 
                for(auto &str1:map[i])
                {
                    if(map[j].count(str1))
                        same++;
                }
                int a = map[i].size(), b = map[j].size();
                ans += (1LL*(a-same)*(b-same))*2LL;
            }
        }
        return ans;
    }
};