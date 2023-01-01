class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        vector<string> v;
        string x="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                v.push_back(x);
                x="";
            }
            else x+=s[i];
        }
        v.push_back(x);

        int m=v.size();
        if(n!=m)    return 0;
        map<char, string> map1;
        map<string, char> map2;
        for(int i=0; i<n; i++)
        {
            if(map1.find(pattern[i]) == map1.end() && map2.find(v[i]) == map2.end())
            {
                map1[pattern[i]] = v[i];
                map2[v[i]] = pattern[i];
            }
            
            else 
            {
                if(map2[v[i]] != pattern[i])   return false;
            }
        }
        return true;
    }
};