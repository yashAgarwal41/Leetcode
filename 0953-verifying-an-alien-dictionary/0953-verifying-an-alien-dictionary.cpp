class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<int> pos(26);
        int p=0;
        for(auto c:order)   pos[c-'a'] = p++;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int x=0, y=0;
                while(x<words[i].size() and y<words[j].size())
                {
                    if(pos[words[i][x]-'a'] < pos[words[j][y]-'a'])
                        break;
                    else if(pos[words[i][x]-'a'] > pos[words[j][y]-'a'])
                        return false;
                    x++, y++;
                }
                if(x<words[i].size() and y == words[j].size())  
                    return false;
            }
        }
        return true;
    }
};