class Solution {
public:
    string getHint(string s, string g) {
        int n = s.size();
        unordered_map<char, int> map;
        int x=0, y=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]==g[i])  x++;
            else
            {
                map[s[i]]++;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(s[i]!=g[i])
            {
                if(map.count(g[i]))
                {
                    y++;
                    map[g[i]]--;
                    if(map[g[i]]==0)    map.erase(g[i]);
                }
            }
        }
        string res = to_string(x) + "A" + to_string(y) + "B";
        return res;
    }
};